# New ports collection makefile for:	3Dc
# Date created:				2 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		3dc
PORTVERSION=		0.8.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=		3Dc-${PORTVERSION}

MAINTAINER=		adam-ports@blacktabby.org

LIB_DEPENDS=		Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

USE_X_PREFIX=		yes
USE_XPM=		yes
WRKSRC=			${WRKDIR}/3Dc/src

post-patch:
.for file in init.c main.c piece.c stack.c xif.c
	@${PERL} -pi -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/${file}
.endfor

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/3Dc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/3Dc
.for file in 3Dc-rules.html ACKNOWLEDGEMENTS GPL README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/3Dc
.endfor
.endif

.include <bsd.port.mk>
