# New ports collection makefile for:	MicroEmacs
# Version required:     4.0
# Date created:         16 Jan 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.10 1997/08/29 11:33:09 tg Exp $
#

DISTNAME=	uemacs
PKGNAME=	uemacs-4.0
CATEGORIES=	editors
MASTER_SITES=	ftp://aquest.com/pub/uemacs400/disk2/ \
		ftp://informatik.hu-berlin.de/pub/pc/msdos/editors/ \
		ftp://ftp.biomath.jussieu.fr/pub/editors/memacs400/disk2/
DISTFILES=	ue400dev.zip

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes
EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-Laq
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}
FETCH_BEFORE_ARGS=	-NP

.include <bsd.port.mk>
