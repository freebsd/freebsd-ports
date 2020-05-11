# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	dxx-rebirth
PORTVERSION=	20200501
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	https://www.dxx-rebirth.com/download/dxx/rebirth/
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source port of Descent and Descent 2

LICENSE=	GPLv3 PARALLAX
LICENSE_COMB=	multi
LICENSE_NAME_PARALLAX=	original Parallax license
LICENSE_FILE_GPLv3=	${WRKSRC}/GPL-3.txt
LICENSE_FILE_PARALLAX=	${WRKSRC}/COPYING.txt
LICENSE_PERMS_PARALLAX=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	as:devel/binutils
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png

USES=		compiler:c++14-lang gl localbase:ldflags pkgconfig scons sdl tar:xz
USE_GL=		gl glu
USE_SDL=	mixer sdl

MAKE_ARGS=	ignore_unknown_variables=1

PLIST_FILES=	bin/d1x-rebirth \
		bin/d2x-rebirth

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/d1x-rebirth \
		${STAGEDIR}${PREFIX}/bin/d2x-rebirth

.include <bsd.port.mk>
