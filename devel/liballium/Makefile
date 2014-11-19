# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	liballium
PORTVERSION=	0.0.1
CATEGORIES=	devel security
DISTNAME=	g-${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Tor pluggable transports utility library

USE_GITHUB=	yes
GH_ACCOUNT=	Yawning
GH_COMMIT=	0c9b50f
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pathfix pkgconfig tar:bzip2
PATHFIX_MAKEFILEIN=Makefile.am
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB+=	PKGNAME=${PKGNAME}

OPTIONS_DEFINE=	DOCS TEST

TEST_ALL_TARGET=check

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
