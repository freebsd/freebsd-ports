PORTNAME=	cmt
DISTVERSION=	1.18
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	The Computer Music Toolkit - a collection of LADSPA plugins
WWW=		https://www.ladspa.org/cmt/overview.html

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake tar:tgz

ALL_TARGET=	targets
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	INSTALL_PLUGINS_DIR=${STAGEDIR}${PREFIX}/lib/ladspa/ \
		CFLAGS="${CFLAGS} -fPIC -I${LOCALBASE}/include"
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	lib/ladspa/cmt.so

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa

.include <bsd.port.mk>
