PORTNAME=	open-beagle
PORTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/beagle/beagle/${PORTVERSION}
DISTNAME=	beagle-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Evolutionary Computation Framework
WWW=		https://beagle.sourceforge.net/

BUILD_DEPENDS+=	gsed:textproc/gsed

USES=		gmake libtool
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimization --with-zlib=/usr

INSTALL_TARGET=	install-strip

CONFLICTS=	beagle

PLIST_SUB=	PORTVERSION=${PORTVERSION} PACCVERSION=${PACCVERSION}

PACCVERSION=	1.3.1b

#unfortunately, some important sed statements rely on GNU sed behavior, and can't be
#easily changed to call GNU sed by means of the configure script
post-configure:
	${FIND} -X ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} \
	's/sed /gsed /g'
	@${REINPLACE_CMD} 's|push_back|this->push_back|' \
		${WRKSRC}/beagle/include/beagle/RouletteT.hpp

.include <bsd.port.mk>
