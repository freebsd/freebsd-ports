# ex:ts=8
# New ports collection makefile for:	qglviewer
# Date created:			Dec 18, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qglviewer
PORTVERSION=	1.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.qglviewer.de/

MAINTAINER=	kde@freebsd.org

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_QT_VER=	2
GNU_CONFIGURE=	yes
QTCPPFLAGS=	${CXXFLAGS} ${PTHREAD_CFLAGS}
QTCFGLIBS=	${PTHREAD_LIBS} -L${X11BASE}/lib -lqtgl
CONFIGURE_ENV=	QTDIR="${X11BASE}"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lqt,-lqt2,g ; \
		s,-lqgl,-lqtgl,g ; \
		s,/moc,/moc2,g" ${WRKSRC}/configure

.include <bsd.port.mk>
