# Created by: Jerry Hicks
# $FreeBSD$

PORTNAME=	9e
PORTVERSION=	1.0
CATEGORIES=	archivers
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	9e

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Explode Plan9 archives

LICENSE=	LPL
LICENSE_GROUPS=	OSI
LICENSE_NAME=	Lucent Public License
LICENSE_TEXT=	http://opensource.org/licenses/LPL-1.02
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

PLIST_FILES=	bin/9e
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="" HDRS=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
