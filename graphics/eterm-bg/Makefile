# New ports collection makefile for:	eterm-bg
# Version required:    21-Jan-1999
# Date created:        99/06/12
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	eterm-bg-1999.1.21
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.eterm.org/pub/Eterm/ \
		http://eterm.is.nontoxic.org/download/ \
		ftp://ftp.livewire.com.au/pub/linuxberg/files/x11/system/ \
		ftp://ftp.c-com.net/pub/.30/LinuxBerg/files/x11/system/ \
		ftp://ftp.sunsite.auc.dk/disk6/linuxberg.com/files/x11/system/
DISTFILES=	Eterm-bg-scale-1.tar.gz Eterm-bg-scale-2.tar.gz Eterm-bg-tile.tar.gz

MAINTAINER=	taoka@FreeBSD.org

EXTRACT_ONLY=	# dummy
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

do-install:
	for dist in ${DISTFILES}; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
			${DISTDIR}/$${dist} \
			${EXTRACT_AFTER_ARGS} -C ${PREFIX}/share; \
	done;

.include <bsd.port.mk>
