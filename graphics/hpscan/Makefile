# New ports collection makefile for:	hpscan
# Date created:		12 January 1996
# Whom:			nate
#
# $FreeBSD$
#

PORTNAME=	hpscan
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.cogsci.ed.ac.uk/pub/richard/
DISTNAME=	scanner

MAINTAINER=	jkh@FreeBSD.org

LIB_DEPENDS=    jpeg.9:${PORTSDIR}/graphics/jpeg

NO_WRKSUBDIR=		yes
USE_X_PREFIX=		yes
USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

pre-configure:
	${CP} -f ${FILESDIR}/Imakefile ${WRKSRC}

.include <bsd.port.mk>
