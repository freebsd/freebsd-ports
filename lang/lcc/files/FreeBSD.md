%{
#define FREEBSDMD_RCSID	"$FreeBSD$"

enum { EAX=0, ECX=1, EDX=2, EBX=3, ESI=6, EDI=7 };
#include "c.h"
#define NODEPTR_TYPE Node
#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->kids[0])
#define RIGHT_CHILD(p) ((p)->kids[1])
#define STATE_LABEL(p) ((p)->x.state)
static void address     ARGS((Symbol, Symbol, int));
static void blkfetch    ARGS((int, int, int, int));
static void blkloop     ARGS((int, int, int, int, int, int[]));
static void blkstore    ARGS((int, int, int, int));
static int  ckstack     ARGS((Node, int));
static void defaddress  ARGS((Symbol));
static void defconst    ARGS((int, Value));
static void defstring   ARGS((int, char *));
static void defsymbol   ARGS((Symbol));
static void doarg       ARGS((Node));
static void emit0       ARGS((Node));
static void emit2       ARGS((Node));
static void export      ARGS((Symbol));
static void clobber     ARGS((Node));
static void function    ARGS((Symbol, Symbol [], Symbol [], int));
static void global      ARGS((Symbol));
static void import      ARGS((Symbol));
static void local       ARGS((Symbol));
static void progbeg     ARGS((int, char **));
static void progend     ARGS((void));
static void segment     ARGS((int));
static void space       ARGS((int));
static void target      ARGS((Node));
static int memop ARGS((Node));
static int hasargs ARGS((Node));
static int sametree ARGS((Node, Node));
static Symbol charreg[32], shortreg[32], intreg[32];
static Symbol fltreg[32];

static int cseg;

static Symbol quo, rem;

%}
%start stmt
%term ADDD=306 ADDF=305 ADDI=309 ADDP=311 ADDU=310
%term ADDRFP=279
%term ADDRGP=263
%term ADDRLP=295
%term ARGB=41 ARGD=34 ARGF=33 ARGI=37 ARGP=39
%term ASGNB=57 ASGNC=51 ASGND=50 ASGNF=49 ASGNI=53 ASGNP=55 ASGNS=52
%term BANDU=390
%term BCOMU=406
%term BORU=422
%term BXORU=438
%term CALLB=217 CALLD=210 CALLF=209 CALLI=213 CALLV=216
%term CNSTC=19 CNSTD=18 CNSTF=17 CNSTI=21 CNSTP=23 CNSTS=20 CNSTU=22
%term CVCI=85 CVCU=86
%term CVDF=97 CVDI=101
%term CVFD=114
%term CVIC=131 CVID=130 CVIS=132 CVIU=134
%term CVPU=150
%term CVSI=165 CVSU=166
%term CVUC=179 CVUI=181 CVUP=183 CVUS=180
%term DIVD=450 DIVF=449 DIVI=453 DIVU=454
%term EQD=482 EQF=481 EQI=485
%term GED=498 GEF=497 GEI=501 GEU=502
%term GTD=514 GTF=513 GTI=517 GTU=518
%term INDIRB=73 INDIRC=67 INDIRD=66 INDIRF=65 INDIRI=69 INDIRP=71 INDIRS=68
%term JUMPV=584
%term LABELV=600
%term LED=530 LEF=529 LEI=533 LEU=534
%term LOADB=233 LOADC=227 LOADD=226 LOADF=225 LOADI=229 LOADP=231 LOADS=228 LOADU=230
%term LSHI=341 LSHU=342
%term LTD=546 LTF=545 LTI=549 LTU=550
%term MODI=357 MODU=358
%term MULD=466 MULF=465 MULI=469 MULU=470
%term NED=562 NEF=561 NEI=565
%term NEGD=194 NEGF=193 NEGI=197
%term RETD=242 RETF=241 RETI=245
%term RSHI=373 RSHU=374
%term SUBD=322 SUBF=321 SUBI=325 SUBP=327 SUBU=326
%term VREGP=615
%%

reg: INDIRC(VREGP)	"# read register\n"
reg: INDIRI(VREGP)	"# read register\n"
reg: INDIRP(VREGP)	"# read register\n"
reg: INDIRS(VREGP)	"# read register\n"
freg: INDIRD(VREGP)	"# read register\n"
freg: INDIRF(VREGP)	"# read register\n"
stmt: ASGNC(VREGP,reg)	"# write register\n"
stmt: ASGNI(VREGP,reg)	"# write register\n"
stmt: ASGNP(VREGP,reg)	"# write register\n"
stmt: ASGNS(VREGP,reg)	"# write register\n"
stmt: ASGND(VREGP,freg)	"# write register\n"
stmt: ASGNF(VREGP,freg)	"# write register\n"
con: CNSTC	"$%a"
con: CNSTI	"$%a"
con: CNSTP	"$%a"
con: CNSTS	"$%a"
con: CNSTU	"$%a"
stmt: reg	""
stmt: freg	""
reg: CVIU(reg)  "%0"  notarget(a)
reg: CVPU(reg)  "%0"  notarget(a)
reg: CVUI(reg)  "%0"  notarget(a)
reg: CVUP(reg)  "%0"  notarget(a)

acon: ADDRGP	"%a"
acon: CNSTC	"%a"
acon: CNSTI	"%a"
acon: CNSTP	"%a"
acon: CNSTS	"%a"
acon: CNSTU	"%a"

baseaddr: ADDRGP	"%a"
base: reg   	    	"(%0)"
base: ADDI(reg,acon)	"%1(%0)"
base: ADDP(reg,acon)	"%1(%0)"
base: ADDU(reg,acon)	"%1(%0)"
base: ADDRFP		"%a(%%ebp)"
base: ADDRLP		"%a(%%ebp)"

con1: CNSTI	"1"	range(a, 1, 1)
con1: CNSTU	"1"	range(a, 1, 1)

icon: CNSTI	"2"	range(a, 1, 1)
icon: CNSTU	"2"	range(a, 1, 1)
icon: CNSTI	"4"	range(a, 2, 2)
icon: CNSTU	"4"	range(a, 2, 2)
icon: CNSTI	"8"	range(a, 3, 3)
icon: CNSTU	"8"	range(a, 3, 3)

