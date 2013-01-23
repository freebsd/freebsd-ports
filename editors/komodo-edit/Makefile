# New ports collection Makefile for:	komodo-edit
# Date created:				2008-02-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	komodo-edit
PORTVERSION=	6.1.2
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://downloads.activestate.com/Komodo/releases/${PORTVERSION}/
DISTNAME=	Komodo-Edit-${PORTVERSION}-8334-linux-libcpp6-x86

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Multi-language editor from ActiveState

CONFLICTS=	komodo-ide-*

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USE_LINUX=	f10
USE_LINUX_APPS=	alsalib gtk2 jpeg dbusglib
DESKTOP_ENTRIES="Komodo Edit" \
		"Free multi-platform editor that makes it easy to write quality code." \
		${DATADIR}/share/icons/komodo48.png \
		"komodo" \
		"Development;Utility;TextEditor;" \
		${FALSE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not build
.endif

do-install:
	${MKDIR} ${DESKTOPDIR}
	cd ${WRKSRC}/INSTALLDIR && ${COPYTREE_SHARE} \* ${DATADIR}
	${CHMOD} ${BINMODE} ${DATADIR}/bin/komodo
	${CHMOD} ${BINMODE} ${DATADIR}/lib/mozilla/komodo
	${CHMOD} ${BINMODE} ${DATADIR}/lib/mozilla/komodo-bin
	${CHMOD} ${BINMODE} ${DATADIR}/lib/mozilla/run-mozilla.sh
	${LN} -sf ${DATADIR}/bin/komodo ${PREFIX}/bin/

.include <bsd.port.post.mk>
