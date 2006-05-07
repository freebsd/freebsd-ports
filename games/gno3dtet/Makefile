# New ports collection makefile for:	gno3dtet
# Date created:		21 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gno3dtet
PORTVERSION=	1.96.1
CATEGORIES=	games gnome
MASTER_SITES=	http://eseb.net/ftp/gno3dtet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME version of the classic 3D-ified T*tris

EXTRACT_DEPENDS=intltoolize:${PORTSDIR}/textproc/intltool

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui librsvg2
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoheader:259 automake:19 aclocal:19 autoconf:259
ACLOCAL_ARGS=	-I m4 -I ${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a -c -f
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes

run-autotools:: run-autotools-aclocal run-autotools-autoheader \
		run-autotools-automake run-autotools-autoconf

post-extract:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/intltoolize -c -f

post-patch:
	@${REINPLACE_CMD} -e '/LIBTOOL/d ; \
		 s|gnome-games|gno3dtet|g' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|/gnome/help/|/help/|g' \
		${WRKSRC}/xmldocs.make
	@${REINPLACE_CMD} -e 's|/gnome/help/|/help/|g ; \
		 s|datadir)/locale|prefix)/share/locale|g' ${WRKSRC}/src/Makefile.am

pre-configure:
	@${INSTALL_SCRIPT} ${AUTOMAKE_DIR}/mkinstalldirs ${WRKSRC}

post-install:
	${CHOWN} root:games ${PREFIX}/bin/gno3dtet
	${CHMOD} 2555 ${PREFIX}/bin/gno3dtet
	${CHOWN} root:games ${PREFIX}/share/gnome/games/gno3dtet.hof
	${CHMOD} 664 ${PREFIX}/share/gnome/games/gno3dtet.hof

.include <bsd.port.mk>
