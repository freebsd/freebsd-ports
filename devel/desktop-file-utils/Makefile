# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$
#   $MCom: ports/trunk/devel/desktop-file-utils/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	desktop-file-utils
PORTVERSION=	0.23
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Couple of command line utilities for working with desktop entries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake gnome localbase:ldflags pkgconfig tar:xz
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lispdir
CONFIGURE_ENV=	EMACS="no"

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PORT_MIMEDIRS=	${LOCALBASE}/share/applications

MIMEDIRS=	${PORT_MIMEDIRS}

post-patch:
	@${SED} -e 's|%%MIMEDIRS%%|${MIMEDIRS}| ;\
		s|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SED} -e 's|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/desktop-entry-mode.el \
		${STAGEDIR}${PREFIX}/share/emacs/site-lisp/desktop-entry-mode.el

.include <bsd.port.mk>
