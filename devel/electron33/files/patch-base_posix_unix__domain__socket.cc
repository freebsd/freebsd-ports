--- base/posix/unix_domain_socket.cc.orig	2024-06-18 21:43:17 UTC
+++ base/posix/unix_domain_socket.cc
@@ -56,7 +56,7 @@ bool UnixDomainSocket::EnableReceiveProcessId(int fd) 
 
 // static
 bool UnixDomainSocket::EnableReceiveProcessId(int fd) {
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   const int enable = 1;
   return setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &enable, sizeof(enable)) == 0;
 #else
@@ -82,7 +82,7 @@ bool UnixDomainSocket::SendMsg(int fd,
 
     struct cmsghdr* cmsg;
     msg.msg_control = control_buffer;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
     msg.msg_controllen = checked_cast<socklen_t>(control_len);
 #else
     msg.msg_controllen = control_len;
@@ -90,7 +90,7 @@ bool UnixDomainSocket::SendMsg(int fd,
     cmsg = CMSG_FIRSTHDR(&msg);
     cmsg->cmsg_level = SOL_SOCKET;
     cmsg->cmsg_type = SCM_RIGHTS;
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
     cmsg->cmsg_len = checked_cast<u_int>(CMSG_LEN(sizeof(int) * fds.size()));
 #else
     cmsg->cmsg_len = CMSG_LEN(sizeof(int) * fds.size());
@@ -154,7 +154,7 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
 
   const size_t kControlBufferSize =
       CMSG_SPACE(sizeof(int) * kMaxFileDescriptors)
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
       // macOS does not support ucred.
       // macOS supports xucred, but this structure is insufficient.
       + CMSG_SPACE(sizeof(struct ucred))
@@ -182,7 +182,7 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
         wire_fds = reinterpret_cast<int*>(CMSG_DATA(cmsg));
         wire_fds_len = payload_len / sizeof(int);
       }
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
       // macOS does not support SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
           cmsg->cmsg_type == SCM_CREDENTIALS) {
@@ -216,6 +216,9 @@ ssize_t UnixDomainSocket::RecvMsgWithFlags(int fd,
     socklen_t pid_size = sizeof(pid);
     if (getsockopt(fd, SOL_LOCAL, LOCAL_PEERPID, &pid, &pid_size) != 0)
       pid = -1;
+#elif BUILDFLAG(IS_BSD)
+    NOTIMPLEMENTED();
+    pid = -1;
 #else
     // |pid| will legitimately be -1 if we read EOF, so only DCHECK if we
     // actually received a message.  Unfortunately, Linux allows sending zero
