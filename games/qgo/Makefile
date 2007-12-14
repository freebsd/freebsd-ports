# ex:ts=8
# Ports collection makefile for:	qgo
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qgo
PORTVERSION=	1.5.4.2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-r${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Go board and SGF editor written with the Qt library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g' ${WRKSRC}/templates/*.desktop

.include <bsd.port.mk>
