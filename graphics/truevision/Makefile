# ex:ts=8
# Ports collection makefile for:	truevision
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	truevision
PORTVERSION=	0.3.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GTK=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_FLAGS}
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e "s,Bison ,Bison,g" ${WRKSRC}/configure
	@${PERL} -pi -e "s,-lgthread,-lgthread12,g ; \
		s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
