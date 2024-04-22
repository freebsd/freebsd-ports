PORTNAME=       dcf77pi
PORTVERSION=    3.7.1.1
DISTVERSIONPREFIX=      v
PORTREVISION=   2
CATEGORIES=     comms
MASTER_SITES=   https://codeberg.org/rene0/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=     rene@FreeBSD.org
COMMENT=        DCF77 receiver/logger/analyzer and library for the Raspberry Pi
WWW=            https://codeberg.org/rene0/dcf77pi

LICENSE=        BSD2CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE.md

LIB_DEPENDS=    libjson-c.so:devel/json-c

USES=           ncurses pkgconfig
USE_LDCONFIG=   yes
WRKSRC=		${WRKDIR}/${PORTNAME}

INSTALL_TARGET= install-strip

PATCH_STRIP=    -p1
PORTDOCS=       CHANGELOG.md README.md receiver.svg

OPTIONS_DEFINE=         DOCS DOXYGEN
DOXYGEN_IMPLIES=        DOCS
DOXYGEN_BUILD_DEPENDS=  doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=     all doxygen
DOXYGEN_INSTALL_TARGET= install-doxygen
DOXYGEN_PORTDOCS=       html/*

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.md # do not install twice
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
