# New ports collection makefile for:	gnofin
# Date created:				Sun Jul 18 1999
# Whom:					domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	gnofin
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	finance deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light-weight GNOME based financial management program

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnofin.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' \
			${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|_la_LDFLAGS =|_la_LDFLAGS = -avoid-version|g'

.include <bsd.port.mk>
