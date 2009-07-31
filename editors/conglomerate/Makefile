# New ports collection makefile for: conglomerate
# Date created:			Jun 26, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	conglomerate
PORTVERSION=	0.9.1
PORTREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	pav@FreeBSD.org
COMMENT=	GNOME2 visual XML editor with emphasis on DocBook editing

INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gtksourceview gnomeprefix gnomehack intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/enchant.pc) || defined(WITH_ENCHANT)
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
.endif

.include <bsd.port.post.mk>
