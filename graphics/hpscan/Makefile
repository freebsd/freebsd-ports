# New ports collection makefile for:	hpscan
# Version required:	<own lineage>
# Date created:		12 January 1996
# Whom:			nate
#
# $Id: Makefile,v 1.11 1998/05/04 20:22:38 jseger Exp $
#

DISTNAME=	scanner
PKGNAME=	hpscan-1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.cogsci.ed.ac.uk/pub/richard/

MAINTAINER=	nate@FreeBSD.org

LIB_DEPENDS+=  jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg

NO_WRKSUBDIR=		yes
USE_X_PREFIX=		yes
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
