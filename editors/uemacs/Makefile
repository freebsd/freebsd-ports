# New ports collection makefile for:	MicroEmacs
# Version required:     3.12
# Date created:         16 Jan 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.3 1995/04/09 06:11:13 asami Exp $
#

DISTNAME=	uemacs
PKGNAME=	uemacs-3.12
CATEGORIES+=	editors
MASTER_SITES=	ftp://midas.mgmt.purdue.edu/dist/uemacs312/
DISTFILES=	ue312dev.zip

MAINTAINER=	ports@freebsd.org

EXEC_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p1
EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-Laq
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}
NCFTPFLAGS=		-N -P

.include <bsd.port.mk>
