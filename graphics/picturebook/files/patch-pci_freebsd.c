--- ../picturebook.old/pci_freebsd.c	Mon Dec 25 19:09:23 2000
+++ pci_freebsd.c	Mon Dec 25 19:03:20 2000
@@ -0,0 +1,148 @@
+/* manipulate PCI devices from user space
+
+   Tridge, July 2000
+*/
+/* 
+   Copyright (C) Andrew Tridgell 2000
+   Copyright (C) Takanori Watanabe 2000
+   
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2 of the License, or
+   (at your option) any later version.
+   
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+   
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+*/
+#include "capture.h"
+#include <sys/types.h>
+#include <sys/pciio.h>
+#include <sys/fcntl.h>
+#define MAX_BUS 8
+
+#define PCI_GETCONF_MATCH_VENDDEV (PCI_GETCONF_MATCH_VENDOR|PCI_GETCONF_MATCH_DEVICE)
+#define MAXHANDLE 32
+
+static struct pci_io pio[MAXHANDLE];
+static u_int32_t handlebmp=0;
+static int pci_fd=-1;
+static int pcifd_internal_init();
+int pcifd_internal_init()
+{
+  return pci_fd=open("/dev/pci",O_RDWR,0);
+}
+/* find a PCI device and return a handle to it */
+int pci_find_device(u32 vendor, u32 device)
+{
+  
+  struct pci_conf pc[4];/*I think only one is enough*/
+  struct pci_conf_io pcfi;
+  struct pci_match_conf pmc={{0,0,0},"",0,0xffff,0xffff,0,
+			       PCI_GETCONF_MATCH_VENDDEV};
+  int handle;
+  if(pci_fd==-1){
+    if(pcifd_internal_init()==-1)
+      return -1;
+  }
+  pmc.pc_vendor=vendor;
+  pmc.pc_device=device;
+  pcfi.pat_buf_len=sizeof(pmc);
+  pcfi.num_patterns=1;
+  pcfi.patterns=&pmc;
+  pcfi.match_buf_len=sizeof(pc);
+  pcfi.num_matches=0;
+  pcfi.matches=pc;
+  pcfi.offset=0;
+  pcfi.generation=0;
+  ioctl(pci_fd,PCIOCGETCONF,&pcfi);
+  if(pcfi.num_matches==0){
+    goto error;
+  }
+  for(handle=0;handle<32;handle++){
+    if(!(handlebmp&(1<<handle))){
+      pio[handle].pi_sel=pc[0].pc_sel;
+      handlebmp|=(1<<handle);
+      return handle;
+    }
+  }
+ error:
+  close(pci_fd);
+  return -1;
+}
+
+
+/* routines to read and write PCI config space */
+#define PCICFGWACCESSOR(bsize) \
+int pci_config_write_u##bsize(int fd, int ofs, u##bsize v)\
+{\
+  int result;\
+  if(fd==-1){\
+    return -1;\
+  }\
+  if(pci_fd==-1){\
+    if(pcifd_internal_init()==-1)\
+       return -1;\
+  }\
+  pio[fd].pi_reg=ofs;\
+  pio[fd].pi_width=bsize/8;\
+  pio[fd].pi_data=v;\
+  result=ioctl(pci_fd,PCIOCWRITE,&pio[fd]);\
+  return result;\
+}
+PCICFGWACCESSOR(8)
+PCICFGWACCESSOR(16)
+PCICFGWACCESSOR(32)
+#undef PCICFGWACCESSOR
+/*Acctually define 
+  pci_config_write_u8();
+  pci_config_write_u16();
+  pci_config_write_u32();
+*/
+#define PCICFGRACCESSOR(bsize) \
+int pci_config_read_u##bsize(int fd, int ofs, u##bsize *v)\
+{\
+  int result;\
+  if(fd==-1){\
+    return -1;\
+  }\
+  if(pci_fd==-1){\
+    if(pcifd_internal_init()==-1)\
+       return -1;\
+  }\
+  pio[fd].pi_reg=ofs;\
+  pio[fd].pi_width=bsize/8;\
+  result=ioctl(pci_fd,PCIOCREAD,&pio[fd]);\
+  *v=pio[fd].pi_data&((bsize==32)? 0xffffffff: (1<<bsize)-1);\
+  return result;\
+}
+/*Acctually define 
+  pci_config_read_u8();
+  pci_config_read_u16();
+  pci_config_read_u32();
+*/
+PCICFGRACCESSOR(8) 
+PCICFGRACCESSOR(16) 
+PCICFGRACCESSOR(32) 
+#undef PCICFGRACCESSOR
+
+/* find a pci base address via /proc/bus/pci/devices. This seems to be
+   needed on some boxes. Why? */
+u_int32_t pci_read_base_address(u32 vendor, u32 device)
+{
+  return 0;/* In FreeBSD???*/
+}
+
+
+
+
+
+
+
+
+
