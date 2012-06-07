# New ports collection makefile for:	libclaw
# Date created:		28 Mar 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	libclaw
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ Library Absolutely Wonderful

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${LOCALBASE}/include/boost/bind.hpp:${PORTSDIR}/devel/boost-libs

USE_CMAKE=	yes
CMAKE_ARGS=	-DCLAW_CMAKE_MODULES_INSTALL_PATH="${DATADIR}/cmake"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
USE_GETTEXT=	yes
USE_GCC=	4.6+

post-patch:
	@${REINPLACE_CMD} -e '/subdirs/ s|doc||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/install.*COPYING/ d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
