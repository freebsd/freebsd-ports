# $FreeBSD$

PORTNAME=	libtexluajit
PORTVERSION=	2.0.3
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150521-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	LuaJIT library for TeXLive

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LuaJIT-2.0.3/COPYRIGHT

BROKEN_powerpc64=	Does not build

USES=		tar:xz libtool pkgconfig
USE_LDCONFIG=	yes
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=		build-aux libs/luajit
WRKSRC=		${WRKDIR}/${DISTNAME}/libs/luajit
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
