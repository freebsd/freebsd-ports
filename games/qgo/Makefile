# ex:ts=8
# Ports collection makefile for:	qgo
# Date created:			Mar 22, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qgo
PORTVERSION=	0.0.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_QT_VER=	2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR=${X11BASE} LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,qt.so,qt2.so,g ; \
		s,/moc,/moc2,g" ${WRKSRC}/configure
	@${PERL} -pi -e "s,-lqt,-lqt2,g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
