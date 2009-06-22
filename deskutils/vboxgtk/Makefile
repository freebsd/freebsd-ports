# New ports collection makefile for:	vboxgtk
# Date created:				13 June 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vboxgtk
PORTVERSION=	0.4.1
CATEGORIES=	deskutils emulators gnome
MASTER_SITES=	http://www.xente.mundo-r.com/narf/vboxgtk/releases/ \
		LOCAL/avl

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GTK frontend for VirtualBox

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gobject/_gobject.so:${PORTSDIR}/devel/py-gobject \
		VBoxManage:${PORTSDIR}/emulators/virtualbox

USE_BZIP2=	yes
NO_BUILD=	yes
USE_PYTHON_RUN=	yes
USE_GNOME=	pygtk2
VBOXGTKDIR=	${PREFIX}/libexec/${PORTNAME}
DESKTOP_ENTRIES="Sun VirtualBox" \
		"Run several virtual systems on a single host computer" \
		"${PORTNAME}.png" \
		"${PORTNAME}" \
		"Application;System;Emulator;" \
		true
PLIST_SUB=	VBOXGTKDIR="${VBOXGTKDIR:S,^${PREFIX}/,,}"

post-patch:
	@${REINPLACE_CMD} -e 's|\([^#]self.base_path = \).*|\1\"${VBOXGTKDIR}/\"|' \
			-e 's|/usr/bin|${PREFIX}/bin|' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|createvdi|createhd|' -e 's|(hd_size|(int(hd_size)|' \
			${WRKSRC}/vboxdao_vboxmanage.py

do-install:
	${MKDIR} ${VBOXGTKDIR}/pixmaps
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${VBOXGTKDIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${VBOXGTKDIR}
	${INSTALL_DATA} ${WRKSRC}/*.glade ${VBOXGTKDIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png ${VBOXGTKDIR}/pixmaps
	${LN} -sf ${VBOXGTKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${LN} -sf ${VBOXGTKDIR}/pixmaps/48x48.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
