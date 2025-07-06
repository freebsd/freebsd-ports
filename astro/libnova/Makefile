PORTNAME=	libnova
DISTVERSION=	0.16.0
CATEGORIES=	astro
MASTER_SITES=	https://sourceforge.net/code-snapshots/git/l/li/${PORTNAME}/${PORTNAME}.git/
DISTNAME=	${PORTNAME}-${PORTNAME}-${GIT_HASH}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Astronomical Calculation Library
WWW=		https://libnova.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool zip
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_SUB=	SOVERSION=${DISTVERSION:R}

GIT_HASH=	edbf65abe27ef1a2520eb9e839daaf58f15a6941

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