index: reg              "%0"
index: LSHI(reg,icon)	"%0,%1"
index: LSHU(reg,icon)	"%0,%1"

addr: base			"%0" 1
addr: baseaddr			"%0"
addr: ADDI(index,baseaddr)	"%1(,%0)"
addr: ADDI(reg,baseaddr)	"%1(%0)"
addr: ADDI(index,reg)		"(%1,%0)"

addr: ADDP(index,baseaddr)	"%1(,%0)"
addr: ADDP(reg,baseaddr)	"%1(%0)"
addr: ADDP(index,reg)		"(%1,%0)"
addr: ADDU(index,baseaddr)	"%1(,%0)"
addr: ADDU(reg,baseaddr)	"%1(%0)"
addr: ADDU(index,reg)		"(%1,%0)"
addr: index			"(,%0)"

memb: INDIRC(addr)	"%0"
memw: INDIRS(addr)	"%0"
mem:  INDIRI(addr)	"%0"
mem:  INDIRP(addr)	"%0"

rc5: CNSTI	"$%a"	range(a, 0, 31)
rc5: reg	"%%cl"

rc: reg		"%0"
rc: con		"%0"

mr:   reg  "%0"
mr:   mem  "%0"

mrb:   reg  "%0"
mrb:   memb  "%0"

mrw:   reg  "%0"
mrw:   memw  "%0"

mrc: mem  "%0"  1
mrc: memb  "%0"  1
mrc: memw  "%0"  1
mrc: rc   "%0"

reg: addr		"\tleal\t%0,%c\n"			1
reg: mr			"\tmovl\t%0,%c\n"			1
reg: mrb		"\tmovb\t%0,%c\n"			1
reg: mrw		"\tmovw\t%0,%c\n"			1
reg: con		"\tmovl\t%0,%c\n"			1
reg: LOADC(reg)		"\tmovb\t%0,%c\n"			move(a)
reg: LOADI(reg)		"\tmovl\t%0,%c\n"			move(a)
reg: LOADP(reg)		"\tmovl\t%0,%c\n"			move(a)
reg: LOADS(reg)		"\tmovw\t%0,%c\n"			move(a)
reg: LOADU(reg)		"\tmovl\t%0,%c\n"			move(a)
reg: ADDI(reg,mrc)	"?\tmovl\t%0,%c\n\taddl\t%1,%c\n"	1
reg: ADDP(reg,mrc)	"?\tmovl\t%0,%c\n\taddl\t%1,%c\n"	1
reg: ADDU(reg,mrc)	"?\tmovl\t%0,%c\n\taddl\t%1,%c\n"	1
reg: SUBI(reg,mrc)	"?\tmovl\t%0,%c\n\tsubl\t%1,%c\n"	1
reg: SUBP(reg,mrc)	"?\tmovl\t%0,%c\n\tsubl\t%1,%c\n"	1
reg: SUBU(reg,mrc)	"?\tmovl\t%0,%c\n\tsubl\t%1,%c\n"	1
reg: BANDU(reg,mrc)	"?\tmovl\t%0,%c\n\tandl\t%1,%c\n"	1
reg: BORU(reg,mrc)	"?\tmovl\t%0,%c\n\torl\t%1,%c\n"	1
reg: BXORU(reg,mrc)	"?\tmovl\t%0,%c\n\txorl\t%1,%c\n"	1
reg: LSHI(reg,rc5)	"?\tmovl\t%0,%c\n\tsall\t%1,%c\n"	2
reg: LSHU(reg,rc5)	"?\tmovl\t%0,%c\n\tshll\t%1,%c\n"	2
reg: RSHI(reg,rc5)	"?\tmovl\t%0,%c\n\tsarl\t%1,%c\n"	2
reg: RSHU(reg,rc5)	"?\tmovl\t%0,%c\n\tshrl\t%1,%c\n"	2
reg: BCOMU(reg)		"?\tmovl\t%0,%c\n\tnotl\t%c\n"		2
reg: NEGI(reg)		"?\tmovl\t%0,%c\n\tnegl\t%c\n"		2

stmt: ASGNI(addr,ADDI(mem,con1)) "\tincl\t%1\n"		memop(a)
stmt: ASGNI(addr,ADDU(mem,con1)) "\tincl\t%1\n"		memop(a)
stmt: ASGNP(addr,ADDP(mem,con1)) "\tincl\t%1\n"		memop(a)
stmt: ASGNI(addr,SUBI(mem,con1)) "\tdecl\t%1\n"		memop(a)
stmt: ASGNI(addr,SUBU(mem,con1)) "\tdecl\t%1\n"		memop(a)
stmt: ASGNP(addr,SUBP(mem,con1))"\tdecl\t%1\n"		memop(a)
stmt: ASGNI(addr,ADDI(mem,rc))	"\taddl\t%2,%1\n"	memop(a)
stmt: ASGNI(addr,ADDU(mem,rc))	"\taddl\t%2,%1\n" 	memop(a)
stmt: ASGNI(addr,SUBI(mem,rc))	"\tsubl\t%2,%1\n"	memop(a)
stmt: ASGNI(addr,SUBU(mem,rc))	"\tsubl\t%2,%1\n"	memop(a)
stmt: ASGNI(addr,BANDU(mem,rc))	"\tandl\t%2,%1\n"  	memop(a)
stmt: ASGNI(addr,BORU(mem,rc))	"\torl\t%2,%1\n"	memop(a)
stmt: ASGNI(addr,BXORU(mem,rc))	"\txorl\t%2,%1\n" 	memop(a)
stmt: ASGNI(addr,BCOMU(mem))	"\tnotl\t%1\n"		memop(a)
stmt: ASGNI(addr,NEGI(mem))	"\tnegl\t%1\n"  	memop(a)
stmt: ASGNI(addr,LSHI(mem,rc5))	"\tsall\t%2,%1\n"	memop(a)
stmt: ASGNI(addr,LSHU(mem,rc5))	"\tshll\t%2,%1\n"	memop(a)
stmt: ASGNI(addr,RSHI(mem,rc5))	"\tsarl\t%2,%1\n"	memop(a)
stmt: ASGNI(addr,RSHU(mem,rc5))	"\tshrl\t%2,%1\n"	memop(a)

