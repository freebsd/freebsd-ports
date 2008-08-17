# New ports collection makefile for:   mosh
# Date created:                2008-07-06
# Whom:                        Katsuji ISHIKAWA <katsuji.ishikawa@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mosh
PORTVERSION=	0.0.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	mosh-scheme

MAINTAINER=	katsuji.ishikawa@gmail.com
COMMENT=	A Fast R6RS Scheme interpreter

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+

# Compilation tends to eat extreme amounts of memory otherwise
CFLAGS+=	"-O0"
CXXFLAGS+=	"-O0"

SCMS=		all-tests.scm repl.scm

do-install:
	${MKDIR} ${DATADIR}
.for F in ${SCMS}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DATADIR}/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
