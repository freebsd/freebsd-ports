diff -rc ../../work.old/doscmd-20040330/dos.h ./dos.h
*** ../../work.old/doscmd-20040330/dos.h	Mon Mar 29 14:00:00 2004
--- ./dos.h	Tue Sep 15 16:22:30 2009
***************
*** 118,165 ****
   * use the first 21 bytes.
   */
  typedef struct {
!     u_char	drive		__attribute__ ((packed));
!     u_char      pattern[11]	__attribute__ ((packed));
!     u_char      flag		__attribute__ ((packed));
!     u_char      reserved1[4]	__attribute__ ((packed));
!     search_t    *searchptr	__attribute__ ((packed));
!     u_char      attr		__attribute__ ((packed));
!     u_short     time		__attribute__ ((packed));
!     u_short     date		__attribute__ ((packed));
!     u_long	size		__attribute__ ((packed));
!     u_char      name[13]	__attribute__ ((packed));
! }/*  __attribute__((__packed__))*/ find_block_t;
  
  /*
   * DOS directory entry structure
   */
  typedef struct {
!     u_char      name[8]		__attribute__ ((packed));
!     u_char      ext[3]		__attribute__ ((packed));
!     u_char      attr		__attribute__ ((packed));
!     u_char      reserved[10]	__attribute__ ((packed));
!     u_short     time		__attribute__ ((packed));
!     u_short     date		__attribute__ ((packed));
!     u_short     start		__attribute__ ((packed));
!     u_long      size		__attribute__ ((packed));
! } dosdir_t;
  
  /*
   * The Current Drive Structure
   */
  typedef struct {
! 	u_char	path[0x43]		__attribute__ ((packed));
! 	u_short	flag			__attribute__ ((packed));
! 	u_short	dpb_off			__attribute__ ((packed));
! 	u_short	dpb_seg			__attribute__ ((packed));
! 	u_short	redirector_off		__attribute__ ((packed));
! 	u_short	redirector_seg		__attribute__ ((packed));
! 	u_char	paramter_int21[2]	__attribute__ ((packed));
!         u_short	offset			__attribute__ ((packed));
! 	u_char	dummy			__attribute__ ((packed));
! 	u_char	ifs_driver[4]		__attribute__ ((packed));
! 	u_char	dummy2[2]		__attribute__ ((packed));
! }/* __attribute__((__packed__))*/ CDS;
  
  #define	CDS_remote	0x8000
  #define	CDS_ready	0x4000
--- 118,165 ----
   * use the first 21 bytes.
   */
  typedef struct {
!     u_char	drive;
!     u_char      pattern[11];
!     u_char      flag;
!     u_char      reserved1[4];
!     search_t    *searchptr;
!     u_char      attr;
!     u_short     time;
!     u_short     date;
!     u_long	size;
!     u_char      name[13];
! } __attribute__((packed)) find_block_t;
  
  /*
   * DOS directory entry structure
   */
  typedef struct {
!     u_char      name[8];
!     u_char      ext[3];
!     u_char      attr;
!     u_char      reserved[10];
!     u_short     time;
!     u_short     date;
!     u_short     start;
!     u_long      size;
! } __attribute__((packed)) dosdir_t;
  
  /*
   * The Current Drive Structure
   */
  typedef struct {
! 	u_char	path[0x43];
! 	u_short	flag;
! 	u_short	dpb_off;
! 	u_short	dpb_seg;
! 	u_short	redirector_off;
! 	u_short	redirector_seg;
! 	u_char	paramter_int21[2];
!         u_short	offset;
! 	u_char	dummy;
! 	u_char	ifs_driver[4];
! 	u_char	dummy2[2];
! } __attribute__((packed)) CDS;
  
  #define	CDS_remote	0x8000
  #define	CDS_ready	0x4000
