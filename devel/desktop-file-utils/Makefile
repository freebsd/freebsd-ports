# New ports collection makefile for:	desktop-file-utils
# Date created:			11 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		desktop-file-utils
PORTVERSION=		0.7
CATEGORIES=		devel
MASTER_SITES=		http://freedesktop.org/Software/desktop-file-utils/releases/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A couple of command line utilities for working with desktop entries

LIB_DEPENDS=		popt:${PORTSDIR}/devel/popt

# This port contains no X program but it might install a GnomeVFS
# module and thus we need to use the same prefix as GnomeVFS.
USE_X_PREFIX=		yes

USE_GNOME=		glib20
WANT_GNOME=		yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=	15

CONFIGURE_ARGS=		--with-lispdir=${PREFIX}/share/emacs/site-lisp
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomevfs2} != ""
USE_GNOME+=		gnomevfs2
PLIST_SUB+=		GNOME_VFS=""
.else
PLIST_SUB+=		GNOME_VFS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/eggdirfuncs.c

post-install:
.if !defined(PACKAGE_BUILDING)
	-@${PREFIX}/bin/update-desktop-database -q
.endif

.include <bsd.port.post.mk>
