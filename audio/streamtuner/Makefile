# New ports collection makefile for:	streamtuner
# Date created:			02 Apr 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		streamtuner
PORTVERSION=		0.12.4
CATEGORIES=		audio www
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A GTK+ stream directory browser

BUILD_DEPENDS=		scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS=		curl:${PORTSDIR}/ftp/curl

USE_X_PREFIX=		yes
USE_GNOME=		gtk20 gnomehack gnomeprefix
USE_GMAKE=		yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
