# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xmms-sexypsf
PORTVERSION=	0.4.8
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/sexypsf/ \
		CRITICAL
DISTNAME=	sexypsf-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS plugin for playing .psf files

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${WRKSRC} -fPIC
DEFINES=	-DSPSFVERSION=\""${PORTVERSION}\"" -DPSS_STYLE=1

PORTDOCS=	ChangeLog README psf_format.txt spu.txt spu2regs.txt \
		system.txt
SOURCES=	PsxBios PsxCounters PsxDma Spu PsxHw PsxMem Misc \
		R3000A PsxInterpreter PsxHLE spu/spu xmms/xmms

PLIST_FILES=	lib/xmms/Input/libsexypsf.so

OPTIONS_DEFINE=DOCS

.include <bsd.port.options.mk>

do-build:
.for f in ${SOURCES}
	${CC} ${CFLAGS} ${DEFINES} `gtk-config --cflags` -c -o ${WRKSRC}/${f}.o ${WRKSRC}/${f}.c
.endfor
	${CC} ${CFLAGS} ${DEFINES} `gtk-config --cflags` ${SOURCES:S/$/.o/:S/^/${WRKSRC}\//} \
		-o ${WRKSRC}/libsexypsf.so -shared -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libsexypsf.so ${PREFIX}/lib/xmms/Input/libsexypsf.so

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/Docs/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
