# New ports collection makefile for:	gicq
# Version required:		0.22
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id: Makefile,v 1.3 1998/11/25 22:31:28 sada Exp $
#

DISTNAME=	gicq-0.22
PKGNAME=	ja-gicq-0.22
CATEGORIES=	japanese net
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

PATCH_SITES=	http://flos.kuee.kyoto-u.ac.jp/soft/
PATCHFILES=	gicq-0.22ja.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=	gtkjp.1:${PORTSDIR}/japanese/gtk \
		icq.0:${PORTSDIR}/japanese/libicq

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome --disable-nls
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" LIBS=-lxpg4

post-configure:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${FILESDIR}/wrapper \
	 > ${WRKDIR}/wrapper

post-install:
	@${MV} ${PREFIX}/bin/gicq ${PREFIX}/bin/gicq.bin
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper ${PREFIX}/bin/gicq
	@${INSTALL_DATA} \
		${FILESDIR}/menu.gicq ${PREFIX}/share/ja-gtk/menu/menu.gicq.bin

.include <bsd.port.mk>
