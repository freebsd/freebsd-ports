# New ports collection makefile for:	titano
# Date created:				25 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	titano
PORTVERSION=	0.0.5b
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IDE for GNOME desktop

LIB_DEPENDS=	gtkeditor.0:${PORTSDIR}/x11-toolkits/libgtkeditor

WRKSRC=		${WRKDIR}/${DISTNAME:S/b//}

USE_REINPLACE=	yes
USE_GNOME=	gnomelibs
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile (bad C++ code)"
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'

post-install:
	${MKDIR} ${PREFIX}/share/gnome/pixmaps/titano
	${INSTALL_DATA} ${WRKSRC}/src/xpm/* ${PREFIX}/share/gnome/pixmaps/titano

.include <bsd.port.post.mk>
