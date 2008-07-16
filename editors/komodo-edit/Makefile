# New ports collection Makefile for:	komodo-edit
# Date created:				2008-02-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	komodo-edit
PORTVERSION=	4.4.1
CATEGORIES=	editors
MASTER_SITES=	http://downloads.activestate.com/Komodo/releases/${PORTVERSION}/
DISTNAME=	Komodo-Edit-${PORTVERSION}-1774-linux-libcpp6-x86

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Multi-language editor from ActiveState

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/bin/gtk-demo:${PORTSDIR}/x11-toolkits/linux-gtk2

ONLY_FOR_ARCH=	i386 amd64
RESTRICTED=	Distribution not permitted
NO_BUILD=	yes
USE_LINUX=	yes
USE_PYTHON=	yes

post-patch:
	${REINPLACE_CMD} -e "s,  _selinux_prepare(absInstallDir),  return,; \
		s,/usr/share/applications,${PREFIX}/share/applications," \
		${WRKSRC}/support/_install.py

do-install:
	${MKDIR} ${PREFIX}/share/applications
	cd ${WRKSRC}; ./install.sh -I ${DATADIR}
	${LN} -sf ${DATADIR}/bin/komodo ${PREFIX}/bin/komodo

.include <bsd.port.mk>