***************
*** 172,333 ****
   * The List of Lists (used to get the CDS and a few other numbers)
   */
  typedef struct {
! 	u_char	dummy1[0x16]	__attribute__ ((packed));
! 	u_short	cds_offset	__attribute__ ((packed));
! 	u_short	cds_seg		__attribute__ ((packed));
! 	u_char  dummy2[6]	__attribute__ ((packed));
! 	u_char	numberbdev	__attribute__ ((packed));
! 	u_char	lastdrive	__attribute__ ((packed));
! } LOL;
  
  /*
   * The System File Table
   */
  typedef struct {
! /*00*/	u_short	nfiles		__attribute__ ((packed));	/* Number file handles referring to this file */
! /*02*/	u_short	open_mode	__attribute__ ((packed));	/* Open mode (bit 15 -> by FCB) */
! /*04*/	u_char	attribute	__attribute__ ((packed));
! /*05*/	u_short	info		__attribute__ ((packed));	/* 15 -> remote, 14 ->  dont set date */
! /*07*/	u_char	ddr_dpb[4]	__attribute__ ((packed));	/* Device Driver Header/Drive Paramter Block */
! /*0b*/	u_short	fd		__attribute__ ((packed));
! /*0d*/	u_short	time		__attribute__ ((packed));
! /*0f*/	u_short	date		__attribute__ ((packed));
! /*11*/	u_long	size		__attribute__ ((packed));
! /*15*/	u_long	offset		__attribute__ ((packed));
! /*19*/	u_short	rel_cluster	__attribute__ ((packed));
! /*1b*/	u_short	abs_cluster	__attribute__ ((packed));
! /*1d*/	u_char	dir_sector[2]	__attribute__ ((packed));
! /*1f*/	u_char	dir_entry	__attribute__ ((packed));
! /*20*/	u_char	name[8]		__attribute__ ((packed));
! /*28*/	u_char	ext[3]		__attribute__ ((packed));
! /*2b*/	u_char	sharesft[4]	__attribute__ ((packed));
! /*2f*/	u_char	sharenet[2]	__attribute__ ((packed));
! /*31*/	u_short	psp		__attribute__ ((packed));
! /*33*/	u_char	share_off[2]	__attribute__ ((packed));
! /*35*/	u_char	local_end[2]	__attribute__ ((packed));
! /*37*/	u_char	ifd_driver[4]	__attribute__ ((packed)); 
! } /*__attribute__((__packed__))*/ SFT;
  
  /*
   * Format of PCDOS 4.01 swappable data area
   * (Sorry, but you need a wide screen to make this look nice)
   */
  typedef struct {
!     u_char	err_crit	__attribute__ ((packed));	/*   00h    BYTE    critical error flag */
!     u_char	InDOS		__attribute__ ((packed));	/*   01h    BYTE    InDOS flag (count of active INT 21 calls) */
!     u_char	err_drive	__attribute__ ((packed));	/*   02h    BYTE    ??? drive number or FFh */
!     u_char	err_locus	__attribute__ ((packed));	/*   03h    BYTE    locus of last error */
!     u_short	err_code	__attribute__ ((packed));	/*   04h    WORD    extended error code of last error */
!     u_char	err_suggest	__attribute__ ((packed));	/*   06h    BYTE    suggested action for last error */
!     u_char	err_class	__attribute__ ((packed));	/*   07h    BYTE    class of last error */
!     u_short	err_di		__attribute__ ((packed));
!     u_short	err_es		__attribute__ ((packed));	/*   08h    DWORD   ES:DI pointer for last error */
!     u_short	dta_off		__attribute__ ((packed));
!     u_short	dta_seg		__attribute__ ((packed));	/*   0Ch    DWORD   current DTA */
!     u_short	psp		__attribute__ ((packed));	/*   10h    WORD    current PSP */
!     u_short	int_23_sp	__attribute__ ((packed));	/*   12h    WORD    stores SP across an INT 23 */
!     u_short	wait_status	__attribute__ ((packed));	/*   14h    WORD    return code from last process termination (set to 0 after reading with AH=4Dh) */
!     u_char	current_drive	__attribute__ ((packed));	/*   16h    BYTE    current drive */
!     u_char	break_flag	__attribute__ ((packed));	/*   17h    BYTE    extended break flag */
!     u_char	unknown1[2]	__attribute__ ((packed));	/*   18h  2 BYTEs   ??? */
!     u_short	int_21_ax	__attribute__ ((packed));	/*   1Ah    WORD    value of AX on call to INT 21 */
!     u_short	net_psp		__attribute__ ((packed));	/*   1Ch    WORD    PSP segment for sharing/network */
!     u_short	net_number	__attribute__ ((packed));	/*   1Eh    WORD    network machine number for sharing/network (0000h = us) */
!     u_short	first_mem	__attribute__ ((packed));	/*   20h    WORD    first usable memory block found when allocating memory */
!     u_short	best_mem	__attribute__ ((packed));	/*   22h    WORD    best usable memory block found when allocating memory */
!     u_short	last_mem	__attribute__ ((packed));	/*   24h    WORD    last usable memory block found when allocating memory */
!     u_char	unknown[10]	__attribute__ ((packed));	/*   26h  2 BYTEs   ??? (don't seem to be referenced) */
!     u_char	monthday	__attribute__ ((packed));	/*   30h    BYTE    day of month */
!     u_char	month		__attribute__ ((packed));	/*   31h    BYTE    month */
!     u_short	year		__attribute__ ((packed));	/*   32h    WORD    year - 1980 */
!     u_short	days		__attribute__ ((packed));	/*   34h    WORD    number of days since 1-1-1980 */
!     u_char	weekday		__attribute__ ((packed));	/*   36h    BYTE    day of week (0 = Sunday) */
!     u_char	unknown2[3]	__attribute__ ((packed));	/*   37h    BYTE    ??? */
!     u_char	ddr_head[30]	__attribute__ ((packed));	/*   38h 30 BYTEs   device driver request header */
!     u_short	ddre_ip		__attribute__ ((packed));
!     u_short	ddre_cs		__attribute__ ((packed));	/*   58h    DWORD   pointer to device driver entry point (used in calling driver) */
!     u_char	ddr_head2[22]	__attribute__ ((packed));	/*   5Ch 22 BYTEs   device driver request header */
!     u_char	ddr_head3[30]	__attribute__ ((packed));	/*   72h 30 BYTEs   device driver request header */
!     u_char	unknown3[6]	__attribute__ ((packed));	/*   90h  6 BYTEs   ??? */
!     u_char	clock_xfer[6]	__attribute__ ((packed));	/*   96h  6 BYTEs   CLOCK$ transfer record (see AH=52h) */
!     u_char	unknown4[2]	__attribute__ ((packed));	/*   9Ch  2 BYTEs   ??? */
!     u_char	filename1[128]	__attribute__ ((packed));	/*   9Eh 128 BYTEs  buffer for filename */
!     u_char	filename2[128]	__attribute__ ((packed));	/*  11Eh 128 BYTEs  buffer for filename */
!     u_char	findfirst[21]	__attribute__ ((packed));	/*  19Eh 21 BYTEs   findfirst/findnext search data block (see AH=4Eh) */
!     u_char	foundentry[32]	__attribute__ ((packed));	/*  1B3h 32 BYTEs   directory entry for found file */
!     u_char	cds[88]		__attribute__ ((packed));	/*  1D3h 88 BYTEs   copy of current directory structure for drive being accessed */
!     u_char	fcbname[11]	__attribute__ ((packed));	/*  22Bh 11 BYTEs   ??? FCB-format filename */
!     u_char	unknown5	__attribute__ ((packed));	/*  236h    BYTE    ??? */
!     u_char	wildcard[11]	__attribute__ ((packed));	/*  237h 11 BYTEs   wildcard destination specification for rename (FCB format) */
!     u_char	unknown6[11]	__attribute__ ((packed));	/*  242h  2 BYTEs   ??? */
!     u_char	attrmask	__attribute__ ((packed));	/*  24Dh    BYTE    attribute mask for directory search??? */
!     u_char	open_mode	__attribute__ ((packed));	/*  24Eh    BYTE    open mode */
!     u_char	unknown7[3]	__attribute__ ((packed));	/*  24fh    BYTE    ??? */
!     u_char	virtual_dos	__attribute__ ((packed));	/*  252h    BYTE    flag indicating how DOS function was invoked (00h = direct INT 20/INT 21, FFh = server call AX=5D00h) */
!     u_char	unknown8[9]	__attribute__ ((packed));	/*  253h    BYTE    ??? */
!     u_char	term_type	__attribute__ ((packed));	/*  25Ch    BYTE    type of process termination (00h-03h) */
!     u_char	unknown9[3]	__attribute__ ((packed));	/*  25Dh    BYTE    ??? */
!     u_short	dpb_off		__attribute__ ((packed));
!     u_short	dpb_seg		__attribute__ ((packed));	/*  260h    DWORD   pointer to Drive Parameter Block for critical error invocation */
!     u_short	int21_sf_off	__attribute__ ((packed));
!     u_short	int21_sf_seg	__attribute__ ((packed));	/*  264h    DWORD   pointer to stack frame containing user registers on INT 21 */
!     u_short	store_sp	__attribute__ ((packed));	/*  268h    WORD    stores SP??? */
!     u_short	dosdpb_off	__attribute__ ((packed));
!     u_short	dosdpb_seg	__attribute__ ((packed));	/*  26Ah    DWORD   pointer to DOS Drive Parameter Block for ??? */
!     u_short	disk_buf_seg	__attribute__ ((packed));	/*  26Eh    WORD    segment of disk buffer */
!     u_short	unknown10[4]	__attribute__ ((packed));	/*  270h    WORD    ??? */
!     u_char	media_id	__attribute__ ((packed));	/*  278h    BYTE    Media ID byte returned by AH=1Bh,1Ch */
!     u_char	unknown11	__attribute__ ((packed));	/*  279h    BYTE    ??? (doesn't seem to be referenced) */
!     u_short	unknown12[2]	__attribute__ ((packed));	/*  27Ah    DWORD   pointer to ??? */
!     u_short	sft_off		__attribute__ ((packed));
!     u_short	sft_seg		__attribute__ ((packed));	/*  27Eh    DWORD   pointer to current SFT */
!     u_short	cds_off		__attribute__ ((packed));
!     u_short	cds_seg		__attribute__ ((packed));	/*  282h    DWORD   pointer to current directory structure for drive being accessed */
!     u_short	fcb_off		__attribute__ ((packed));
!     u_short	fcb_seg		__attribute__ ((packed));	/*  286h    DWORD   pointer to caller's FCB */
!     u_short	unknown13[2]	__attribute__ ((packed));	/*  28Ah    WORD    ??? */
!     u_short	jft_off		__attribute__ ((packed));
!     u_short	jft_seg		__attribute__ ((packed));	/*  28Eh    DWORD   pointer to a JFT entry in process handle table (see AH=26h) */
!     u_short	filename1_off	__attribute__ ((packed));	/*  292h    WORD    offset in DOS CS of first filename argument */
!     u_short	filename2_off	__attribute__ ((packed));	/*  294h    WORD    offset in DOS CS of second filename argument */
!     u_short	unknown14[12]	__attribute__ ((packed));	/*  296h    WORD    ??? */
!     u_short	file_offset_lo	__attribute__ ((packed));
!     u_short	file_offset_hi	__attribute__ ((packed));	/*  2AEh    DWORD   offset in file??? */
!     u_short	unknown15	__attribute__ ((packed));	/*  2B2h    WORD    ??? */
!     u_short	partial_bytes	__attribute__ ((packed));	/*  2B4h    WORD    bytes in partial sector */
!     u_short	number_sectors	__attribute__ ((packed));	/*  2B6h    WORD    number of sectors */
!     u_short	unknown16[3]	__attribute__ ((packed));	/*  2B8h    WORD    ??? */
!     u_short	nbytes_lo	__attribute__ ((packed));
!     u_short	nbytes_hi	__attribute__ ((packed));	/*  2BEh    DWORD   number of bytes appended to file */
!     u_short	qpdb_off	__attribute__ ((packed));
!     u_short	qpdb_seg	__attribute__ ((packed));	/*  2C2h    DWORD   pointer to ??? disk buffer */
!     u_short	asft_off	__attribute__ ((packed));
!     u_short	asft_seg	__attribute__ ((packed));	/*  2C6h    DWORD   pointer to ??? SFT */
!     u_short	int21_bx	__attribute__ ((packed));	/*  2CAh    WORD    used by INT 21 dispatcher to store caller's BX */
!     u_short	int21_ds	__attribute__ ((packed));	/*  2CCh    WORD    used by INT 21 dispatcher to store caller's DS */
!     u_short	temporary	__attribute__ ((packed));	/*  2CEh    WORD    temporary storage while saving/restoring caller's registers */
!     u_short	prevcall_off	__attribute__ ((packed));
!     u_short	prevcall_seg	__attribute__ ((packed));	/*  2D0h    DWORD   pointer to prev call frame (offset 264h) if INT 21 reentered also switched to for duration of INT 24 */
!     u_char	unknown17[9]	__attribute__ ((packed));	/*  2D4h    WORD    ??? */
!     u_short	ext_action	__attribute__ ((packed));	/*  2DDh    WORD    multipurpose open action */
!     u_short	ext_attr	__attribute__ ((packed));	/*  2DFh    WORD    multipurpose attribute */
!     u_short	ext_mode	__attribute__ ((packed));	/*  2E1h    WORD    multipurpose mode */
!     u_char	unknown17a[9]	__attribute__ ((packed));
!     u_short	lol_ds		__attribute__ ((packed));	/*  2ECh    WORD    stores DS during call to [List-of-Lists + 37h] */
!     u_char	unknown18[5]	__attribute__ ((packed));	/*  2EEh    WORD    ??? */
!     u_char	usernameptr[4]	__attribute__ ((packed));	/*  2F3h    DWORD   pointer to user-supplied filename */
!     u_char	unknown19[4]	__attribute__ ((packed));	/*  2F7h    DWORD   pointer to ??? */
!     u_char	lol_ss[2]	__attribute__ ((packed));	/*  2FBh    WORD    stores SS during call to [List-of-Lists + 37h] */
!     u_char	lol_sp[2]	__attribute__ ((packed));	/*  2FDh    WORD    stores SP during call to [List-of-Lists + 37h] */
!     u_char	lol_flag	__attribute__ ((packed));	/*  2FFh    BYTE    flag, nonzero if stack switched in calling [List-of-Lists+37h] */
!     u_char	searchdata[21]	__attribute__ ((packed));	/*  300h 21 BYTEs   FindFirst search data for source file(s) of a rename operation (see AH=4Eh) */
!     u_char	renameentry[32]	__attribute__ ((packed));	/*  315h 32 BYTEs   directory entry for file being renamed */
!     u_char	errstack[331]	__attribute__ ((packed));	/*  335h 331 BYTEs  critical error stack */
!     u_char	diskstack[384]	__attribute__ ((packed));	/*  480h 384 BYTEs  disk stack (functions greater than 0Ch, INT 25, INT 26) */
!     u_char	iostack[384]	__attribute__ ((packed));	/*  600h 384 BYTEs  character I/O stack (functions 01h through 0Ch) */
!     u_char	int_21_08_flag	__attribute__ ((packed));	/*  780h    BYTE    flag affecting AH=08h (see AH=64h) */
!     u_char	unknown20[11]	__attribute__ ((packed));	/*  781h    BYTE    ??? looks like a drive number */
! } /*__attribute__((__packed__))*/ SDA;
  
  struct exehdr {
  	u_short magic;
--- 172,333 ----
   * The List of Lists (used to get the CDS and a few other numbers)
   */
  typedef struct {
! 	u_char	dummy1[0x16];
! 	u_short	cds_offset;
! 	u_short	cds_seg;
! 	u_char  dummy2[6];
! 	u_char	numberbdev;
! 	u_char	lastdrive;
! } __attribute__((packed)) LOL;
  
  /*
   * The System File Table
   */
  typedef struct {
! /*00*/	u_short	nfiles;	/* Number file handles referring to this file */
! /*02*/	u_short	open_mode;	/* Open mode (bit 15 -> by FCB) */
! /*04*/	u_char	attribute;
! /*05*/	u_short	info;	/* 15 -> remote, 14 ->  dont set date */
! /*07*/	u_char	ddr_dpb[4];	/* Device Driver Header/Drive Paramter Block */
! /*0b*/	u_short	fd;
! /*0d*/	u_short	time;
! /*0f*/	u_short	date;
! /*11*/	u_long	size;
! /*15*/	u_long	offset;
! /*19*/	u_short	rel_cluster;
! /*1b*/	u_short	abs_cluster;
! /*1d*/	u_char	dir_sector[2];
! /*1f*/	u_char	dir_entry;
! /*20*/	u_char	name[8];
! /*28*/	u_char	ext[3];
! /*2b*/	u_char	sharesft[4];
! /*2f*/	u_char	sharenet[2];
! /*31*/	u_short	psp;
! /*33*/	u_char	share_off[2];
! /*35*/	u_char	local_end[2];
! /*37*/	u_char	ifd_driver[4]; 
! } __attribute__((packed)) SFT;
  
  /*
   * Format of PCDOS 4.01 swappable data area
   * (Sorry, but you need a wide screen to make this look nice)
   */
  typedef struct {
!     u_char	err_crit;	/*   00h    BYTE    critical error flag */
!     u_char	InDOS;	/*   01h    BYTE    InDOS flag (count of active INT 21 calls) */
!     u_char	err_drive;	/*   02h    BYTE    ??? drive number or FFh */
!     u_char	err_locus;	/*   03h    BYTE    locus of last error */
!     u_short	err_code;	/*   04h    WORD    extended error code of last error */
!     u_char	err_suggest;	/*   06h    BYTE    suggested action for last error */
!     u_char	err_class;	/*   07h    BYTE    class of last error */
!     u_short	err_di;
!     u_short	err_es;	/*   08h    DWORD   ES:DI pointer for last error */
!     u_short	dta_off;
!     u_short	dta_seg;	/*   0Ch    DWORD   current DTA */
!     u_short	psp;	/*   10h    WORD    current PSP */
!     u_short	int_23_sp;	/*   12h    WORD    stores SP across an INT 23 */
!     u_short	wait_status;	/*   14h    WORD    return code from last process termination (set to 0 after reading with AH=4Dh) */
!     u_char	current_drive;	/*   16h    BYTE    current drive */
!     u_char	break_flag;	/*   17h    BYTE    extended break flag */
!     u_char	unknown1[2];	/*   18h  2 BYTEs   ??? */
!     u_short	int_21_ax;	/*   1Ah    WORD    value of AX on call to INT 21 */
!     u_short	net_psp;	/*   1Ch    WORD    PSP segment for sharing/network */
!     u_short	net_number;	/*   1Eh    WORD    network machine number for sharing/network (0000h = us) */
!     u_short	first_mem;	/*   20h    WORD    first usable memory block found when allocating memory */
!     u_short	best_mem;	/*   22h    WORD    best usable memory block found when allocating memory */
!     u_short	last_mem;	/*   24h    WORD    last usable memory block found when allocating memory */
!     u_char	unknown[10];	/*   26h  2 BYTEs   ??? (don't seem to be referenced) */
!     u_char	monthday;	/*   30h    BYTE    day of month */
!     u_char	month;	/*   31h    BYTE    month */
!     u_short	year;	/*   32h    WORD    year - 1980 */
!     u_short	days;	/*   34h    WORD    number of days since 1-1-1980 */
!     u_char	weekday;	/*   36h    BYTE    day of week (0 = Sunday) */
!     u_char	unknown2[3];	/*   37h    BYTE    ??? */
!     u_char	ddr_head[30];	/*   38h 30 BYTEs   device driver request header */
!     u_short	ddre_ip;
!     u_short	ddre_cs;	/*   58h    DWORD   pointer to device driver entry point (used in calling driver) */
!     u_char	ddr_head2[22];	/*   5Ch 22 BYTEs   device driver request header */
!     u_char	ddr_head3[30];	/*   72h 30 BYTEs   device driver request header */
!     u_char	unknown3[6];	/*   90h  6 BYTEs   ??? */
!     u_char	clock_xfer[6];	/*   96h  6 BYTEs   CLOCK$ transfer record (see AH=52h) */
!     u_char	unknown4[2];	/*   9Ch  2 BYTEs   ??? */
!     u_char	filename1[128];	/*   9Eh 128 BYTEs  buffer for filename */
!     u_char	filename2[128];	/*  11Eh 128 BYTEs  buffer for filename */
!     u_char	findfirst[21];	/*  19Eh 21 BYTEs   findfirst/findnext search data block (see AH=4Eh) */
!     u_char	foundentry[32];	/*  1B3h 32 BYTEs   directory entry for found file */
!     u_char	cds[88];	/*  1D3h 88 BYTEs   copy of current directory structure for drive being accessed */
!     u_char	fcbname[11];	/*  22Bh 11 BYTEs   ??? FCB-format filename */
!     u_char	unknown5;	/*  236h    BYTE    ??? */
!     u_char	wildcard[11];	/*  237h 11 BYTEs   wildcard destination specification for rename (FCB format) */
!     u_char	unknown6[11];	/*  242h  2 BYTEs   ??? */
!     u_char	attrmask;	/*  24Dh    BYTE    attribute mask for directory search??? */
!     u_char	open_mode;	/*  24Eh    BYTE    open mode */
!     u_char	unknown7[3];	/*  24fh    BYTE    ??? */
!     u_char	virtual_dos;	/*  252h    BYTE    flag indicating how DOS function was invoked (00h = direct INT 20/INT 21, FFh = server call AX=5D00h) */
!     u_char	unknown8[9];	/*  253h    BYTE    ??? */
!     u_char	term_type;	/*  25Ch    BYTE    type of process termination (00h-03h) */
!     u_char	unknown9[3];	/*  25Dh    BYTE    ??? */
!     u_short	dpb_off;
!     u_short	dpb_seg;	/*  260h    DWORD   pointer to Drive Parameter Block for critical error invocation */
!     u_short	int21_sf_off;
!     u_short	int21_sf_seg;	/*  264h    DWORD   pointer to stack frame containing user registers on INT 21 */
!     u_short	store_sp;	/*  268h    WORD    stores SP??? */
!     u_short	dosdpb_off;
!     u_short	dosdpb_seg;	/*  26Ah    DWORD   pointer to DOS Drive Parameter Block for ??? */
!     u_short	disk_buf_seg;	/*  26Eh    WORD    segment of disk buffer */
!     u_short	unknown10[4];	/*  270h    WORD    ??? */
!     u_char	media_id;	/*  278h    BYTE    Media ID byte returned by AH=1Bh,1Ch */
!     u_char	unknown11;	/*  279h    BYTE    ??? (doesn't seem to be referenced) */
!     u_short	unknown12[2];	/*  27Ah    DWORD   pointer to ??? */
!     u_short	sft_off;
!     u_short	sft_seg;	/*  27Eh    DWORD   pointer to current SFT */
!     u_short	cds_off;
!     u_short	cds_seg;	/*  282h    DWORD   pointer to current directory structure for drive being accessed */
!     u_short	fcb_off;
!     u_short	fcb_seg;	/*  286h    DWORD   pointer to caller's FCB */
!     u_short	unknown13[2];	/*  28Ah    WORD    ??? */
!     u_short	jft_off;
!     u_short	jft_seg;	/*  28Eh    DWORD   pointer to a JFT entry in process handle table (see AH=26h) */
!     u_short	filename1_off;	/*  292h    WORD    offset in DOS CS of first filename argument */
!     u_short	filename2_off;	/*  294h    WORD    offset in DOS CS of second filename argument */
!     u_short	unknown14[12];	/*  296h    WORD    ??? */
!     u_short	file_offset_lo;
!     u_short	file_offset_hi;	/*  2AEh    DWORD   offset in file??? */
!     u_short	unknown15;	/*  2B2h    WORD    ??? */
!     u_short	partial_bytes;	/*  2B4h    WORD    bytes in partial sector */
!     u_short	number_sectors;	/*  2B6h    WORD    number of sectors */
!     u_short	unknown16[3];	/*  2B8h    WORD    ??? */
!     u_short	nbytes_lo;
!     u_short	nbytes_hi;	/*  2BEh    DWORD   number of bytes appended to file */
!     u_short	qpdb_off;
!     u_short	qpdb_seg;	/*  2C2h    DWORD   pointer to ??? disk buffer */
!     u_short	asft_off;
!     u_short	asft_seg;	/*  2C6h    DWORD   pointer to ??? SFT */
!     u_short	int21_bx;	/*  2CAh    WORD    used by INT 21 dispatcher to store caller's BX */
!     u_short	int21_ds;	/*  2CCh    WORD    used by INT 21 dispatcher to store caller's DS */
!     u_short	temporary;	/*  2CEh    WORD    temporary storage while saving/restoring caller's registers */
!     u_short	prevcall_off;
!     u_short	prevcall_seg;	/*  2D0h    DWORD   pointer to prev call frame (offset 264h) if INT 21 reentered also switched to for duration of INT 24 */
!     u_char	unknown17[9];	/*  2D4h    WORD    ??? */
!     u_short	ext_action;	/*  2DDh    WORD    multipurpose open action */
!     u_short	ext_attr;	/*  2DFh    WORD    multipurpose attribute */
!     u_short	ext_mode;	/*  2E1h    WORD    multipurpose mode */
!     u_char	unknown17a[9];
!     u_short	lol_ds;	/*  2ECh    WORD    stores DS during call to [List-of-Lists + 37h] */
!     u_char	unknown18[5];	/*  2EEh    WORD    ??? */
!     u_char	usernameptr[4];	/*  2F3h    DWORD   pointer to user-supplied filename */
!     u_char	unknown19[4];	/*  2F7h    DWORD   pointer to ??? */
!     u_char	lol_ss[2];	/*  2FBh    WORD    stores SS during call to [List-of-Lists + 37h] */
!     u_char	lol_sp[2];	/*  2FDh    WORD    stores SP during call to [List-of-Lists + 37h] */
!     u_char	lol_flag;	/*  2FFh    BYTE    flag, nonzero if stack switched in calling [List-of-Lists+37h] */
!     u_char	searchdata[21];	/*  300h 21 BYTEs   FindFirst search data for source file(s) of a rename operation (see AH=4Eh) */
!     u_char	renameentry[32];	/*  315h 32 BYTEs   directory entry for file being renamed */
!     u_char	errstack[331];	/*  335h 331 BYTEs  critical error stack */
!     u_char	diskstack[384];	/*  480h 384 BYTEs  disk stack (functions greater than 0Ch, INT 25, INT 26) */
!     u_char	iostack[384];	/*  600h 384 BYTEs  character I/O stack (functions 01h through 0Ch) */
!     u_char	int_21_08_flag;	/*  780h    BYTE    flag affecting AH=08h (see AH=64h) */
!     u_char	unknown20[11];	/*  781h    BYTE    ??? looks like a drive number */
! } __attribute__((packed)) SDA;
  
  struct exehdr {
  	u_short magic;
Only in .: dos.h.orig
diff -rc ../../work.old/doscmd-20040330/ems.h ./ems.h
*** ../../work.old/doscmd-20040330/ems.h	Mon Mar 29 14:00:00 2004
--- ./ems.h	Tue Sep 15 16:24:00 2009
***************
*** 242,250 ****
   */
  
  typedef struct {
!     u_short handle __attribute__ ((packed));   /* handle */
!     u_short npages __attribute__ ((packed));   /* pages allocated */
! } EMShandlepage;
  
  /*
   * EMS map/unmap multiple, only used to pass information to and from
--- 242,250 ----
   */
  
  typedef struct {
!     u_short handle;   /* handle */
!     u_short npages;   /* pages allocated */
! } __attribute__((packed)) EMShandlepage;
  
  /*
   * EMS map/unmap multiple, only used to pass information to and from
***************
*** 252,261 ****
   */
  
  typedef struct {
!     u_short log __attribute__ ((packed));   /* logical page number */
!     u_short phys __attribute__ ((packed));  /* physical page (position) or
  					      segment address inside frame */
! } EMSmapunmap;
  
  /*
   * EMS handle directory, only used to pass information to and from
--- 252,261 ----
   */
  
  typedef struct {
!     u_short log;   /* logical page number */
!     u_short phys;  /* physical page (position) or
  					      segment address inside frame */
! } __attribute__ ((packed)) EMSmapunmap;
  
  /*
   * EMS handle directory, only used to pass information to and from
***************
*** 263,272 ****
   */
  
  typedef struct {
!    u_short log  __attribute__ ((packed));   /* logical page number */
!    Hname   name __attribute__ ((packed));   /* Handle name */
  
! } EMShandledir;
  
  /*
   * Structure for get/set page map: This structure is used to save and
--- 263,272 ----
   */
  
  typedef struct {
!    u_short log;   /* logical page number */
!    Hname   name;   /* Handle name */
  
! } __attribute__ ((packed)) EMShandledir;
  
  /*
   * Structure for get/set page map: This structure is used to save and
***************
*** 287,295 ****
   */
  
  typedef struct {
!    u_short segm __attribute__ ((packed));  /* segment address inside frame */
!    u_short phys __attribute__ ((packed));  /* physical page (position) */
! } EMSaddrarray;
  
  /*
   * EMS move memory call structure, only used to pass information to and from
--- 287,295 ----
   */
  
  typedef struct {
!    u_short segm;  /* segment address inside frame */
!    u_short phys;  /* physical page (position) */
! } __attribute__ ((packed)) EMSaddrarray;
  
  /*
   * EMS move memory call structure, only used to pass information to and from
***************
*** 297,313 ****
   */
  
  typedef struct {
!    u_long  length __attribute__ ((packed));      /* length of region */
  #define EMS_MOVE_CONV 0
  #define EMS_MOVE_EMS  1
!    u_char  src_type __attribute__ ((packed));    /* source type (0,1) */
!    u_short src_handle __attribute__ ((packed));  /* source handle */
!    u_short src_offset __attribute__ ((packed));  /* source offset */
!    u_short src_seg __attribute__ ((packed));     /* source type  */
!    u_char  dst_type __attribute__ ((packed));    /* destination type (0,1) */
!    u_short dst_handle __attribute__ ((packed));  /* destination handle */
!    u_short dst_offset __attribute__ ((packed));  /* destination offset */
!    u_short dst_seg __attribute__ ((packed));     /* destination type  */
! } EMSmovemem;
  
  #endif /* EMS_H */
--- 297,313 ----
   */
  
  typedef struct {
!    u_long  length;      /* length of region */
  #define EMS_MOVE_CONV 0
  #define EMS_MOVE_EMS  1
!    u_char  src_type;    /* source type (0,1) */
!    u_short src_handle;  /* source handle */
!    u_short src_offset;  /* source offset */
!    u_short src_seg;     /* source type  */
!    u_char  dst_type;    /* destination type (0,1) */
!    u_short dst_handle;  /* destination handle */
!    u_short dst_offset;  /* destination offset */
!    u_short dst_seg;     /* destination type  */
! } __attribute__ ((packed)) EMSmovemem;
  
  #endif /* EMS_H */
diff -rc ../../work.old/doscmd-20040330/int14.c ./int14.c
*** ../../work.old/doscmd-20040330/int14.c	Tue Sep 15 16:26:36 2009
--- ./int14.c	Tue Sep 15 16:25:04 2009
***************
*** 636,642 ****
  	"com_set_line: going with cflag 0x%X iflag 0x%X speed %d.\n",
  	cdsp->tty.c_cflag, cdsp->tty.c_iflag, speed);
      div_lo = (115200 / spd) & 0x00ff;
!     div_hi = (115200 / spd) & 0xff00;
      cdsp->div_latch[DIV_LATCH_LOW] = div_lo;
      cdsp->div_latch[DIV_LATCH_HIGH] = div_hi;
      errno = 0;
--- 636,642 ----
  	"com_set_line: going with cflag 0x%X iflag 0x%X speed %d.\n",
  	cdsp->tty.c_cflag, cdsp->tty.c_iflag, speed);
      div_lo = (115200 / spd) & 0x00ff;
