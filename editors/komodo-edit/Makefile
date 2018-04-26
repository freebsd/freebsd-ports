# $FreeBSD$

PORTNAME=	komodo-edit
DISTVERSION=	11.0.2
CATEGORIES=	editors
MASTER_SITES=	http://downloads.activestate.com/Komodo/releases/${DISTVERSION}/ \
		http://downloads.activestate.com/Komodo/releases/archive/${DISTVERSION:R:R}.x/${DISTVERSION}/
DISTNAME=	Komodo-Edit-${DISTVERSION}-18122-linux-x86

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Multi-language editor from ActiveState

# https://www.activestate.com/komodo-edit/license-agreement
LICENSE=	KEL11 MPL11
LICENSE_COMB=	multi
LICENSE_NAME_KEL11=	Komodo Edit END-USER SOFTWARE LICENSE AGREEMENT
LICENSE_FILE_KEL11=	${FILESDIR}/kel11_license.txt
LICENSE_PERMS_KEL11=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		linux
USE_LINUX=	alsalib dbusglib gtk2 jpeg xorglibs

DESKTOP_ENTRIES="Komodo Edit" \
		"Free multi-platform editor that makes it easy to write quality code." \
		${DATADIR}/share/icons/komodo48.png \
		"komodo" \
		"Development;Utility;TextEditor;" \
		false
NO_BUILD=	yes
PLIST_FILES=	bin/komodo
PORTDATA=	*

do-install:
	cd ${WRKSRC}/INSTALLDIR && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/komodo
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/lib/mozilla/komodo
	${RLN} ${STAGEDIR}${DATADIR}/bin/komodo ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
