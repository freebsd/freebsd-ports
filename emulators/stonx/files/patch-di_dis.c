--- STonX-0.6.7.6.orig/di_dis.c	2004-08-15 14:33:40.000000000 +0200
+++ di_dis.c	2004-12-25 15:21:15.000000000 +0100
@@ -76,7 +76,6 @@
 
 static const OP_DEF table[] = {
 	"ABCD",0xc100,0xf1f0,type_14,
-	"ADD",0xd000,0xf000,type_3,		/*	add, adda	*/
 
 	"RESET",0x4e70,0xffff,type_10,
 	"RTE",0x4e73,0xffff,type_10,
@@ -105,12 +104,12 @@
 	"NBCD",0x4800,0xffc0,type_15,
 	"PEA",0x4840,0xffc0,type_5,
 
+	"CHK",0x4180,0xf1c0,type_16,
+	"LEA",0x41c0,0xf1c0,type_2,
 	"EXT",0x4800,0xfe30,type_12,
 
 	"MOVEM",0x4880,0xfb80,type_23,
 
-	"CHK",0x4180,0xf1c0,type_16,
-	"LEA",0x41c0,0xf1c0,type_2,
 
 	"TST",0x4a00,0xff00,type_7,
 	"CLR",0x4200,0xff00,type_15,
@@ -152,13 +151,13 @@
 	"SVC",0x58c0,0xffc0,type_5,
 	"SVS",0x59c0,0xffc0,type_5,
 	"ADDQ",0x5000,0xf100,type_6,
-	"ADDX",0xd000,0xf130,type_14,
-	"EXG",0xc100,0xf130,type_18,
+	"ADDA",0xd0c0,0xf0c0,type_3,   /* ADDA can look like a ADDX! */
+	"ADDX",0xd100,0xf130,type_14,
+	"ADD",0xd000,0xf000,type_3,		/*	add, adda	*/
 	"MULS",0xc1c0,0xf1c0,type_16,
 	"MULU",0xc0c0,0xf1c0,type_16,
+	"EXG",0xc100,0xf130,type_18,
 	"AND",0xc000,0xf000,type_3,
-	"ASL",0xe100,0xf118,type_11,
-	"ASR",0xe000,0xf118,type_11,
 	"BCC",0x6400,0xff00,type_8,
 	"BCS",0x6500,0xff00,type_8,
 	"BEQ",0x6700,0xff00,type_8,
@@ -175,15 +174,14 @@
 	"BVS",0x6900,0xff00,type_8,
 	"BRA",0x6000,0xff00,type_8,
 	"BSR",0x6100,0xff00,type_8,
+	"CMPA",0xb0c0,0xf0c0,type_3,	/*	cmpa	*/
 	"CMPM",0xb108,0xf138,type_19,
+	"EOR",0xb100,0xf100,type_3,
 	"CMP",0xb000,0xf000,type_3,	/*	cmp,cmpa	*/
 	"DIVS",0x81c0,0xf1c0,type_16,
 	"DIVU",0x80c0,0xf1c0,type_16,
-	"EOR",0xd000,0xf000,type_3,
-	"LSR",0xe008,0xf118,type_11,
-	"LSR",0xe2c0,0xffc0,type_11,
-	"LSL",0xe108,0xf118,type_11,
-	"LSL",0xe3c0,0xffc0,type_11,
+	"MOVEA.W",0x3040,0xf1c0,type_4,
+	"MOVEA.L",0x2040,0xf1c0,type_4,
 	"MOVE.B",0x1000,0xf000,type_4,
 	"MOVE.W",0x3000,0xf000,type_4,
 	"MOVE.L",0x2000,0xf000,type_4,
@@ -196,10 +194,10 @@
 	"%6lx   EORI   #$%x,SR",0x0a7c,0xffff,type_27,
 	"%6lx   ANDI   #$%x,CCR",0x023c,0xffff,type_27,	/*	ANDI #<data>,CCR	*/
 	"%6lx   ANDI   #$%x,SR",0x027c,0xffff,type_27,	/*	ANDI #data,SR		*/
-	"%6lx   MOVEP.W  %x(%s),%s",0x0108,0xf1f8,type_29,
-	"%6lx   MOVEP.W   %s,%x(%s)",0x0188,0xf1f8,type_29,
-	"%6lx   MOVEP.L  %x(%s),%s",0x0148,0xf1f8,type_29,
-	"%6lx   MOVEP.L   %s,%x(%s)",0x01c8,0xf1f8,type_29,
+	"%6lx   MOVEP.W  $%x(%s),%s",0x0108,0xf1f8,type_29,
+	"%6lx   MOVEP.W   %s,$%x(%s)",0x0188,0xf1f8,type_29,
+	"%6lx   MOVEP.L  $%x(%s),%s",0x0148,0xf1f8,type_29,
+	"%6lx   MOVEP.L   %s,$%x(%s)",0x01c8,0xf1f8,type_29,
 	"BTST",0x0800,0xffc0,type_20,
 	"BSET",0x08c0,0xffc0,type_20,
 	"BCHG",0x0840,0xffc0,type_20,
@@ -216,14 +214,23 @@
 	"BCHG",0x0140,0xf1c0,type_21,
 	"BCLR",0x0180,0xf1c0,type_21,
 
+	"ASR",0xe0c0,0xffc0,type_11,
+	"ASL",0xe1c0,0xffc0,type_11,
+	"LSR",0xe2c0,0xffc0,type_11,
+	"LSL",0xe3c0,0xffc0,type_11,
+	"ROXR",0xe4c0,0xffc0,type_11,
+	"ROXL",0xe5c0,0xffc0,type_11,
+	"ROR",0xe6c0,0xffc0,type_11,
+	"ROL",0xe7c0,0xffc0,type_11,
+	"ASR",0xe000,0xf118,type_11,
+	"ASL",0xe100,0xf118,type_11,
+	"LSR",0xe008,0xf118,type_11,
+	"LSL",0xe108,0xf118,type_11,
 	"ROL",0xe118,0xf118,type_11,
 	"ROR",0xe018,0xf118,type_11,
-	"ROL",0xe7c0,0xffc0,type_11,
-	"ROR",0xe6c0,0xffc0,type_11,
 	"ROXL",0xe110,0xf118,type_11,
 	"ROXR",0xe010,0xf118,type_11,
-	"ROXL",0xe5c0,0xffc0,type_11,
-	"ROXR",0xe4c0,0xffc0,type_11,
+
 	"SUBQ",0x5100,0xf100,type_6,
 	"SUBA",0x90c0,0xf0c0,type_3,   /* SUBA can look like a SUBX! */
 	"SUBX",0x9100,0xf130,type_14,
@@ -237,7 +244,9 @@
 static const char *data_regs[] = {
 	"D0","D1","D2","D3","D4","D5","D6","D7"};
 
-static const char *sizes[] = {".B",".W",".L"};
+static const char *sizes[] = {".B",".W",".L",".?"};
+
+static const char *unknown = "??";
 
 void *dis(void *c,char *s)
 {
@@ -309,7 +318,7 @@
 	ULONG adr;
 /*	WORD data;	*/
 
-	adr = LM_UL(MEM(c));
+	adr = (long) c;
         c++;
 	sprintf(s,table[index].op,adr,LM_UW(MEM(c)));
 	return(++c);
@@ -524,7 +533,14 @@
 	adr = (long)c;
 	dest_reg = (LM_UW(MEM(c)) & 0x0e00) >> 9;	/*	get destination reg	*/
 	source = LM_UW(MEM(c)) & 0x3f;				/*	this is an effective address	*/
-	c = effective_address(c,e_a,source,index,0);	/*	do effective address	*/
+	if (0x0100 == (LM_UW(MEM(c)) & 0xf1c0))
+	{
+		c = effective_address(c,e_a,source,index,BYTE_SIZE);	/*	do effective address for BTST (special for BTST Dn,#)	*/
+	}
+	else
+	{
+		c = effective_address(c,e_a,source,index,0);	/*	do effective address	*/
+	}
 	sprintf(s,"%6lx   %s  %s,%s",adr,table[index].op,data_regs[dest_reg],e_a);
 	++c;
 	return(c);
@@ -575,7 +591,7 @@
 	const char *rx,*ry;
 
 	adr = (long)c;
-	dest = LM_UL(MEM(c)) & 0x07;
+	dest = LM_UW(MEM(c)) & 0x07;
 	source = (LM_UW(MEM(c)) & 0x0e00) >> 9;
 	op_mode = (LM_UW(MEM(c)) & 0xf8) >> 3;
 	if(op_mode == 0x08)
@@ -593,6 +609,11 @@
 		rx = data_regs[source];
 		ry = adr_regs[dest];
 	}
+	else
+	{
+		rx = unknown;
+		ry = unknown;
+	}
 	sprintf(s,"%6lx   %s  %s,%s",adr,table[index].op,rx,ry);
 	++c;
 	return(c);
@@ -693,7 +714,7 @@
 	}
 	else
 	{
-		il_data = LM_UL(MEM(c));
+		il_data = LM_UW(MEM(c));
 	}
 	c = effective_address(c,e_a,dest,index,0);
 	sprintf(s,"%6lx   %s%s  #$%lx,%s",adr,table[index].op,sizes[size],il_data,e_a);
