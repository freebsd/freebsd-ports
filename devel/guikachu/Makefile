# New ports collection makefile for:	guikachu
# Date created:		7 Nov 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guikachu
PORTVERSION=	1.5.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel palm gnome
MASTER_SITES=	http://cactus.rulez.org/projects/guikachu/download/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Resource editor for PalmOS(tm) systems

LIB_DEPENDS=	gnomeuimm-2.6.1:${PORTSDIR}/x11-toolkits/libgnomeuimm26 \
		gnomevfsmm-2.6.1:${PORTSDIR}/devel/gnome-vfsmm

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	guikachu-form-editor.schemas guikachu-interface.schemas

post-patch:
	@${REINPLACE_CMD} -e '/mime_packagedir/s|(mimedir)|(prefix)/share/mime|' \
		-e '/(UPDATE_MIME)/s|(mimedir)|(prefix)/share/mime|' \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
