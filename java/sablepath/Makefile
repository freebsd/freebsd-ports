# New ports collection makefile for:    sablepath
# Date created:         		9 July 2002
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sablepath
PORTVERSION=	0.1.3
CATEGORIES=	java
MASTER_SITES=	http://unc.dl.sourceforge.net/sablevm/

MAINTAINER=	archie@freebsd.org

LIB_DEPENDS=	gmp.5:${PORTSDIR}/math/libgmp4
BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes

PATCH_STRIP=	-p1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-build:
	jikes -classpath ${WRKSRC}:${WRKSRC}/vm/sablevm -nowarn +OLDCSO +P \
	    -d ${WRKSRC}/classes `find ${WRKSRC} -name '*.java'`

post-install:
	[ -d ${PREFIX}/share/sablepath ] || ${MKDIR} ${PREFIX}/share/sablepath
	${CP} -R ${WRKSRC}/classes/java ${WRKSRC}/classes/gnu \
	    ${WRKSRC}/classes/org ${PREFIX}/share/sablepath

.include <bsd.port.mk>
