# New ports collection makefile for:	German phone codes
# Version required:     1.0
# Date created:         1997-12-30
# Whom:                 wosch
#
# $Id: Makefile,v 1.4 1998/01/02 21:05:36 max Exp $
#

DISTNAME=	avon-1996
PKGNAME=	de-phone-1.0
CATEGORIES=	german misc
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.freebsd.org/~wosch/src/
EXTRACT_SUFX=	.gz

MAINTAINER=     wosch@FreeBSD.org

NO_WRKSUBDIR=	YES
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/de.phone
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/de.phone ${PREFIX}/share/misc

.include <bsd.port.mk>
