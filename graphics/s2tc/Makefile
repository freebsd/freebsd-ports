# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s2tc
PORTVERSION=	1.0+20151228
CATEGORIES=	graphics

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Subset of a well-known texture compression scheme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libGL>=9.1.7:graphics/libGL
TEST_DEPENDS=	convert:graphics/ImageMagick \
		nvcompress:graphics/nvidia-texture-tools \
		wget:ftp/wget

USES=		autoreconf libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	divVerent
GH_TAGNAME=	f6ec862
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PATHFIX_MAKEFILEIN=Makefile.am

CPPFLAGS+=	-I${LOCALBASE}/include

do-test:
	(cd ${WRKSRC}/tests; ${SETENV} use_external=false use_nvcompress=true ${SH} test.sh)

.include <bsd.port.mk>
