# ex:ts=8
# Ports collection makefile for:	g2c
# Date created:			Mar 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	g2c
PORTVERSION=	0.4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(datadir)/gnome/|\$$(datadir)/|g ; \
		 s|\$$(datadir)/locale|\$$(prefix)/share/locale|g'

.include <bsd.port.post.mk>
