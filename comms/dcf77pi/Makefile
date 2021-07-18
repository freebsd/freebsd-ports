# Created by: rene@FreeBSD.org

PORTNAME=	dcf77pi
PORTVERSION=	3.7.1.1
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	rene0@freedom.nl
COMMENT=	DCF77 receiver/logger/analyzer and library for the Raspberry Pi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rene0
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

PATCH_STRIP=	-p1
PORTDOCS=	CHANGELOG.md README.md receiver.svg

OPTIONS_DEFINE=	DOXYGEN DOCS
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doxygen
DOXYGEN_INSTALL_TARGET=	install-doxygen
DOXYGEN_PORTDOCS=	html/*

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.md # do not install twice
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