reg: MULI(reg,mrc)	"?\tmovl\t%0,%c\n\timull\t%1,%c\n"  14
reg: MULI(con,mr)	"\timul\t%0,%1,%c\n"	13
reg: MULU(reg,mr)	"\tmull\t%1\n"		13
reg: DIVU(reg,reg)	"\txorl\t%%edx,%%edx\n\tdivl\t%1\n"
reg: MODU(reg,reg)	"\txorl\t%%edx,%%edx\n\tdivl\t%1\n"
reg: DIVI(reg,reg)	"\tcdq\n\tidivl\t%1\n"
reg: MODI(reg,reg)	"\tcdq\n\tidivl\t%1\n"
reg: CVIU(reg)		"\tmovl\t%0,%c\n"	move(a)
reg: CVPU(reg)		"\tmovl\t%0,%c\n"	move(a)
reg: CVUI(reg)		"\tmovl\t%0,%c\n"	move(a)
reg: CVUP(reg)		"\tmovl\t%0,%c\n"	move(a)
reg: CVCI(INDIRC(addr))	"\tmovsbl\t%0,%c\n"	3
reg: CVCU(INDIRC(addr))	"\tmovzbl\t%0,%c\n"	3
reg: CVSI(INDIRS(addr))	"\tmovswl\t%0,%c\n"	3
reg: CVSU(INDIRS(addr))	"\tmovzwl\t%0,%c\n"	3

reg: CVCI(reg)  "# extend\n"  3
reg: CVCU(reg)  "# extend\n"  3
reg: CVSI(reg)  "# extend\n"  3
reg: CVSU(reg)  "# extend\n"  3
reg: CVIC(reg)  "# truncate\n"  1
reg: CVIS(reg)  "# truncate\n"  1
reg: CVUC(reg)  "# truncate\n"  1
reg: CVUS(reg)  "# truncate\n"  1

mrca: mem  "%0"
mrca: rc   "%0"
mrca: ADDRGP "$%a"

stmt: ASGNC(addr,rc)	"\tmovb\t%1,%0\n"	1
stmt: ASGNI(addr,rc)	"\tmovl\t%1,%0\n"	1
stmt: ASGNP(addr,rc)	"\tmovl\t%1,%0\n"	1
stmt: ASGNS(addr,rc)	"\tmovw\t%1,%0\n"	1
stmt: ASGNB(reg,INDIRB(reg)) "\tmovl\t$%a,%%ecx\n\trep\n\tmovsb\n"
stmt: ARGI(mrca)	"\tpushl\t%0\n"  1
stmt: ARGP(mrca)	"\tpushl\t%0\n"  1
stmt: ARGB(INDIRB(reg)) "\tsubl\t$%a,%%esp\n\tmovl\t%%esp,%%edi\n\tmovl\t$%a,%%ecx\n\trep\n\tmovsb\n"

memf: INDIRD(addr)		"l\t%0"
memf: INDIRF(addr)		"s\t%0"
memf: CVFD(INDIRF(addr))	"s\t%0"
freg: memf			"\tfld%0\n"		3
stmt: ASGND(addr,freg)		"\tfstpl\t%0\n"  7
stmt: ASGNF(addr,freg)		"\tfstps\t%0\n"  7
stmt: ASGNF(addr,CVDF(freg))	"\tfstps\t%0\n"  7
stmt: ARGD(freg)		"\tsubl\t$8,%%esp\n\tfstpl\t(%%esp)\n"
stmt: ARGF(freg)		"\tsubl\t$4,%%esp\n\tfstps\t(%%esp)\n"
freg: NEGD(freg)		"\tfchs\n"
freg: NEGF(freg)		"\tfchs\n"

flt: memf	"%0"
flt: freg	"p\t%%st,%%st(1)"

freg: ADDD(freg,flt)	"\tfadd%1\n"
freg: ADDF(freg,flt)	"\tfadd%1\n"
freg: DIVD(freg,memf)	"\tfdiv%1\n"
freg: DIVD(freg,freg)	"\tfdivrp\t%%st,%%st(1)\n"
freg: DIVF(freg,memf)	"\tfdiv%1\n"
freg: DIVF(freg,freg)	"\tfdivrp\t%%st,%%st(1)\n"
freg: MULD(freg,flt)	"\tfmul%1\n"
freg: MULF(freg,flt)	"\tfmul%1\n"
freg: SUBD(freg,memf)	"\tfsub%1\n"
freg: SUBD(freg,freg)	"\tfsubrp\t%%st,%%st(1)\n"
freg: SUBF(freg,memf)	"\tfsub%1\n"
freg: SUBF(freg,freg)	"\tfsubrp\t%%st,%%st(1)\n"
freg: CVFD(freg)  "# CVFD\n"
freg: CVDF(freg)  "\tsub\t$4,%%esp ; fstps (%%esp) ; flds (%%esp) ; addl $4,%%esp\n"  12

stmt: ASGNI(addr,CVDI(freg))  "\tfistpl\t%0\n"  29
reg: CVDI(freg)  "\tsubl\t$4,%%esp\n\tfistpl\t0(%%esp)\n\tpopl\t%c\n" 31

freg: CVID(INDIRI(addr))  "\tfildl\t%0\n"  10
freg: CVID(reg)  "\tpushl\t%0\n\tfildl\t(%%esp)\n\taddl\t$4,%%esp\n"  12

addrj: ADDRGP  "%a"
addrj: reg     "*%0"  2
addrj: mem     "*%0"  2

addrjmp: ADDRGP  "%a"
addrjmp: reg     "*%0"  2
addrjmp: mem     "*%0"  2

