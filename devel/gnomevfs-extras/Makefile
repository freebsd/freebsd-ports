# New ports collection makefile for:	gnomevfs-extras
# Date created:				20 January 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs-extras
PORTVERSION=	0.99.10
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-vfs-extras/0.99
DISTNAME=	gnome-vfs-extras-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	einekoai@chello.nl
COMMENT=	A plugin for gnomevfs2 to browse smb shares with nautilus2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomevfs2
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-rio500
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
