# New ports collection makefile for:	gIDE
# Version required:			0.1.6
# Date created:				29 Jul 1998
# Whom:					rom
#
# $FreeBSD$
#

DISTNAME= 	gIDE-0.1.6
PKGNAME= 	gide-0.1.6
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gIDE

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnomeui.3:${PORTSDIR}/x11/gnomelibs \
		guile.6:${PORTSDIR}/lang/guile

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}

MAN1=		gide.1 gdbio.1

post-patch:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/*.c
	@${PERL} -pi -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/src/*.c

.include <bsd.port.mk>
