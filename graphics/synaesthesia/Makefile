# New ports collection makefile for:	synaesthesia
# Date created:				25 May 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	synaesthesia
PORTVERSION=	2.1
CATEGORIES=	graphics
MASTER_SITES=	http://yoyo.cc.monash.edu.au/~pfh/

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl10

USE_GMAKE=	Yes
USE_X_PREFIX=	Yes

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/synaesthesia ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/synaesthesia
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/synaesthesia
.endif

.include <bsd.port.mk>
