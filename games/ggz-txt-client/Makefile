# ex:ts=8
# Ports collection makefile for:	ggz-txt-client
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-txt-client
PORTVERSION=	0.0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Console (Text) Frontend

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext \
		ggz.1:${PORTSDIR}/games/libggz \
		ggzcore.3:${PORTSDIR}/games/ggz-clientp-libs

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--disable-debug

MAN6=	ggz-txt.6

.include <bsd.port.mk>
