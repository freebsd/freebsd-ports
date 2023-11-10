PORTNAME=	9e
PORTVERSION=	1.0
CATEGORIES=	archivers
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	9e

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Explode Plan9 archives
WWW=		https://osorio.me/projects/dev/9e/

LICENSE=	LPL
LICENSE_GROUPS=	OSI
LICENSE_NAME=	Lucent Public License
LICENSE_TEXT=	http://opensource.org/licenses/LPL-1.02
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		HDRS="" \
		LIBS=""
PLIST_FILES=	bin/9e

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9e ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
