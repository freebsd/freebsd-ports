PORTNAME=	sdl
PORTVERSION=	1.2.60
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	devel linux
DISTNAME=	sdl12-compat-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.libsdl.org/

LICENSE=	ZLIB

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	sdl20 xorglibs
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}12-compat/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}12-compat

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
