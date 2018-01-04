# Created by: arved
# $FreeBSD$

PORTNAME=	komodo-edit
PORTVERSION=	10.2.2
CATEGORIES=	editors
MASTER_SITES=	http://downloads.activestate.com/Komodo/releases/${PORTVERSION}/ \
		http://downloads.activestate.com/Komodo/releases/archive/${PORTVERSION:R:R}.x/${PORTVERSION}/
DISTNAME=	Komodo-Edit-${PORTVERSION}-17703-linux-x86

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Multi-language editor from ActiveState

CONFLICTS=	komodo-ide-6*

RESTRICTED=	Distribution not permitted

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USES=		linux
USE_LINUX=	alsalib gtk2 jpeg dbusglib

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
	${RLN} ${STAGEDIR}${DATADIR}/bin/komodo ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
