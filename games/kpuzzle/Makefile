# New ports collection Makefile for:	kpuzzle
# Date created:				2004-09-02
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kpuzzle
PORTVERSION=	0.4
PORTREVISION=	9
CATEGORIES=	games kde
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-final

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jigsaw puzzle game for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_AUTOTOOLS=		libtool

post-patch:
	${REINPLACE_CMD} -e "s,malloc.h,stdlib.h," \
		${WRKSRC}/src/highscore.cpp ${WRKSRC}/src/kpuzzlegame.cpp

post-install:
	${RM} ${PREFIX}/share/doc/HTML/de/kpuzzle

.include <bsd.port.mk>
