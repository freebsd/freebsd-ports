# Version required:     1.0
# Date created:         1997-12-30
# Whom:                 wosch
#
# $Id: Makefile,v 1.6 1997/10/03 12:25:15 wosch Exp $

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
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${WRKSRC}/${phone} ${PREFIX}/share/misc/${phoneout}

post-extract: ${phone}
${phone}:
	${GZIP_CMD} -d < ${DISTDIR}/${phone}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
