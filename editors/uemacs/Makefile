# New ports collection makefile for:	MicroEmacs
# Version required:     3.12
# Date created:         16 Jan 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $Id: Makefile,v 1.9 1996/11/11 05:07:20 obrien Exp $
#

DISTNAME=	uemacs
PKGNAME=	uemacs-3.12
CATEGORIES=	editors
MASTER_SITES=	ftp://midas.mgmt.purdue.edu/dist/uemacs312/ \
		ftp://ftp.th-darmstadt.de/pub/editors/MicroEMACS/uemacs312/
DISTFILES=	ue312dev.zip

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p1
EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-Laq
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}
FETCH_BEFORE_ARGS=	-NP

.include <bsd.port.mk>
