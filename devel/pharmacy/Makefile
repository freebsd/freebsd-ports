# New ports collection makefile for:	pharmacy
# Date created:				02 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	pharmacy
PORTVERSION=	0.2.1a
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	GNOME frontend for CVS

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPCFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|\(DATADIRNAME=\)lib|\1share|g ; \
		s|USE_INCLUDED_LIBINTL=yes|#&|g ; \
		s|\$$(top_builddir)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\(\$$(datadir)/\)gnome/|\1|g ; \
		 s|\$$(datadir)/locale|$$(prefix)/share/locale|g'

.include <bsd.port.mk>
