# New ports collection makefile for:   gngb
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gngb
PORTVERSION=	20010318
CATEGORIES=	emulators
MASTER_SITES=	http://frogus.multimania.com/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_X_PREFIX=	yes

post-patch:
		perl -pi -e 's/<SDL\//<SDL11\//' ${WRKSRC}/*.[ch]

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gngb ${PREFIX}/bin

.include <bsd.port.mk>
