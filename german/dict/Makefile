# New ports collection makefile for: dict
# Version required:     1.0
# Date created:         6 August 1997
# Whom:                 wosch
#
# $Id: Makefile,v 1.4 1997/12/28 12:17:46 wosch Exp $
#

DISTNAME=       dict-1.1
CATEGORIES=	german
MASTER_SITES=   http://www.freebsd.org/~wosch/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${dict}.gz

MAINTAINER=     wosch@FreeBSD.org

RUN_DEPENDS=	${PORTSDIR}/textproc/agrep

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

dict=		ger-eng.txt

post-extract: ${dict}
${dict}:
	${GZCAT} < ${DISTDIR}/${dict}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
