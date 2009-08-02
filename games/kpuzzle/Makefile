# New ports collection Makefile for:	kpuzzle
# Date created:				2004-09-02
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpuzzle
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kpuzzle
DISTNAME=	${PORTNAME}-${PORTVERSION}-final

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jigsaw puzzle game for KDE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_AUTOTOOLS=		libtool:22

post-patch:
	${REINPLACE_CMD} -e "s,malloc.h,stdlib.h," \
		${WRKSRC}/src/highscore.cpp ${WRKSRC}/src/kpuzzlegame.cpp

post-install:
	${RM} ${PREFIX}/share/doc/HTML/de/kpuzzle

.include <bsd.port.mk>
