PORTNAME=	pickle
DISTVERSION=	5.01
CATEGORIES=	devel
MASTER_SITES=	LOCAL/bofh/devel/${PORTNAME}

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

ALL_TARGET=	freebsd

PLIST_FILES=	${BIN_SYMLINKS} \
		bin/${PORTNAME}

BIN_SYMLINKS=	bin/n14 \
		bin/n16 \
		bin/p12 \
		bin/p14 \
		bin/p16

WRKSRC=	${WRKDIR}/${PORTNAME}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=		llvm:max=14
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CFLAGS=|CFLAGS+=| ; \
		 s|-ggdb||' ${WRKSRC}/src/Makefile

do-install:
	(cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME})
.for i in ${BIN_SYMLINKS}
	${RLN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/${i}
.endfor

.include <bsd.port.mk>
