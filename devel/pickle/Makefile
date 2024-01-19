PORTNAME=	pickle
PORTVERSION=	4.20
CATEGORIES=	devel
MASTER_SITES=	http://wiki.kewl.org/downloads/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Programs Microchip PICs using ICSP
WWW=		https://wiki.kewl.org/dokuwiki/projects:pickle

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		invokes x86 assembler
BROKEN_armv7=		invokes x86 assembler
BROKEN_mips=		invokes x86 assembler
BROKEN_mips64=		invokes x86 assembler

USES=		gmake tar:tgz

ALL_TARGET=	build

PLIST_FILES=	${BIN_SYMLINKS} \
		bin/pctrl  \
		bin/${PORTNAME} \
		bin/pio \
		bin/pload \
		bin/ptest

BIN_SYMLINKS=	bin/n14 \
		bin/n16 \
		bin/p12 \
		bin/p14 \
		bin/p16 \
		bin/p24 \
		bin/p32

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
USES+=		llvm:max=14
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CFLAGS=|CFLAGS+=| ; \
		 s|-ggdb||' ${WRKSRC}/src/Makefile

do-install:
.for i in ${PORTNAME} pio ptest pctrl pload
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/bin/${i})
.endfor
.for i in ${BIN_SYMLINKS}
	${RLN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/${i}
.endfor

.include <bsd.port.mk>
