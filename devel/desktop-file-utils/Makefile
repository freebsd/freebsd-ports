# New ports collection makefile for:	desktop-file-utils
# Date created:			11 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		desktop-file-utils
PORTVERSION=		0.10
CATEGORIES=		devel
MASTER_SITES=		http://freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A couple of command line utilities for working with desktop entries

LIB_DEPENDS=		popt:${PORTSDIR}/devel/popt

USE_GNOME=		glib20
WANT_GNOME=		yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=		--with-lispdir=${PREFIX}/share/emacs/site-lisp
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

PKGDEINSTALL=		${WRKDIR}/pkg-deinstall

MIMEDIRS=		${X11BASE}/share/applications \
			${LOCALBASE}/share/applications \
			/usr/share/applications \
			${X11BASE}/share/gnome/applications \
			${LOCALBASE}/share/gnome/applications \
			/usr/share/gnome/applications

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/eggdirfuncs.c
	@${SED} -e 's|%%MIMEDIRS%%|${MIMEDIRS}|' \
		< ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}

post-install:
.if !defined(PACKAGE_BUILDING)
	-@${PREFIX}/bin/update-desktop-database -q
.endif

.include <bsd.port.mk>
