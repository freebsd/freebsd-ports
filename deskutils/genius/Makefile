# New ports collection makefile for:	genius
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	genius
PORTVERSION=	0.5.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://ftp.5z.com/pub/genius/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4 \
		intl.4:${PORTSDIR}/devel/gettext \
		popt.0:${PORTSDIR}/devel/popt

USE_PERL5_BUILD=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20 gconf2 libgnome libgnomeui vte
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
