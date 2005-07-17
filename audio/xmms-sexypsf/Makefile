# New ports collection makefile for:	xmms-sexypsf
# Date created:				10 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xmms-sexypsf
PORTVERSION=	0.4.7
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/sexypsf/
DISTNAME=	sexypsf-${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	XMMS plugin for playing .psf files

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12

WRKSRC=		${WRKDIR}/sexypsf

CFLAGS+=	-I${WRKSRC} -fPIC
DEFINES=	-DSPSFVERSION=\""${PORTVERSION}\"" -DPSS_STYLE=1

PORTDOCS=	ChangeLog README psf_format.txt spu.txt spu2regs.txt \
		system.txt
SOURCES=	PsxBios PsxCounters PsxDma Spu PsxHw PsxMem Misc \
		R3000A PsxInterpreter PsxHLE spu/spu xmms/xmms

PLIST_FILES=	lib/xmms/Input/libsexypsf.so

do-build:
.for f in ${SOURCES}
	${CC} ${CFLAGS} ${DEFINES} `gtk-config --cflags` -c -o ${WRKSRC}/${f}.o ${WRKSRC}/${f}.c
.endfor
	${CC} ${CFLAGS} ${DEFINES} `gtk-config --cflags` ${SOURCES:S/$/.o/:S/^/${WRKSRC}\//} \
		-o ${WRKSRC}/libsexypsf.so -shared -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libsexypsf.so ${PREFIX}/lib/xmms/Input/libsexypsf.so

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/Docs/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
