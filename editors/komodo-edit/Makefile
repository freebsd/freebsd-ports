# New ports collection Makefile for:	komodo-edit
# Date created:				2008-02-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	komodo-edit
PORTVERSION=	5.1.4
CATEGORIES=	editors
MASTER_SITES=	http://downloads.activestate.com/Komodo/releases/${PORTVERSION}/
DISTNAME=	Komodo-Edit-${PORTVERSION}-3797-linux-libcpp6-x86

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Multi-language editor from ActiveState

ONLY_FOR_ARCH=	i386 amd64
RESTRICTED=	Distribution not permitted
NO_BUILD=	yes
USE_LINUX=	f10
USE_LINUX_APPS=	gtk2 jpeg
USE_LDCONFIG=	yes
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
