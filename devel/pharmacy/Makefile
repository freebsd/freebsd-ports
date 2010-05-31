# New ports collection makefile for:	pharmacy
# Date created:				02 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	pharmacy
PORTVERSION=	0.3
PORTREVISION=	9
CATEGORIES=	devel gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for CVS

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPCFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|\(DATADIRNAME=\)lib|\1share|g ; \
		s|USE_INCLUDED_LIBINTL=yes|#&|g ; \
		s|\$$(top_builddir)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.mk>
