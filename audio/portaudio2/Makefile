# Created by: michaelnottebrock@gmx.net and lioux@FreeBSD.org
# $FreeBSD$

PORTNAME=	portaudio
PORTVERSION=	19.20111121
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	pa_stable_v${DISTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Portable cross-platform Audio API

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=PKG_CONFIG_LIBDIR=${PREFIX}/libdata/pkgconfig \
			--without-alsa \
			--libdir=${PREFIX}/lib/${PORTNAME}2 \
			--includedir=${PREFIX}/include/${PORTNAME}2

USE_GMAKE=	yes
USE_DOS2UNIX=	yes
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}2

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt index.html

OPTIONS_DEFINE=	DOCS EXAMPLES JACK PATEST DOXYGEN
OPTIONS_DEFAULT=PATEST DOXYGEN

PATEST_DESC=	PortAudio Test Programs
DOXYGEN_DESC=	Install API documentation (requires DOCS)
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

.if ${PORT_OPTIONS:MJACK}
CONFIGURE_ARGS+=--with-jack
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=--without-jack
.endif

.if ${PORT_OPTIONS:MPATEST}
PLIST_SUB+=	PATEST=""
.else
PLIST_SUB+=	PATEST="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#include <malloc.h>|#include <stdlib.h>|' ${WRKSRC}/ltmain.sh
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' ${WRKSRC}/configure.in \
		${WRKSRC}/src/hostapi/oss/pa_unix_oss.c ${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e 's|PACKAGE_NAME=|PACKAGE_NAME=portaudio2|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MPATEST}
	@(cd ${WRKSRC}/bin && for i in *; do ${MV} "$$i" "$${i}"-2; done)
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MDOXYGEN} && ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC} && doxygen
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
