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
MASTER_SITES=	ftp://midas.mgmt.purdue.edu/pub/ue312/
DISTFILES=	ue312dev.zip

EXEC_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p1

# one weakness of the ports scheme: it doesn't allow arguments
# to ${EXTRACT_CMD} after the filename, which is required for unzip.

# Satoshi: it does now, so please update it when you see this.... :)

do-extract:
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@unzip -Laq ${DISTDIR}/${DISTFILES} -d ${WRKDIR}

.include <bsd.port.mk>
