# ex:ts=8
# Ports collection makefile for:	qgo
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qgo
PORTVERSION=	1.5.4.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-r${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Go board and SGF editor written with the Qt library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_XORG=	x11 ice xext
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/NOOPT/s|^CXXFLAGS=|#CXXFLAGS=|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/templates/*.desktop

.include <bsd.port.mk>
