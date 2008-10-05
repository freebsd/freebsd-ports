# New ports collection makefile for:	giggle
# Date created:		2008-10-01
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	giggle
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://ftp.imendio.com/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	pub/imendio/giggle/src

MAINTAINER=	wahjava@gmail.com
COMMENT=	GTK+ frontend for git version control system

BUILD_DEPENDS=	git:${PORTSDIR}/devel/git
RUN_DEPENDS=	git:${PORTSDIR}/devel/git

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 gtksourceview2 libglade2
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
