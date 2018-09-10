# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer and library for the Raspberry Pi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libjson-c.so:devel/json-c

OPTIONS_DEFINE=	DOXYGEN DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doxygen

USES=		ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rene0
USE_LDCONFIG=	yes

PATCH_STRIP=	-p1
PORTDOCS=	CHANGELOG.md README.md receiver.svg

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_PORTDOCS=	html/*

INSTALL_TARGET=	install-strip
DOXYGEN_INSTALL_TARGET=	install-doxygen

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.md # do not install twice
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
