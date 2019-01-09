# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	liballium
PORTVERSION=	0.0.1
CATEGORIES=	devel security

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Tor pluggable transports utility library

LICENSE=	BSD2CLAUSE BSD3CLAUSE PD
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Yawning
GH_TAGNAME=	0c9b50f

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
