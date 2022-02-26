PORTNAME=	libpgf
PORTVERSION=	7.21.7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Progressive Graphics Format (PGF) library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe dos2unix libtool pathfix zip
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

pre-configure:
	@${MKDIR} ${WRKSRC}/m4

.include <bsd.port.mk>
