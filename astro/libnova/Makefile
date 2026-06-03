PORTNAME=	libnova
DISTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	astro
# Pull from Gentoo repo because upstream stopped tarball releases after v0.15
MASTER_SITES=	https://dev.gentoo.org/~asturm/distfiles/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Astronomical Calculation Library
WWW=		https://libnova.sourceforge.net/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_SUB=	SOVERSION=${DISTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
