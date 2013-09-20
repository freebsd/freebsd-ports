# Created by: ijliao
# $FreeBSD$

PORTNAME=	open-beagle
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	SF/beagle/beagle/${PORTVERSION}
DISTNAME=	beagle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Evolutionary Computation Framework

CONFLICTS=	beagle-[0-9]*
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-optimization --with-zlib=/usr
USE_LDCONFIG=	yes
USE_GMAKE=	yes
PACCVERSION=	1.3.1b

PLIST_SUB=	PORTVERSION=${PORTVERSION} PACCVERSION=${PACCVERSION}
BUILD_DEPENDS+=	gsed:${PORTSDIR}/textproc/gsed

#unfortunately, some important sed statements rely on GNU sed behavior, and can't be
#easily changed to call GNU sed by means of the configure script
NO_STAGE=	yes
post-configure:
	${FIND} -X ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} \
	's/sed /gsed /g'
	@${REINPLACE_CMD} 's|push_back|this->push_back|' \
		${WRKSRC}/beagle/include/beagle/RouletteT.hpp

.include <bsd.port.mk>
