# New ports collection makefile for:	hpscan
# Version required:	<own lineage>
# Date created:		12 January 1996
# Whom:			nate
#
# $Id: Makefile,v 1.15 1998/10/05 18:27:26 nate Exp $
#

DISTNAME=	scanner
PKGNAME=	hpscan-1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.cogsci.ed.ac.uk/pub/richard/

MAINTAINER=	jkh@FreeBSD.org

LIB_DEPENDS=    jpeg.9:${PORTSDIR}/graphics/jpeg

NO_WRKSUBDIR=		yes
USE_X_PREFIX=		yes
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

pre-configure:
	${CP} -f ${FILESDIR}/Imakefile ${WRKSRC}

.include <bsd.port.mk>
