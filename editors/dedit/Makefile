# New ports collection makefile for:   dedit
# Version required:    0.5.6
# Date created:        26 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	dedit_0.5.6
PKGNAME=	dedit-0.5.6
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.debian.org/debian/dists/unstable/main/source/editors/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	iconv.0:${PORTSDIR}/converters/iconv \
		gnome.3:${PORTSDIR}/x11/gnomelibs

WRKSRC=		${WRKDIR}/dedit-0.5.6

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASSE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		dedit.1 dedit.ja.1

pre-configure:
		( cd ${WRKSRC}; ${SH} bootstrap )

.include <bsd.port.mk>
