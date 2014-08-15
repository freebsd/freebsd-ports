# Created by: wosch
# $FreeBSD$

PORTNAME=	dict
PORTVERSION=	1.2
CATEGORIES=	german
MASTER_SITES=	http://wolfram.schneider.org/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${dict}.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple English/German dictionary

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	agrep:${PORTSDIR}/textproc/agrep

PLIST_FILES=	bin/de-dict share/ger-eng.txt
dict=		ger-eng.txt

post-extract: ${dict}

${dict}:
	${GZCAT} < ${DISTDIR}/${dict}.gz > ${WRKSRC}/${.TARGET}

.include <bsd.port.mk>
