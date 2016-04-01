# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xmms-sexypsf
PORTVERSION=	0.4.8
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/sexypsf/ \
		LOCAL/ehaupt
DISTNAME=	sexypsf-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS plugin for playing .psf files

BUILD_DEPENDS=	xmms:multimedia/xmms
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		tar:bzip2
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

CFLAGS+=	-I${WRKSRC} -fPIC
DEFINES=	-DSPSFVERSION=\""${PORTVERSION}\"" -DPSS_STYLE=1

PORTDOCS=	ChangeLog README psf_format.txt spu.txt spu2regs.txt \
		system.txt
SOURCES=	PsxBios PsxCounters PsxDma Spu PsxHw PsxMem Misc \
		R3000A PsxInterpreter PsxHLE spu/spu xmms/xmms

PLIST_FILES=	lib/xmms/Input/libsexypsf.so

OPTIONS_DEFINE=DOCS

do-build:
.for f in ${SOURCES}
	${CC} ${CFLAGS} ${DEFINES} `gtk-config --cflags` -c -o ${WRKSRC}/${f}.o ${WRKSRC}/${f}.c
.endfor
	${CC} ${CFLAGS} ${DEFINES} `gtk-config --cflags` ${SOURCES:S/$/.o/:S/^/${WRKSRC}\//} \
		-o ${WRKSRC}/libsexypsf.so -shared -lz

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	${INSTALL_PROGRAM} ${WRKSRC}/libsexypsf.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Input/libsexypsf.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/Docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
