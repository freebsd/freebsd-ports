# New ports collection makefile for: dict
# Version required:     1.0
# Date created:         6 August 1997
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	de-dict
PORTVERSION=	1.2
CATEGORIES=	german
MASTER_SITES=	http://www.de.freebsd.org/~wosch/src/
DISTNAME=	dict-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${dict}.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wosch@FreeBSD.org

RUN_DEPENDS=	agrep:${PORTSDIR}/textproc/agrep

dict=		ger-eng.txt

post-extract: ${dict}
${dict}:
	${GZCAT} < ${DISTDIR}/${dict}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
