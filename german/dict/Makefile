# New ports collection makefile for: dict
# Date created:         6 August 1997
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	dict
PORTVERSION=	1.2
CATEGORIES=	german
MASTER_SITES=	http://wolfram.schneider.org/src/
DISTNAME=	dict-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${dict}.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	Simple English/German dictionary

RUN_DEPENDS=	agrep:${PORTSDIR}/textproc/agrep

dict=		ger-eng.txt

post-extract: ${dict}
${dict}:
	${GZCAT} < ${DISTDIR}/${dict}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
