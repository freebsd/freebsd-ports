# New ports collection makefile for:	genius
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	genius
PORTVERSION=	1.0.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME \
		http://ftp.5z.com/pub/genius/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

LIB_DEPENDS=	mpfr.3:${PORTSDIR}/math/mpfr

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gtksourceview2 intlhack libgnomeui vte
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-extra-gcc-optimization
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

.include <bsd.port.mk>
