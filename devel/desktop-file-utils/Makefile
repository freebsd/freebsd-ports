# New ports collection makefile for:	desktop-file-utils
# Date created:			11 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		desktop-file-utils
PORTVERSION=		0.10
PORTREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=		gnome@FreeBSD.org
COMMENT=		A couple of command line utilities for working with desktop entries

LIB_DEPENDS=		popt:${PORTSDIR}/devel/popt

USE_GNOME=		glib20
WANT_GNOME=		yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=		--with-lispdir=${PREFIX}/share/emacs/site-lisp
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

PKGINSTALL=		${WRKDIR}/pkg-install
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall

PORT_MIMEDIRS=		${X11BASE}/share/applications \
			${LOCALBASE}/share/applications \
			${X11BASE}/share/gnome/applications \
			${LOCALBASE}/share/gnome/applications

MIMEDIRS=		${PORT_MIMEDIRS} \
			/usr/share/applications \
			/usr/share/gnome/applications

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/eggdirfuncs.c
	@${SED} -e 's|%%MIMEDIRS%%|${MIMEDIRS}| ;\
		s|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SED} -e 's|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
