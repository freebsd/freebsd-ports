# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	dxx-rebirth
DISTVERSION=	0.60.0-beta2
CATEGORIES=	games
MASTER_SITES=	https://www.dxx-rebirth.com/download/dxx/user/afuturepilot/
EXTRACT_SUFX=	-git.tar.gz

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Open source port of Descent and Descent 2

LICENSE=	GPLv3 PARALLAX
LICENSE_COMB=	multi
LICENSE_NAME_PARALLAX=	original Parallax license
LICENSE_FILE_GPLv3=	${WRKSRC}/GPL-3.txt
LICENSE_FILE_PARALLAX=	${WRKSRC}/COPYING.txt
LICENSE_PERMS_PARALLAX=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libpng.so:graphics/png

USES=		compiler:c++14-lang localbase:ldflags gl pkgconfig scons
USE_GL=		gl glu
USE_SDL=	mixer sdl

MAKE_ARGS=	ignore_unknown_variables=1

PLIST_FILES=	bin/d1x-rebirth \
		bin/d2x-rebirth

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/d1x-rebirth \
		${STAGEDIR}${PREFIX}/bin/d2x-rebirth

.include <bsd.port.mk>
