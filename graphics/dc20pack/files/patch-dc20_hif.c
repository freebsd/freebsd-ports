*** dc20_hif.c.orig	Sun Aug  1 13:55:41 1999
--- dc20_hif.c	Sun Aug  1 13:57:21 1999
***************
*** 15,21 ****
  unsigned char sts_res= 0, sts_bat= 0;
  unsigned char sts_pic_cnt= 0, sts_pic_rem= 0;
  unsigned char dc_type= 0x25;
! unsigned char com_dev[128]= "/dev/ttyS0";
  
  
  /* LOCAL VARIABLES ****************************************/
--- 15,21 ----
  unsigned char sts_res= 0, sts_bat= 0;
  unsigned char sts_pic_cnt= 0, sts_pic_rem= 0;
  unsigned char dc_type= 0x25;
! unsigned char com_dev[128]= "/dev/cuaa0";
  
  
  /* LOCAL VARIABLES ****************************************/
***************
*** 146,156 ****
  {
    switch (com_nr)
    {
!     case 1:  strcpy(com_dev, "/dev/ttyS0") ; break;
!     case 2:  strcpy(com_dev, "/dev/ttyS1") ; break;
!     case 3:  strcpy(com_dev, "/dev/ttyS2") ; break;
!     case 4:  strcpy(com_dev, "/dev/ttyS3") ; break;
!     default: strcpy(com_dev, "/dev/ttyS0") ; break;
    }
  
    if ((com_hdl = open(com_dev, O_RDWR)) == -1) 
--- 146,156 ----
  {
    switch (com_nr)
    {
!     case 1:  strcpy(com_dev, "/dev/cuaa0") ; break;
!     case 2:  strcpy(com_dev, "/dev/cuaa1") ; break;
!     case 3:  strcpy(com_dev, "/dev/cuaa2") ; break;
!     case 4:  strcpy(com_dev, "/dev/cuaa3") ; break;
!     default: strcpy(com_dev, "/dev/cuaa0") ; break;
    }
  
    if ((com_hdl = open(com_dev, O_RDWR)) == -1) 
