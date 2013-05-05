# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$
#   $MCom: ports/trunk/devel/desktop-file-utils/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	desktop-file-utils
PORTVERSION=	0.21
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A couple of command line utilities for working with desktop entries

USES=		pkgconfig gettext
USE_GNOME=	glib20
USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lispdir
CONFIGURE_ENV=	EMACS="no"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		desktop-file-edit.1 desktop-file-install.1 \
		desktop-file-validate.1 update-desktop-database.1

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PORT_MIMEDIRS=	${LOCALBASE}/share/applications

MIMEDIRS=	${PORT_MIMEDIRS}

RMDIRS=		${PORT_MIMEDIRS}

post-patch:
	@${SED} -e 's|%%MIMEDIRS%%|${MIMEDIRS}| ;\
		s|%%RMDIRS%%|${RMDIRS}| ; \
		s|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SED} -e 's|%%PORT_MIMEDIRS%%|${PORT_MIMEDIRS}|' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/desktop-entry-mode.el \
	    	${PREFIX}/share/emacs/site-lisp/desktop-entry-mode.el
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