@@ -731,7 +752,7 @@
 	size = (LM_UW(MEM(c)) & 0x0c0) >> 6;
 	if(size < 3)	/*	register shifts	*/
 	{
-		type = (LM_UW(MEM(c)) & 0x100) >> 8;
+		type = (LM_UW(MEM(c)) & 0x20) >> 5;
 		dest = (LM_UW(MEM(c)) & 0x07);
 		count = (LM_UW(MEM(c)) & 0x0e00)>>9;
 		if(type)
@@ -796,9 +817,9 @@
 	else
 	{
 		size = ".S";
-		displacement = (UWORD)( (WORD)( (char)displacement) );
+		displacement = (UWORD)( (WORD)( (char)displacement) + 2 );
 	}
-	dest = (long)c + (long)((WORD)displacement) + 2l;
+	dest = (long)c + (long)((WORD)displacement);
 	sprintf(s,"%6lx   %s%s  $%lx",adr,table[index].op,size,dest);
 	++c;
 	return(c);
@@ -952,7 +973,7 @@
 	adr = (long)c;
 	the_reg = LM_UW(MEM(c)) & 0x07;	/*	get register number	*/
 	++c;	                /*	point to word displacement	*/
-	sprintf(s,"%6lx   %s  %s,#$%x",adr,table[index].op,adr_regs[the_reg],*c);
+	sprintf(s,"%6lx   %s  %s,#$%x",adr,table[index].op,adr_regs[the_reg],LM_UW(MEM(c)));
 	++c;
 	return(c);
 }
