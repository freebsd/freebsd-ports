# New ports collection makefile for:	gicq
# Version required:		0.22
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id$
#

DISTNAME=	gicq-0.22
PKGNAME=	ja-gicq-0.22
CATEGORIES=	japanese net
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

PATCH_SITES=	http://flos.kuee.kyoto-u.ac.jp/soft/
PATCHFILES=	gicq-0.22ja.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.ORG

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	LIBS=-lxpg4

BUILD_DEPENDS=	${LOCALBASE}/lib/libicq.a:${PORTSDIR}/japanese/libicq \
		${X11BASE}/lib/libgtk.a:${PORTSDIR}/japanese/gtk

post-configure:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${FILESDIR}/wrapper \
	 > ${WRKDIR}/wrapper

post-install:
	@${MV} ${PREFIX}/bin/gicq ${PREFIX}/bin/gicq.bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper ${PREFIX}/bin/gicq
	@${INSTALL_DATA} \
		${FILESDIR}/menu.gicq ${PREFIX}/share/ja-gtk/menu/menu.gicq.bin

.include <bsd.port.mk>
