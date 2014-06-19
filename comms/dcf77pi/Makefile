# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	3.0.0.1
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer and library for the Raspberry Pi

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	92c359d

USES=		ncurses

PORTDOCS=	README.md

INSTALL_TARGET=	install-strip

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
