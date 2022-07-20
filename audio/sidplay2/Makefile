PORTNAME=	sidplay2
PORTVERSION=	2.0.9
PORTREVISION=	4
CATEGORIES=	audio emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sidplay-${PORTVERSION}
DISTNAME=	sidplay-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commodore SID music player using libsidplay2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsidplay2.so:audio/libsidplay2

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_CXXSTD=	c++98

PLIST_FILES=	bin/sidplay2 man/man1/sidplay2.1.gz

.include <bsd.port.mk>
