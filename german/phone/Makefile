# New ports collection makefile for:	German phone codes
# Version required:     1.0
# Date created:         1997-12-30
# Whom:                 wosch
#
# $Id: Makefile,v 1.3 1997/12/31 22:43:27 asami Exp $
#

DISTNAME=	avon-1996
PKGNAME=	de-phone-1.0
CATEGORIES=	german missc
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