!     div_hi = ((115200 / spd) & 0xff00) >> 8;
      cdsp->div_latch[DIV_LATCH_LOW] = div_lo;
      cdsp->div_latch[DIV_LATCH_HIGH] = div_hi;
      errno = 0;
diff -rc ../../work.old/doscmd-20040330/xms.h ./xms.h
*** ../../work.old/doscmd-20040330/xms.h	Mon Mar 29 14:00:00 2004
--- ./xms.h	Tue Sep 15 16:26:02 2009
***************
*** 99,109 ****
  
  struct EMM {
     u_long  nbytes;
!    u_short src_handle __attribute__ ((packed));
!    u_long  src_offset __attribute__ ((packed));
!    u_short dst_handle __attribute__ ((packed));
!    u_long  dst_offset __attribute__ ((packed));
! } ;
  
  /*
   * XMS info structure, only used to pass information to and from
--- 99,109 ----
  
  struct EMM {
     u_long  nbytes;
!    u_short src_handle;
!    u_long  src_offset;
!    u_short dst_handle;
!    u_long  dst_offset;
! } __attribute__ ((packed));
  
  /*
   * XMS info structure, only used to pass information to and from
***************
*** 112,121 ****
  
  struct XMSinfo {
     u_char handle;				/* the handle */
!    u_char num_locks __attribute__ ((packed));   /* number of locks */
!    u_long size __attribute__ ((packed));	/* size of memory */
!    u_long phys_addr __attribute__ ((packed));   /* "physical" address */
! };
  
  /*
   * Handle management inside the emulator for extended memory pages, 
--- 112,121 ----
  
  struct XMSinfo {
     u_char handle;				/* the handle */
!    u_char num_locks;   /* number of locks */
!    u_long size;	/* size of memory */
!    u_long phys_addr;   /* "physical" address */
! } __attribute__ ((packed));
  
  /*
   * Handle management inside the emulator for extended memory pages, 