@@ -1043,7 +1064,7 @@
 			displacement = LM_UW(MEM(a)) & 0xff;
 			index_reg = (LM_UW(MEM(a)) & 0x7000) >> 12;
 			index_reg_ind = (LM_UW(MEM(a)) & 0x8000)>> 15;
-			index_size = (LM_UW(MEM(a)) & 0x8000) >> 11;
+			index_size = (LM_UW(MEM(a)) & 0x0800) >> 11;
 			if(index_size)
 			{
 				s1 = ".L";
@@ -1082,15 +1103,15 @@
 				case 2:	/*	program counter with displacement	*/
 					++a;
 					displacement = LM_UW(MEM(a));
-					a1 = (long)a + (long)displacement;
-					sprintf(s,"%lx(PC)",a1);
+					a1 = (long)a + (long)((WORD)displacement);
+					sprintf(s,"$%lx(PC)",a1);
 					break;
 				case 3:
 					++a;
 					a1 = (long)((char)(LM_UW(MEM(a)) & 0xff));
 					index_reg = (LM_UW(MEM(a)) & 0x7000) >> 12;
 					index_reg_ind = (LM_UW(MEM(a)) & 0x8000)>> 15;
-					index_size = (LM_UW(MEM(a)) & 0x8000) >> 11;
+					index_size = (LM_UW(MEM(a)) & 0x0800) >> 11;
 					a1 += (long)a;
 					if(index_size)
 					{
@@ -1134,6 +1155,11 @@
 							sprintf(s,"#$%x.B",displacement);
 					}
 					break;
+				case 5:
+				case 6:
+				case 7:
+					sprintf (s, "%s", unknown);
+					break;
 			default:
 			  {
 			    fprintf(stderr,"Overun decode!\n");
