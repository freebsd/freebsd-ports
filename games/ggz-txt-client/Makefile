# ex:ts=8
# Ports collection makefile for:	ggz-txt-client
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-txt-client
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Console (Text) Frontend

LIB_DEPENDS=	ggz.1:${PORTSDIR}/games/libggz \
		ggzcore.3:${PORTSDIR}/games/ggz-client-libs

USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

MAN6=	ggz-txt.6

.include <bsd.port.mk>
