# Custom Makefile to build all firmware utilities. OpenWrt has its own build
# system for these which would be overkill to replicate here.
#
# $FreeBSD$
#

SIMPLES=	add_header addpattern airlink dgfirmware encode_crc \
	lzma2eva makeamitbin mkcasfw mkchkimg mkcsysimg mkdniimg \
	mkedimaximg mkfwimage mkfwimage2 mkmylofw mktitanimg mktplinkfw \
	mkwrgimg mkzynfw motorola-bin nand_ecc osbridge-crc pc1crypt \
	ptgen spw303v srec2bin trx trx2edips trx2usr wndr3700 xorimage

ALL=	${SIMPLES} buffalo-enc buffalo-tag buffalo-tftp \
	imagetag mkplanexfw mkzcfw wrt400n

OBJS+=	buffalo-lib.o buffalo-enc.o buffalo-tag.o \
	buffalo-tftp.o
OBJS+=	imagetag.o imagetag_cmdline.o
OBJS+=	mkplanexfw.o sha1.o
OBJS+=	mkzcfw.o
OBJS+=	wrt400n.o cyg_crc32.o

LDFLAGS+=	-lmd -lcrypto -lz

INSTALL_PROGRAM?=	echo /usr/bin/install -C -o root -g bin -m 0644
PREFIX?=	/usr/local

all: ${ALL}

install: ${ALL}
	${INSTALL_PROGRAM} ${ALL} ${DESTDIR}${PREFIX}/bin

clean:
	rm -f ${ALL} ${OBJS}

.for i in ${SIMPLES}
${i}: ${i}.c
.endfor

buffalo-enc: buffalo-enc.o buffalo-lib.o
	${CC} -o ${.TARGET} ${LDFLAGS} ${.ALLSRC}

buffalo-tag: buffalo-tag.o buffalo-lib.o
	${CC} -o ${.TARGET} ${LDFLAGS} ${.ALLSRC}

buffalo-tftp: buffalo-tftp.o buffalo-lib.o
	${CC} -o ${.TARGET} ${LDFLAGS} ${.ALLSRC}

imagetag:	imagetag.o imagetag_cmdline.o
	${CC} -o ${.TARGET} ${LDFLAGS} ${.ALLSRC}

mkplanexfw: mkplanexfw.o sha1.o
	${CC} -o ${.TARGET} ${LDFLAGS} ${.ALLSRC}

mkzcfw:	mkzcfw.o cyg_crc32.o
	${CC} -o ${.TARGET} ${LDFLAGS} ${.ALLSRC}

wrt400n:	wrt400n.o cyg_crc32.o
	${CC} -o ${.TARGET} ${LDFLAGS} ${.ALLSRC}
