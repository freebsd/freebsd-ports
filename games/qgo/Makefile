# ex:ts=8
# Ports collection makefile for:	qgo
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qgo
PORTVERSION=	0.0.14
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@freebsd.org
COMMENT=	A Go board and SGF editor written with the Qt library

USE_REINPLACE=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
QTCPPFLAGS+=	-DDONT_USE_GETOPT
CONFIGURE_ENV=	QTDIR=${X11BASE}
USE_GMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e "s,libqt.so,libqt-mt.so,; \
		s,-O2, ${CFLAGS} ${PTHREAD_CFLAGS}," ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,-lqt,-lqt-mt ${PTHREAD_LIBS}," ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