stmt: LABELV		"%a:\n"
stmt: JUMPV(addrjmp)	"\tjmp\t%0\n"  3
stmt: EQI(mem,rc)	"\tcmpl\t%1,%0\n\tje\t%a\n"   5
stmt: GEI(mem,rc)	"\tcmpl\t%1,%0\n\tjge\t%a\n"  5
stmt: GTI(mem,rc)	"\tcmpl\t%1,%0\n\tjg\t%a\n"   5
stmt: LEI(mem,rc)	"\tcmpl\t%1,%0\n\tjle\t%a\n"  5
stmt: LTI(mem,rc)	"\tcmpl\t%1,%0\n\tjl\t%a\n"   5
stmt: NEI(mem,rc)	"\tcmpl\t%1,%0\n\tjne\t%a\n"  5
stmt: GEU(mem,rc)	"\tcmpl\t%1,%0\n\tjae\t%a\n"  5
stmt: GTU(mem,rc)	"\tcmpl\t%1,%0\n\tja \t%a\n"  5
stmt: LEU(mem,rc)	"\tcmpl\t%1,%0\n\tjbe\t%a\n"  5
stmt: LTU(mem,rc)	"\tcmpl\t%1,%0\n\tjb \t%a\n"  5
stmt: EQI(reg,mrc)	"\tcmpl\t%1,%0\n\tje\t%a\n"   4
stmt: GEI(reg,mrc)	"\tcmpl\t%1,%0\n\tjge\t%a\n"  4
stmt: GTI(reg,mrc)	"\tcmpl\t%1,%0\n\tjg\t%a\n"   4
stmt: LEI(reg,mrc)	"\tcmpl\t%1,%0\n\tjle\t%a\n"  4
stmt: LTI(reg,mrc)	"\tcmpl\t%1,%0\n\tjl\t%a\n"   4
stmt: NEI(reg,mrc)	"\tcmpl\t%1,%0\n\tjne\t%a\n"  4

stmt: GEU(reg,mrc)	"\tcmpl\t%1,%0\n\tjae\t%a\n"  4
stmt: GTU(reg,mrc)	"\tcmpl\t%1,%0\n\tja \t%a\n"  4
stmt: LEU(reg,mrc)	"\tcmpl\t%1,%0\n\tjbe\t%a\n"  4
stmt: LTU(reg,mrc)	"\tcmpl\t%1,%0\n\tjb \t%a\n"  4

cmpf: INDIRD(addr)		"l\t%0"
cmpf: INDIRF(addr)		"s\t%0"
cmpf: CVFD(INDIRF(addr))	"s\t%0"
cmpf: freg	"p"

