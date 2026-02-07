PORTNAME=	libaiff
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read and write AIFF files
WWW=		https://aifftools.sourceforge.net/libaiff/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	mtszb

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
