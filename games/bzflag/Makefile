# New ports collection makefile for: bzflag
# Date created:		2000/08/12
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	bzflag
PORTVERSION=	2.4.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	A multiplayer 3D tank battle game

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_SDL=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS} -I ${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS}

MAN5=	bzw.5
MAN6=	bzadmin.6 bzflag.6 bzfs.6

.include <bsd.port.mk>
