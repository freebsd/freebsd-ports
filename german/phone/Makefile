# New ports collection makefile for:	German phone codes
# Version required:     1.0
# Date created:         1997-12-30
# Whom:                 wosch
#
# $Id: Makefile,v 1.2 1997/12/31 12:09:33 wosch Exp $
#

DISTNAME=       de-phone-1.0
CATEGORIES=	german
MASTER_SITES=   ${MASTER_SITE_LOCAL} http://www.freebsd.org/~wosch/src/
DISTFILES=	${phone}.gz

MAINTAINER=     wosch@FreeBSD.org

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
EXTRACT_ONLY=

phone=	avon-1996
phoneout= de.phone

do-install:
	${INSTALL_DATA} ${WRKSRC}/${phone} ${PREFIX}/share/misc/${phoneout}

post-extract: ${phone}
${phone}:
	${GZCAT} < ${DISTDIR}/${phone}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
