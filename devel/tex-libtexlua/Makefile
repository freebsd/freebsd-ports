# $FreeBSD$

PORTNAME=	libtexlua
PORTVERSION=	5.2.4
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150521-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Lua library for TeXLive

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/LICENSE.MIT

USES=		tar:xz libtool pathfix pkgconfig
USE_LDCONFIG=	yes
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=		build-aux libs/lua52
WRKSRC=		${WRKDIR}/${DISTNAME}/libs/lua52
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-extract:
	${SED} -e '/\*\ Copyright/,/\*\//!d;s/^\*//;/^\*\*/d' \
	    ${WRKSRC}/lua-5.2.4/src/lua.h > ${WRKDIR}/LICENSE.MIT

.include <bsd.port.mk>
