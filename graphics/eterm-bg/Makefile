# New ports collection makefile for:	eterm-bg
# Version required:    0.9
# Date created:        99/06/12
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Eterm-bg-0.9
PKGNAME=	eterm-bg-0.9
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.eterm.org/pub/Eterm/ \
		http://eterm.is.nontoxic.org/download/ \
		ftp://ftp.livewire.com.au/pub/linuxberg/files/x11/system/ \
		ftp://ftp.c-com.net/pub/.30/LinuxBerg/files/x11/system/ \
		ftp://ftp.sunsite.auc.dk/disk6/linuxberg.com/files/x11/system/

MAINTAINER=	taoka@FreeBSD.org

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes
RM_FILES1=	014.jpg 40.jpg backwave.jpg blackstone.jpg circuit.jpg nebula.jpg
RM_FILES2=	fourthday.jpg gaia.jpg galleon.jpg nebula.jpg night_of_the_dragon.jpg

post-extract:
	cd ${WRKSRC}/bg/tile; ${RM} ${RM_FILES1}
	cd ${WRKSRC}/bg/scale; ${RM} ${RM_FILES2}

do-install:
	${MKDIR} ${PREFIX}/share/Eterm/pix
	cd ${WRKSRC}; ${INSTALL_DATA} bg/scale/*  ${PREFIX}/share/Eterm/pix
	cd ${WRKSRC}; ${INSTALL_DATA} bg/tile/*  ${PREFIX}/share/Eterm/pix

dd-i:
	for dist in ${DISTFILES}; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
			${DISTDIR}/$${dist} \
			${EXTRACT_AFTER_ARGS} -C ${PREFIX}/share/Eterm; \
	done;

.include <bsd.port.mk>
