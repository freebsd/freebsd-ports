# New ports collection makefile for:	pinedit
# Date created:				2011-04-02
# Whom:					Stephen Hurd <shurd@sasktel.net>
#
# $FreeBSD$
#

PORTNAME=	pinedit
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/pinball/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	shurd@sasktel.net
COMMENT=	Editor for Emilia Pinball

BUILD_DEPENDS=	${LOCALBASE}/lib/pinball/libemilia_pin.a:${PORTSDIR}/games/pinball

USE_QT_VER=	3
USE_SDL=	sdl image mixer
USE_GL=		gl
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS=	--prefix=${PREFIX} --without-debug
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/pinball
CPPFLAGS+=	-DRZR_LIBSTATIC

.include <bsd.port.mk>
