# New ports collection makefile for: conglomerate
# Date created:			Jun 26, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	conglomerate
PORTVERSION=	0.7.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	GNOME2 visual XML editor with emphasis on DocBook editing

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gtksourceview gnomeprefix gnomehack
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
