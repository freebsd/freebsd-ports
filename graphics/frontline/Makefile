# New ports collection makefile for:	frontline
# Date created:				12 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frontline
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	http://autotrace.sourceforge.net/frontline/

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	autotrace.2:${PORTSDIR}/graphics/autotrace \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs imlib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
