# New ports collection makefile for:	gnofin
# Date created:				Sun Jul 18 1999
# Whom:					domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	gnofin
PORTVERSION=	0.8.4
CATEGORIES=	deskutils gnome finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light-weight GNOME based financial management program

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gnofin.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		-e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
		-e 's|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|' \
		-e 's|$$(top_builddir)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|$$(datadir)/gnome/|$$(datadir)/|g' \
		-e ' s|$$(datadir)/locale|$$(prefix)/share/locale|g'
	@{FIND} ${WRKSRC}/plugins -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|_la_LDFLAGS =|_la_LDFLAGS = -avoid-version|g'

.include <bsd.port.mk>
