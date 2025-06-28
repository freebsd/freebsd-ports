PORTNAME=	jday
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomical Julian date calculator
WWW=		https://jday.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	netatal3

PLIST_FILES=	bin/dbd bin/j2d bin/jday include/jday.h lib/libjday.a \
		lib/libjday.so lib/libjday.so.2 lib/libjday.so.2.0.4 \
		libdata/pkgconfig/jday.pc share/man/man1/jday.1.gz

.include <bsd.port.mk>
