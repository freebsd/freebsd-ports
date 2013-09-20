# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	pharmacy
PORTVERSION=	0.3
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for CVS

LICENSE=	GPLv2

USE_GMAKE=	yes
USES=		pathfix gettext
USE_GNOME=	gnomeprefix gnomelibs
GNU_CONFIGURE=	yes
CPPFLAGS+=	-Wno-return-type
CONFIGURE_ENV+=	CPPCFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|\(DATADIRNAME=\)lib|\1share|g ; \
		s|USE_INCLUDED_LIBINTL=yes|#&|g ; \
		s|\$$(top_builddir)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

.include <bsd.port.mk>
