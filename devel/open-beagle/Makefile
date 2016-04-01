# Created by: ijliao
# $FreeBSD$

PORTNAME=	open-beagle
PORTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/beagle/beagle/${PORTVERSION}
DISTNAME=	beagle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Evolutionary Computation Framework

CONFLICTS=	beagle-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimization --with-zlib=/usr
USE_LDCONFIG=	yes
USES=		gmake libtool
INSTALL_TARGET=	install-strip
PACCVERSION=	1.3.1b

PLIST_SUB=	PORTVERSION=${PORTVERSION} PACCVERSION=${PACCVERSION}
BUILD_DEPENDS+=	gsed:textproc/gsed

#unfortunately, some important sed statements rely on GNU sed behavior, and can't be
#easily changed to call GNU sed by means of the configure script
post-configure:
	${FIND} -X ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} \
	's/sed /gsed /g'
	@${REINPLACE_CMD} 's|push_back|this->push_back|' \
		${WRKSRC}/beagle/include/beagle/RouletteT.hpp

.include <bsd.port.mk>
