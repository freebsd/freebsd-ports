# Created by: arved
# $FreeBSD$

PORTNAME=	komodo-edit
PORTVERSION=	6.1.3
CATEGORIES=	editors
MASTER_SITES=	http://downloads.activestate.com/Komodo/releases/archive/6.x/${PORTVERSION}/
DISTNAME=	Komodo-Edit-${PORTVERSION}-8844-linux-libcpp6-x86

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-language editor from ActiveState

CONFLICTS=	komodo-ide-6*

RESTRICTED=	Distribution not permitted
NO_CDROM=	Distribution not permitted
NO_PACKAGE=	Distribution not permitted

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	alsalib gtk2 jpeg dbusglib

PLIST_FILES=	bin/komodo
PORTDATA=	*

DESKTOP_ENTRIES="Komodo Edit" \
		"Free multi-platform editor that makes it easy to write quality code." \
		${DATADIR}/share/icons/komodo48.png \
		"komodo" \
		"Development;Utility;TextEditor;" \
		false

do-install:
	cd ${WRKSRC}/INSTALLDIR && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/komodo
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/lib/mozilla/komodo
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/lib/mozilla/komodo-bin
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/lib/mozilla/run-mozilla.sh
	${LN} -sf ${DATADIR}/bin/komodo ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
