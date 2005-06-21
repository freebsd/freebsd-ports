# New ports collection makefile for: conglomerate
# Date created:			Jun 26, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	conglomerate
PORTVERSION=	0.9.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	GNOME2 visual XML editor with emphasis on DocBook editing

USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui gtksourceview gnomeprefix gnomehack intlhack
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/libdata/pkgconfig/enchant.pc) || defined(WITH_ENCHANT)
LIB_DEPENDS+=	enchant.2:${PORTSDIR}/textproc/enchant
.endif

post-install:
	${MKDIR} ${PREFIX}/share/gnome/${PORTNAME}/help
	${LN} -sf ${PREFIX}/share/gnome/help/${PORTNAME} ${PREFIX}/share/gnome/${PORTNAME}/help/${PORTNAME}

.include <bsd.port.post.mk>
