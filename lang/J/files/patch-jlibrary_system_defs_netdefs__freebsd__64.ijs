--- jlibrary/system/defs/netdefs_freebsd_64.ijs.orig	2018-02-22 19:12:35 UTC
+++ jlibrary/system/defs/netdefs_freebsd_64.ijs
@@ -0,0 +1,131 @@
+NB. do not edit -- created by sym2ijs
+
+cocurrent <'jdefs'
+
+FIONBIO=: -2147195266
+FIONREAD=: 1074030207
+FD_SETSIZE=: 1024
+
+sockaddr_sz=: 16
+sa_family_off=: 1
+sa_family_sz=: 1
+sa_data_off=: 2
+sa_data_sz=: 14
+
+sockaddr_in_sz=: 16
+sin_family_off=: 1
+sin_family_sz=: 1
+sin_port_off=: 2
+sin_port_sz=: 2
+sin_addr_off=: 4
+sin_addr_sz=: 4
+
+in_addr_sz=: 4
+s_addr_off=: 0
+s_addr_sz=: 4
+
+hostent_sz=: 32
+h_name_off=: 0
+h_name_sz=: 8
+h_aliases_off=: 8
+h_aliases_sz=: 8
+h_addrtype_off=: 16
+h_addrtype_sz=: 4
+h_length_off=: 20
+h_length_sz=: 4
+h_addr_list_off=: 24
+h_addr_list_sz=: 8
+
+
+SIOCATMARK=: 1074033415
+
+
+IPPROTO_IP=: 0
+IPPROTO_ICMP=: 1
+IPPROTO_IGMP=: 2
+IPPROTO_TCP=: 6
+IPPROTO_PUP=: 12
+IPPROTO_UDP=: 17
+IPPROTO_IDP=: 22
+IPPROTO_RAW=: 255
+IPPROTO_MAX=: 256
+
+
+INADDR_ANY=: 0
+INADDR_LOOPBACK=: 2130706433
+INADDR_BROADCAST=: 4294967295
+INADDR_NONE=: 4294967295
+
+INADDR_UNSPEC_GROUP=: -536870912
+INADDR_ALLHOSTS_GROUP=: -536870911
+INADDR_MAX_LOCAL_GROUP=: -536870657
+IN_LOOPBACKNET=: 127
+
+SOCK_STREAM=: 1
+SOCK_DGRAM=: 2
+SOCK_RAW=: 3
+SOCK_RDM=: 4
+SOCK_SEQPACKET=: 5
+
+SOL_SOCKET=: 65535
+SO_DEBUG=: 1
+SO_REUSEADDR=: 4
+SO_KEEPALIVE=: 8
+SO_DONTROUTE=: 16
+SO_BROADCAST=: 32
+SO_LINGER=: 128
+SO_OOBINLINE=: 256
+
+SO_SNDBUF=: 4097
+SO_RCVBUF=: 4098
+SO_SNDLOWAT=: 4099
+SO_RCVLOWAT=: 4100
+SO_SNDTIMEO=: 4101
+SO_RCVTIMEO=: 4102
+SO_ERROR=: 4103
+SO_TYPE=: 4104
+
+linger_sz=: 8
+l_onoff_off=: 0
+l_onoff_sz=: 4
+l_linger_off=: 4
+l_linger_sz=: 4
+
+AF_UNSPEC=: 0
+AF_UNIX=: 1
+AF_INET=: 2
+AF_SNA=: 11
+AF_DECnet=: 12
+AF_APPLETALK=: 16
+AF_IPX=: 23
+AF_MAX=: 42
+PF_UNSPEC=: 0
+PF_UNIX=: 1
+PF_INET=: 2
+PF_SNA=: 11
+PF_DECnet=: 12
+PF_APPLETALK=: 16
+PF_IPX=: 23
+PF_MAX=: 42
+
+SOMAXCONN=: 128
+MSG_OOB=: 1
+MSG_PEEK=: 2
+MSG_DONTROUTE=: 4
+
+msghdr_sz=: 48
+msg_name_off=: 0
+msg_name_sz=: 8
+msg_namelen_off=: 8
+msg_namelen_sz=: 4
+msg_iov_off=: 16
+msg_iov_sz=: 8
+msg_iovlen_off=: 24
+msg_iovlen_sz=: 4
+msg_control_off=: 32
+msg_control_sz=: 8
+msg_controllen_off=: 40
+msg_controllen_sz=: 4
+msg_flags_off=: 44
+msg_flags_sz=: 4
+
