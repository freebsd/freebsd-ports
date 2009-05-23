--- CodeLite/procutils.cpp.orig	2009-01-09 17:34:59.000000000 +0100
+++ CodeLite/procutils.cpp	2009-05-23 13:45:05.000000000 +0200
@@ -40,6 +40,15 @@
 
 #endif
 
+#ifdef __FreeBSD__
+#include <kvm.h>
+#include <fcntl.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <paths.h>
+#endif
+
 ProcUtils::ProcUtils()
 {
 }
@@ -135,6 +144,24 @@
 	CloseHandle( hModuleSnap );
 	return me32.szExePath;
 
+#elif defined(__FreeBSD__)
+	kvm_t *kvd;
+	struct kinfo_proc *ki;
+	int nof_procs;
+	wxString cmd;
+
+	if (!(kvd = kvm_openfiles(_PATH_DEVNULL, _PATH_DEVNULL, NULL, O_RDONLY, NULL)))
+	    return wxEmptyString;
+
+	if (!(ki = kvm_getprocs(kvd, KERN_PROC_PID, pid, &nof_procs))) {
+	    kvm_close(kvd);
+	    return wxEmptyString;
+	}
+
+	cmd = wxString(ki->ki_ocomm, wxConvUTF8);
+	kvm_close(kvd);
+
+	return (cmd);
 #else
 	wxArrayString output;
 	ExecuteCommand(wxT("ps -A -o pid,command --no-heading"), output);
@@ -223,6 +250,28 @@
 		proclist.push_back(entry);
 	} while (Process32Next (hProcessSnap, &pe));
 	CloseHandle (hProcessSnap);
+
+#elif defined(__FreeBSD__)
+	kvm_t *kvd;
+	struct kinfo_proc *ki;
+	int nof_procs, i;
+
+	if (!(kvd = kvm_openfiles(_PATH_DEVNULL, _PATH_DEVNULL, NULL, O_RDONLY, NULL)))
+	    return;
+
+	if (!(ki = kvm_getprocs(kvd, KERN_PROC_PROC, 0, &nof_procs))) {
+	    kvm_close(kvd);
+	    return;
+	}
+
+	for (i=0; i<nof_procs; i++) {
+	    ProcessEntry entry;
+	    entry.pid = ki[i].ki_pid;
+	    entry.name = wxString(ki[i].ki_ocomm, wxConvUTF8);
+	    proclist.push_back(entry);
+	}
+	kvm_close(kvd);
+
 #else
 	//GTK and other
 	wxArrayString output;
@@ -299,6 +348,28 @@
 		}
 	} while (Process32Next (hProcessSnap, &pe));
 	CloseHandle (hProcessSnap);
+
+#elif defined(__FreeBSD__)
+	kvm_t *kvd;
+	struct kinfo_proc *ki;
+	int nof_procs, i;
+
+	if (!(kvd = kvm_openfiles(_PATH_DEVNULL, _PATH_DEVNULL, NULL, O_RDONLY, NULL)))
+	    return;
+
+	if (!(ki = kvm_getprocs(kvd, KERN_PROC_PROC, pid, &nof_procs))) {
+	    kvm_close(kvd);
+	    return;
+	}
+
+	for (i=0; i<nof_procs; i++) {
+	    ProcessEntry entry;
+	    if (ki[i].ki_ppid == pid)
+		proclist.push_back(ki[i].ki_pid);
+	}
+
+	kvm_close(kvd);
+
 #else
 	//GTK and other
 	wxArrayString output;
