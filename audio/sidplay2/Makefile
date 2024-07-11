PORTNAME=	sidplay2
PORTVERSION=	2.0.9
PORTREVISION=	5
CATEGORIES=	audio emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sidplay-${PORTVERSION}
DISTNAME=	sidplay-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commodore SID music player using libsidplay2
WWW=		https://sidplay2.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware and superseded by audio/sidplayfp
EXPIRATION_DATE=2024-07-31

LIB_DEPENDS=	libsidplay2.so:audio/libsidplay2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		pkgconfig
USE_CXXSTD=	c++98

PLIST_FILES=	bin/sidplay2 share/man/man1/sidplay2.1.gz

.include <bsd.port.mk>
