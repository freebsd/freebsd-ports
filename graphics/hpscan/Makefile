# New ports collection makefile for:	hpscan
# Version required:	<own lineage>
# Date created:		12 January 1996
# Whom:			nate
#
# $Id: Makefile,v 1.6 1996/11/18 11:28:09 asami Exp $
#

DISTNAME=	scanner
PKGNAME=	hpscan-1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/ \
		ftp://macbeth.cogsci.ed.ac.uk/pub/

MAINTAINER=	nate@FreeBSD.org

LIB_DEPENDS+=  jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg

NO_WRKSUBDIR=		yes
USE_X11=		yes
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
