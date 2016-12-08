# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	conglomerate
PORTVERSION=	0.9.1
PORTREVISION=	13
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/Conglomerate%20XML%20Editor/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME2 visual XML editor with emphasis on DocBook editing

INSTALLS_OMF=	yes
USES=		desktop-file-utils gettext-tools gmake pathfix pkgconfig
USE_GNOME=	libgnomeui gtksourceview gnomeprefix intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ENCHANT DOCS

ENCHANT_LIB_DEPENDS=	libenchant.so:textproc/enchant

.include <bsd.port.mk>
