# New ports collection makefile for: dict
# Version required:     1.0
# Date created:         6 August 1997
# Whom:                 wosch
#
# $Id: Makefile,v 1.7 1997/04/30 03:18:08 asami Exp $


DISTNAME=       dict-1.0
CATEGORIES=	german
MASTER_SITES=   http://www.apfel.de/~wosch/src/
dict=		eng2germ.dict
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${dict}.gz
RUN_DEPENDS=	${PORTSDIR}/textproc/agrep
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=     wosch@FreeBSD.org

post-extract: ${dict}
${dict}:
	gzip -d < ${DISTDIR}/${dict}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
