# ex:ts=8
# Ports collection makefile for:	qgo
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qgo
PORTVERSION=	0.0.11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@freebsd.org

USE_REINPLACE=	yes
USE_QT_VER=	2
GNU_CONFIGURE=	yes
QTCPPFLAGS+=	-DDONT_USE_GETOPT
CONFIGURE_ENV=	QTDIR=${X11BASE}
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,qt.so,qt2.so,g ; \
		s,/moc,/moc2,g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,-lqt,-lqt2,g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
