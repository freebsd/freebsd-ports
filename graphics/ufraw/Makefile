# New ports collection makefile for:    UFRaw gimp plugin
# Date created:         		Sun 10 Apr 2005 14:44:15 BST
# Whom:                 		markm@FreeBSD.org
#
# $FreeBSD$

PORTNAME=		gimp-ufraw
PORTVERSION=		0.6
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ufraw
DISTNAME=		ufraw-${PORTVERSION}

MAINTAINER=		markm@FreeBSD.org
COMMENT=		GIMP plug-in for raw digital camera image importing

BUILD_DEPENDS=		gimp:${PORTSDIR}/graphics/gimp
LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			tiff.4:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=		yes
USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_GNOME=		glib20 gnomehack intltool intlhack gtk20 libartlgpl2
WANT_GNOME=		yes

CONFIGURE_ENV=		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
			CFLAGS="${CFLAGS} -I ${LOCALBASE}/include"

MAN1=			ufraw.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 504105
BROKEN=			"Needs memmem(3)"
.endif

.include <bsd.port.post.mk>