stmt: EQD(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tje\t%a\n"
stmt: GED(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjbe\t%a\n"
stmt: GTD(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjb\t%a\n"
stmt: LED(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjae\t%a\n"
stmt: LTD(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tja\t%a\n"
stmt: NED(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjne\t%a\n"

stmt: EQF(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tje\t%a\n"
stmt: GEF(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjbe\t%a\n"
stmt: GTF(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjb\t%a\n"
stmt: LEF(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjae\t%a\n"
stmt: LTF(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tja\t%a\n"
stmt: NEF(cmpf,freg)	"\tfcomp%0 ; fstsw %%ax ; sahf\n\tjne\t%a\n"

reg:  CALLI(addrj)  "\tcall\t%0\n\taddl\t$%a,%%esp\n"	hasargs(a)
reg:  CALLI(addrj)  "\tcall\t%0\n"			1

stmt: CALLV(addrj)  "\tcall\t%0\n\taddl\t$%a,%%esp\n"	hasargs(a)
stmt: CALLV(addrj)  "\tcall\t%0\n"			1

freg: CALLF(addrj)  "\tcall\t%0\n\taddl\t$%a,%%esp\n"	hasargs(a)
freg: CALLF(addrj)  "\tcall\t%0\n"			1

stmt: CALLF(addrj)  "\tcall\t%0\n\taddl\t$%a,%%esp\n\tfstp\t%%st(0)\n"	hasargs(a)
stmt: CALLF(addrj)  "\tcall\t%0\n\tfstp\t%%st(0)\n"			1

freg: CALLD(addrj)  "\tcall\t%0\n\taddl\t$%a,%%esp\n"	hasargs(a)
freg: CALLD(addrj)  "\tcall\t%0\n"			1

stmt: CALLD(addrj)  "\tcall\t%0\n\taddl\t$%a,%%esp\n\tfstp\t%%st(0)\n"	hasargs(a)
stmt: CALLD(addrj)  "\tcall\t%0\n\tfstp\t%%st(0)\n"			1

stmt: RETI(reg)  "# ret\n"
stmt: RETF(freg)  "# retf\n"
stmt: RETD(freg)  "# retd\n"

%%

static void 
progbeg(argc, argv)
	char *argv[];
{
	int i;

	{
		union {
			char c;
			int i;
		} u;
		u.i = 0;
		u.c = 1;
		swap = (u.i == 1) != IR->little_endian;
	}
	parseflags(argc, argv);
	intreg[EAX] = mkreg("%%eax", EAX, 1, IREG);
	intreg[EDX] = mkreg("%%edx", EDX, 1, IREG);
	intreg[ECX] = mkreg("%%ecx", ECX, 1, IREG);
	intreg[EBX] = mkreg("%%ebx", EBX, 1, IREG);
	intreg[ESI] = mkreg("%%esi", ESI, 1, IREG);
	intreg[EDI] = mkreg("%%edi", EDI, 1, IREG);
	shortreg[EAX] = mkreg("%%ax", EAX, 1, IREG);
	shortreg[ECX] = mkreg("%%cx", ECX, 1, IREG);
	shortreg[EDX] = mkreg("%%dx", EDX, 1, IREG);
	shortreg[EBX] = mkreg("%%bx", EBX, 1, IREG);
	shortreg[ESI] = mkreg("%%si", ESI, 1, IREG);
	shortreg[EDI] = mkreg("%%di", EDI, 1, IREG);

	charreg[EAX] = mkreg("%%al", EAX, 1, IREG);
	charreg[ECX] = mkreg("%%cl", ECX, 1, IREG);
	charreg[EDX] = mkreg("%%dl", EDX, 1, IREG);
	charreg[EBX] = mkreg("%%bl", EBX, 1, IREG);
	for (i = 0; i < 8; i++)
		fltreg[i] = mkreg("%d", i, 0, FREG);
	rmap[C] = mkwildcard(charreg);
	rmap[S] = mkwildcard(shortreg);
	rmap[P] = rmap[B] = rmap[U] = rmap[I] = mkwildcard(intreg);
	rmap[F] = rmap[D] = mkwildcard(fltreg);
	tmask[IREG] = (1 << EDI) | (1 << ESI) | (1 << EBX)
		| (1 << EDX) | (1 << ECX) | (1 << EAX);
	vmask[IREG] = 0;
	tmask[FREG] = 0xff;
	vmask[FREG] = 0;
	print("\t.text\n");
	cseg = 0;
	quo = mkreg("%%eax", EAX, 1, IREG);
	quo->x.regnode->mask |= 1<<EDX;
	rem = mkreg("%%edx", EDX, 1, IREG);
	rem->x.regnode->mask |= 1<<EAX;
}

static void 
segment(n)
{
	if (n == cseg)
		return;
	cseg = n;
	if (n == CODE)
		print("\t.text\n");
	else if (cseg == BSS)
    	    	print("\t.bss\n");
	else if (cseg == DATA || cseg == LIT)
		print("\t.data\n");
}

static void 
progend()
{
	segment(0);
}
static void target(p) Node p; {
	assert(p);
	switch (p->op) {
	case RSHI: case RSHU: case LSHI: case LSHU:
		if (generic(p->kids[1]->op) != CNST
		&& !(   generic(p->kids[1]->op) == INDIR
		     && p->kids[1]->kids[0]->op == VREG+P
		     && p->kids[1]->syms[RX]->u.t.cse
		     && generic(p->kids[1]->syms[RX]->u.t.cse->op) == CNST
)) {
			rtarget(p, 1, intreg[ECX]);
			setreg(p, intreg[EAX]);
		}
		break;
	case MULU:
		setreg(p, quo);
		rtarget(p, 0, intreg[EAX]);
		break;
	case DIVI: case DIVU:
		setreg(p, quo);
		rtarget(p, 0, intreg[EAX]);
		rtarget(p, 1, intreg[ECX]);
		break;
	case MODI: case MODU:
		setreg(p, rem);
		rtarget(p, 0, intreg[EAX]);
		rtarget(p, 1, intreg[ECX]);
		break;
	case ASGNB:
		rtarget(p, 0, intreg[EDI]);
		rtarget(p, 1, intreg[ESI]);
		break;
	case ARGB:
		rtarget(p->kids[0], 0, intreg[ESI]);
		break;
	case CALLI: case CALLV:
		setreg(p, intreg[EAX]);
		break;
	case RETI:
		rtarget(p, 0, intreg[EAX]);
		break;
	}
}

static void clobber(p) Node p; {
	static int nstack = 0;

	assert(p);
	nstack = ckstack(p, nstack);
	assert(p->count > 0 || nstack == 0);
	switch (p->op) {
     
        case DIVI: case DIVU: case MULU:
               spill(1 << EDX, IREG, p);
               break;
        case MODI: case MODU:
               spill(1 << EAX, IREG, p);
               break;

	case ASGNB: case ARGB:
		spill(1<<ECX | 1<<ESI | 1<<EDI, IREG, p);
		break;
	case EQD: case LED: case GED: case LTD: case GTD: case NED:
	case EQF: case LEF: case GEF: case LTF: case GTF: case NEF:
		spill(1<<EAX, IREG, p);
		break;
	case CALLD: case CALLF:
		spill(1<<EDX | 1<<EAX, IREG, p);
		break;
	}
}


#define isfp(p) (optype((p)->op)==F || optype((p)->op)==D)

static int ckstack(p, n) Node p; int n; {
	int i;

	for (i = 0; i < NELEMS(p->x.kids) && p->x.kids[i]; i++)
		if (isfp(p->x.kids[i]))
			n--;
	if (isfp(p) && p->count > 0)
		n++;
	if (n > 8)
		error("expression too complicated\n");
	debug(fprint(2, "(ckstack(%x)=%d)\n", p, n));
	assert(n >= 0);
	return n;
}

static int
hasargs(p)
	Node p;
{
	assert(p);
	assert(generic(p->op) == CALL);
	assert(p->syms[0]);
	if (p->syms[0]->u.c.v.i > 0)
		return 0;
	return LBURG_MAX;
}

static int 
memop(p)
	Node p;
{
	assert(p);
	assert(generic(p->op) == ASGN);
	assert(p->kids[0]);
	assert(p->kids[1]);
	if (generic(p->kids[1]->kids[0]->op) == INDIR
	    && sametree(p->kids[0], p->kids[1]->kids[0]->kids[0]))
		return 3;
	else
		return LBURG_MAX;
}

static int 
sametree(p, q)
	Node p, q;
{
	return p == NULL && q == NULL
		|| p && q && p->op == q->op && p->syms[0] == q->syms[0]
		&& sametree(p->kids[0], q->kids[0])
		&& sametree(p->kids[1], q->kids[1]);
}

static void
emit0(q)
	Node q;
{
#if _EMIT_DEBUG
	Node p = q;
	for (; p; p = p->x.next) {
		if (p->op == LABEL+V) {
			assert(p->syms[0]);
			print("# %s:\n", p->syms[0]->x.name);
		} else {
			int i;
			print("# node%c%d %s count=%d", p->x.listed ? '\'' : '#', p->x.inst,
				opname(p->op), p->count);
			for (i = 0; i < NELEMS(p->kids) && p->kids[i]; i++)
				print(" #%d", p->kids[i]->x.inst);
			for (i = 0; i < NELEMS(p->syms) && p->syms[i]; i++) {
				if (p->syms[i]->x.name)
					print(" %s", p->syms[i]->x.name);
				if (p->syms[i]->name != p->syms[i]->x.name)
					print(" (%s)", p->syms[i]->name);
			}
			print("\n");
		}
	}
#endif
	emit(q);
}

static void 
emit2(p)
	Node p;
{
#define preg(f) ((f)[getregnum(p->x.kids[0])]->x.name)

	switch (p->op) {
	case CVCI:
		print("\tmovsbl\t%s,%s\n",
		      preg(charreg),
		      p->syms[RX]->x.name);
		break;
	case CVCU:
		print("\tmovzbl\t%s,%s\n",
		      preg(charreg),
		      p->syms[RX]->x.name);
		break;
	case CVSI:
		print("\tmovswl\t%s,%s\n",
		      preg(shortreg),
		      p->syms[RX]->x.name);
		break;
	case CVSU:
		print("\tmovzwl\t%s,%s\n",
		      preg(shortreg),
		      p->syms[RX]->x.name);
		break;
	case CVIC: case CVIS:
	case CVUC: case CVUS:
		{ char *dst = shortreg[getregnum(p)]->x.name;
		  char *src = preg(shortreg);
		  if (dst != src)
			print("\tmovl\t%s,%s\n", src, dst);
		}
		break;
	}
}

static void 
doarg(p)
	Node p;
{
	assert(p && p->syms[0]);
	mkactual(4, p->syms[0]->u.c.v.i);
}

static void 
blkfetch(k, off, reg, tmp)
{
}

static void 
blkstore(k, off, reg, tmp)
{
}

static void 
blkloop(dreg, doff, sreg, soff, size, tmps)
	int tmps[];
{
}

static void 
local(p)
	Symbol p;
{
	if (isfloat(p->type))
		p->sclass = AUTO;
	if (askregvar(p, rmap[ttob(p->type)]) == 0)
		mkauto(p);
}

static void 
function(f, caller, callee, n)
	Symbol f, callee[], caller[];
	int n;
{
	int i;

	print("\t.type\t%s,@function\n", f->x.name);
	print("%s:\n", f->x.name);
	print("\tpushl\t%%ebx\n");
	print("\tpushl\t%%esi\n");
	print("\tpushl\t%%edi\n");
	print("\tpushl\t%%ebp\n");
	print("\tmovl\t%%esp,%%ebp\n");

	usedmask[0] = usedmask[1] = 0;
	freemask[0] = freemask[1] = ~(unsigned) 0;
	offset = 16 + 4;
	for (i = 0; callee[i]; i++) {
		Symbol p = callee[i];
		Symbol q = caller[i];
		assert(q);
		offset = roundup(offset, q->type->align);
		p->x.offset = q->x.offset = offset;
		p->x.name = q->x.name = stringf("%d", p->x.offset);
		p->sclass = q->sclass = AUTO;
		offset += roundup(q->type->size, 4);
	}
	assert(caller[i] == 0);
	offset = maxoffset = 0;
	gencode(caller, callee);
	framesize = roundup(maxoffset, 4);
	if (framesize > 0)
		print("\tsubl\t$%d,%%esp\n", framesize);
	emitcode();

	print("\tleave\n");
	print("\tpopl\t%%edi\n");
	print("\tpopl\t%%esi\n");
	print("\tpopl\t%%ebx\n");
	print("\tret\n");
	{ int l = genlabel(1);
	  print("L%d:\n", l);
	  print("\t.size\t%s,L%d-%s\n", f->x.name, l, f->x.name);
	}
}

static void 
defsymbol(p)
	Symbol p;
{
	if (p->scope >= LOCAL && p->sclass == STATIC)
		p->x.name = stringf("L%d", genlabel(1));
	else if (p->generated)
		p->x.name = stringf("L%s", p->name);
	else if (p->scope == GLOBAL || p->sclass == EXTERN)
		p->x.name = stringf("_%s", p->name);
/*
	else if (p->scope == CONSTANTS
		 && (isint(p->type) || isptr(p->type))
		 && p->name[0] == '0' && p->name[1] == 'x')
		p->x.name = stringf("0%sH", &p->name[2]);
*/
	else
		p->x.name = p->name;
}

static void 
address(q, p, n)
	Symbol q, p;
	int n;
{
	if (p->scope == GLOBAL
	    || p->sclass == STATIC || p->sclass == EXTERN)
		q->x.name = stringf("%s%s%d",
				    p->x.name, n >= 0 ? "+" : "", n);
	else {
		q->x.offset = p->x.offset + n;
		q->x.name = stringd(q->x.offset);
	}
}

static void 
defconst(ty, v)
	Value v;
{
	switch (ty) {
	case C:
		print("\t.byte\t%d\n", v.uc);
		return;
	case S:
		print("\t.word\t%d\n", v.ss);
		return;
	case I:
		print("\t.long\t%d\n", v.i);
		return;
	case U:
		print("\t.long\t0x%x\n", v.u);
		return;
	case P:
		print("\t.long\t0x%x\n", v.p);
		return;
	case F:
		print("\t.long\t0x%x\n", *(unsigned *) &v.f);
		return;
	case D:{
			unsigned *p = (unsigned *) &v.d;
			print("\t.long\t0x%x,0x%x\n", p[swap], p[1 - swap]);
			return;
		}
	}
	assert(0);
}

static void 
defaddress(p)
	Symbol p;
{
	print("\t.long\t%s\n", p->x.name);
}

static void 
defstring(n, str)
	char *str;
{
	char *s;
#if 1
	for (s = str; s < str + n; s++)
		print("\t.byte\t%d\n", *s);
#else
	print("\t.ascii\t\"", *s);
	for (s = str; s < str + n; s++)
		if (*s < 0x20)
			print("\\0%o", *s);
		else
			print("%c", *s);
	print("\"\n");
#endif
}

static void 
export(p)
	Symbol p;
{
	print("\t.globl\t%s\n", p->x.name);
}

static void 
import(p)
	Symbol p;
{
	int oldseg = cseg;

	if (p->ref > 0) {
		segment(0);
		print("\t.extern\t%s\n", p->x.name);
		segment(oldseg);
	}
}

static void global (p)
	Symbol p;
{
	print("\t.align\t%d\n", p->type->align > 4 ? 4 : p->type->align);
	if (!p->generated)
		print("\t.type\t%s,@%s\n", p->x.name,
			isfunc(p->type) ? "function" : "object");
	if (p->u.seg == BSS) {
		if (p->sclass == STATIC)
			print("\t.lcomm\t%s,%d\n", p->x.name, p->type->size);
		else
			print("\t.comm\t%s,%d\n", p->x.name, p->type->size);
	} else {
		if (!p->generated)
			print("\t.size\t%s,%d\n", p->x.name, p->type->size);
		print("%s:\n", p->x.name);
	}
}

static void 
space(n)
{
	if (cseg != BSS)
		print("\t.space\t%d\n", n);
}

#include <stab.h>
static char *currentfile;       /* current file name */
static int ntypes;

static void stabblock ARGS((int, int, Symbol*));
static void stabfend ARGS((Symbol, int));
static void stabinit ARGS((char *, int, char *[]));
static void stabline ARGS((Coordinate *));
static void stabsym ARGS((Symbol));
static void stabtype ARGS((Symbol));

static void asgncode ARGS((Type, int));
static void dbxout ARGS((Type));
static int dbxtype ARGS((Type));
static int emittype ARGS((Type, int, int));

/* asgncode - assign type code to ty */
static void asgncode(ty, lev) Type ty; {
	if (ty->x.marked || ty->x.typeno)
		return;
	ty->x.marked = 1;
	switch (ty->op) {
	case VOLATILE: case CONST: case VOLATILE+CONST:
		asgncode(ty->type, lev);
		ty->x.typeno = ty->type->x.typeno;
		break;
	case POINTER: case FUNCTION: case ARRAY:
		asgncode(ty->type, lev + 1);
		/* fall thru */
	case VOID: case CHAR: case SHORT: case INT: case UNSIGNED:
	case FLOAT: case DOUBLE:
		break;
	case STRUCT: case UNION: {
		Field p;
		for (p = fieldlist(ty); p; p = p->link)
			asgncode(p->type, lev + 1);
		/* fall thru */
	case ENUM:
		if (ty->x.typeno == 0)
			ty->x.typeno = ++ntypes;
		if (lev > 0 && (*ty->u.sym->name < '0' || *ty->u.sym->name > '9'))
			dbxout(ty);
		break;
		}
	default:
		assert(0);
	}
}

/* dbxout - output .stabs entry for type ty */
static void dbxout(ty) Type ty; {
	ty = unqual(ty);
	if (!ty->x.printed) {
		int col = 0;
		print(".stabs \""), col += 8;
		if (ty->u.sym && !(isfunc(ty) || isarray(ty) || isptr(ty)))
			print("%s", ty->u.sym->name), col += strlen(ty->u.sym->name);
		print(":%c", isstruct(ty) || isenum(ty) ? 'T' : 't'), col += 2;
		emittype(ty, 0, col);
		print("\",%d,0,0,0\n", N_LSYM);
	}
}

/* dbxtype - emit a stabs entry for type ty, return type code */
static int dbxtype(ty) Type ty; {
	asgncode(ty, 0);
	dbxout(ty);
	return ty->x.typeno;
}

/*
 * emittype - emit ty's type number, emitting its definition if necessary.
 * Returns the output column number after emission; col is the approximate
 * output column before emission and is used to emit continuation lines for long
 * struct, union, and enum types. Continuations are not emitted for other types,
 * even if the definition is long. lev is the depth of calls to emittype.
 */
static int emittype(ty, lev, col) Type ty; {
	int tc = ty->x.typeno;

	if (isconst(ty) || isvolatile(ty)) {
		col = emittype(ty->type, lev, col);
		ty->x.typeno = ty->type->x.typeno;
		ty->x.printed = 1;
		return col;
	}
	if (tc == 0) {
		ty->x.typeno = tc = ++ntypes;
/*              fprint(2,"`%t'=%d\n", ty, tc); */
	}
	print("%d", tc), col += 3;
	if (ty->x.printed)
		return col;
	ty->x.printed = 1;
	switch (ty->op) {
	case VOID:	/* void is defined as itself */
		print("=%d", tc), col += 1+3;
		break;
	case CHAR:	/* unsigned char is a subrange of int */
		if (ty == unsignedchar)
			print("=r1;0;255;"), col += 10;
		else	/* following pcc, char is a subrange of itself */
			print("=r%d;-128;127;", tc), col += 2+3+10;
		break;
	case SHORT:	/* short is a subrange of int */
		if (ty == unsignedshort)
			print("=r1;0;65535;"), col += 12;
		else	/* signed */
			print("=r1;-32768;32767;"), col += 17;
		break;
	case INT:	/* int is a subrange of itself */
		print("=r1;%d;%d;", INT_MIN, INT_MAX), col += 4+11+1+10+1;
		break;
	case UNSIGNED:	/* unsigned is a subrange of int */
		print("=r1;0;-1;"), col += 9;
		break;
	case FLOAT: case DOUBLE:	/* float, double get sizes instead of ranges */
		print("=r1;%d;0;", ty->size), col += 4+1+3;
		break;
	case POINTER:
		print("=*"), col += 2;
		col = emittype(ty->type, lev + 1, col);
		break;
	case FUNCTION:
		print("=f"), col += 2;
		col = emittype(ty->type, lev + 1, col);
		break;
	case ARRAY:	/* array includes subscript as an int range */
		if (ty->size && ty->type->size)
			print("=ar1;0;%d;", ty->size/ty->type->size - 1), col += 7+3+1;
		else
			print("=ar1;0;-1;"), col += 10;
		col = emittype(ty->type, lev + 1, col);
		break;
	case STRUCT: case UNION: {
		Field p;
		if (!ty->u.sym->defined) {
			print("=x%c%s:", ty->op == STRUCT ? 's' : 'u', ty->u.sym->name);
			col += 2+1+strlen(ty->u.sym->name)+1;
			break;
		}
		if (lev > 0 && (*ty->u.sym->name < '0' || *ty->u.sym->name > '9')) {
			ty->x.printed = 0;
			break;
		}
		print("=%c%d", ty->op == STRUCT ? 's' : 'u', ty->size), col += 1+1+3;
		for (p = fieldlist(ty); p; p = p->link) {
			if (p->name)
				print("%s:", p->name), col += strlen(p->name)+1;
			else
				print(":"), col += 1;
			col = emittype(p->type, lev + 1, col);
			if (p->lsb)
				print(",%d,%d;", 8*p->offset +
					(IR->little_endian ? fieldright(p) : fieldleft(p)),
					fieldsize(p));
			else
				print(",%d,%d;", 8*p->offset, 8*p->type->size);
			col += 1+3+1+3+1;	/* accounts for ,%d,%d; */
			if (col >= 80 && p->link) {
				print("\\\\\",%d,0,0,0\n.stabs \"", N_LSYM);
				col = 8;
			}
		}
		print(";"), col += 1;
		break;
		}
	case ENUM: {
		Symbol *p;
		if (lev > 0 && (*ty->u.sym->name < '0' || *ty->u.sym->name > '9')) {
			ty->x.printed = 0;
			break;
		}
		print("=e"), col += 2;
		for (p = ty->u.sym->u.idlist; *p; p++) {
			print("%s:%d,", (*p)->name, (*p)->u.value), col += strlen((*p)->name)+3;
			if (col >= 80 && p[1]) {
				print("\\\\\",%d,0,0,0\n.stabs \"", N_LSYM);
				col = 8;
			}
		}
		print(";"), col += 1;
		break;
		}
	default:
		assert(0);
	}
	return col;
}

/* stabblock - output a stab entry for '{' or '}' at level lev */
static void stabblock(brace, lev, p) Symbol *p; {
	if (brace == '{')
		while (*p)
			stabsym(*p++);
	print(".stabd 0x%x,0,%d\n", brace == '{' ? N_LBRAC : N_RBRAC, lev);
}

/* stabfend - end of function p */
static void stabfend(p, line) Symbol p; {}

/* stabinit - initialize stab output */
static void stabinit(file, argc, argv) char *file, *argv[]; {
	typedef void (*Closure) ARGS((Symbol, void *));

	if (file && *file) {
		(*IR->segment)(CODE);
		print("Ltext:.stabs \"%s\",0x%x,0,0,Ltext\n", file, N_SO);
		currentfile = file;
	}
	dbxtype(inttype);
	dbxtype(chartype);
	dbxtype(doubletype);
	dbxtype(floattype);
	dbxtype(longdouble);
	dbxtype(longtype);
	dbxtype(shorttype);
	dbxtype(signedchar);
	dbxtype(unsignedchar);
	dbxtype(unsignedlong);
	dbxtype(unsignedshort);
	dbxtype(unsignedtype);
	dbxtype(voidtype);
	foreach(types, GLOBAL, (Closure)stabtype, NULL);
}

/* stabline - emit stab entry for source coordinate *cp */
static void stabline(cp) Coordinate *cp; {
	if (cp->file && cp->file != currentfile) {
		int lab = genlabel(1);
		print("L%d: .stabs \"%s\",0x%x,0,0,L%d\n", lab,
				cp->file, N_SOL, lab);
		currentfile = cp->file;
	}
	print(".stabd 0x%x,0,%d\n", N_SLINE, cp->y);
}

/* stabsym - output a stab entry for symbol p */
static void stabsym(p) Symbol p; {
	int code, tc, sz = p->type->size;

	if (p->generated || p->computed)
		return;
	if (isfunc(p->type)) {
		print(".stabs \"%s:%c%d\",%d,0,0,%s\n", p->name,
			p->sclass == STATIC ? 'f' : 'F', dbxtype(freturn(p->type)),
			N_FUN, p->x.name);
		return;
	}
	if (!IR->wants_argb && p->scope == PARAM && p->structarg) {
		assert(isptr(p->type) && isstruct(p->type->type));
		tc = dbxtype(p->type->type);
		sz = p->type->type->size;
	} else
		tc = dbxtype(p->type);
	if (p->sclass == AUTO && p->scope == GLOBAL || p->sclass == EXTERN) {
		print(".stabs \"%s:G", p->name);
		code = N_GSYM;
	} else if (p->sclass == STATIC) {
		print(".stabs \"%s:%c%d\",%d,0,0,%s\n", p->name, p->scope == GLOBAL ? 'S' : 'V',
			tc, p->u.seg == BSS ? N_LCSYM : N_STSYM, p->x.name);
		return;
	} else if (p->sclass == REGISTER) {
		if (p->scope > PARAM) {
			int r = p->x.regnode->number;
			if (p->x.regnode->set == FREG)
				r += 32;	/* floating point */
			print(".stabs \"%s:r%d\",%d,0,", p->name, tc, N_RSYM);
			print("%d,%d\n", sz, r);
		}
		return;
	} else if (p->scope == PARAM) {
		print(".stabs \"%s:p", p->name);
		code = N_PSYM;
	} else if (p->scope >= LOCAL) {
		print(".stabs \"%s:", p->name);
		code = N_LSYM;
	} else
		assert(0);
	print("%d\",%d,0,0,%s\n", tc, code,
		p->scope >= PARAM && p->sclass != EXTERN ? p->x.name : "0");
}

/* stabtype - output a stab entry for type *p */
static void stabtype(p) Symbol p; {
	if (p->type) {
		if (p->sclass == 0)
			dbxtype(p->type);
		else if (p->sclass == TYPEDEF)
			print(".stabs \"%s:t%d\",%d,0,0,0\n", p->name, dbxtype(p->type), N_LSYM);
	}
}

Interface x86freebsdIR = {
	1, 1, 0,		/* char */
	2, 2, 0,		/* short */
	4, 4, 0,		/* int */
	4, 4, 1,		/* float */
	8, 4, 1,		/* double */
	4, 4, 0,		/* T * */
	0, 1, 0,		/* struct so that ARGB keeps stack aligned */
	1,			/* little_endian */
	0,			/* mulops_calls */
	0,			/* wants_callb */
	1,			/* wants_argb */
	0,			/* left_to_right */
	0,			/* wants_dag */
	address,
	blockbeg,
	blockend,
	defaddress,
	defconst,
	defstring,
	defsymbol,
	emit0,
	export,
	function,
	gen,
	global,
	import,
	local,
	progbeg,
	progend,
	segment,
	space,
	stabblock, 0, 0, stabinit, stabline, stabsym, stabtype,
	{1, blkfetch, blkstore, blkloop,
		_label,
		_rule,
		_nts,
		_kids,
		_opname,
		_arity,
		_string,
		_templates,
		_isinstruction,
		_ntname,
		emit2,
		doarg,
		target,
		clobber,
	}
};
