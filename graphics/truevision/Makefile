# ex:ts=8
# Ports collection makefile for:	truevision
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	truevision
PORTVERSION=	0.3.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_FLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'
	@${REINPLACE_CMD} -e "s,Bison ,Bison,g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,-lgthread,-lgthread12,g ; \
		s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
