# New ports collection makefile for:	gnomevfs-extras
# Date created:				20 January 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs-extras
PORTVERSION=	0.99.11
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-vfs-extras/0.99
DISTNAME=	gnome-vfs-extras-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	A plugin for gnomevfs2 to browse smb shares with nautilus2

LIB_DEPENDS=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomevfs2
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-rio500
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
