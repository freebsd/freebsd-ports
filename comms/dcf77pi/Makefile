# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	3.5.0
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer and library for the Raspberry Pi

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rene0

OPTIONS_DEFINE=	DOXYGEN

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doxygen

USES=		ncurses
USE_LDCONFIG=	yes

PATCH_STRIP=	-p1
PORTDOCS=	README.md
DOXYGEN_PORTDOCS=	html/*

INSTALL_TARGET=	install-strip
DOXYGEN_INSTALL_TARGET=	install-doxygen

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
