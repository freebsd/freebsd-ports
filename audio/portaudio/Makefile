# Created by: michaelnottebrock@gmx.net and lioux@FreeBSD.org
# $FreeBSD$

PORTNAME=	portaudio
PORTVERSION=	18.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Portable cross-platform Audio API

LICENSE=	MIT

USES=		gmake
USE_ZIP=	yes
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_CFLAGS}

PLIST_SUB+=	SHLIB_VERSION=${SHLIB_VERSION}
SHLIB_VERSION=	0

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt index.html

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	*.html *.txt *.pdf

OPTIONS_DEFINE=		PATEST
OPTIONS_DEFAULT=	PATEST

PATEST_DESC=	PortAudio Test Programs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPATEST}
PLIST_SUB+=	PATEST=""
.else
PLIST_SUB+=	PATEST="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#include <malloc.h>|#include <stdlib.h>|' ${WRKSRC}/pa_unix_oss/pa_unix.h
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' ${WRKSRC}/pa_unix_oss/pa_unix_oss.c
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure ${WRKSRC}/configure.in \
		${WRKSRC}/pa_unix_oss/Makefile

pre-configure:
	@${CHMOD} +x ${WRKSRC}/configure

post-install:
	@${LN} -sf libportaudio.so \
		${PREFIX}/lib/libportaudio.so.${SHLIB_VERSION}
.if ${PORT_OPTIONS:MPATEST}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
