# New ports collection makefile for: dict
# Version required:     1.0
# Date created:         6 August 1997
# Whom:                 wosch
#
# $Id: Makefile,v 1.2 1997/08/13 05:09:22 asami Exp $
#

DISTNAME=       dict-1.0
CATEGORIES=	german
MASTER_SITES=   http://www.freebsd.org/~wosch/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${dict}.gz

MAINTAINER=     wosch@FreeBSD.org

RUN_DEPENDS=	${PORTSDIR}/textproc/agrep

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

dict=		eng2germ.dict

post-extract: ${dict}
${dict}:
	${GZIP_CMD} -d < ${DISTDIR}/${dict}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
