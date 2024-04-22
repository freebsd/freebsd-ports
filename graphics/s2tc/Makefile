PORTNAME=	s2tc
PORTVERSION=	1.0+20151228
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subset of a well-known texture compression scheme
WWW=		https://github.com/divVerent/s2tc/wiki

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libglvnd>=0:graphics/libglvnd
TEST_DEPENDS=	nvcompress:graphics/nvidia-texture-tools \
		wget:ftp/wget

USES=		autoreconf libtool magick:6,test pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	divVerent
GH_TAGNAME=	f6ec862
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include

do-test:
	(cd ${WRKSRC}/tests; ${SETENV} use_external=false use_nvcompress=true ${SH} test.sh)

.include <bsd.port.mk>
