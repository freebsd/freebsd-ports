# New ports collection makefile for:	ja-mg
# Date created:		7 May 2006
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mg
PORTVERSION=	5.0.1.3
CATEGORIES=	japanese perl5
MASTER_SITES=	http://dist.bsdlab.org/ \
		http://www.srekcah.org/~utashiro/perl/scripts/mg/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	# None
EXTRACT_ONLY=	# None

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Multi-line grep suitable for Japanese text

USE_PERL5_RUN=	YES
CONFLICTS=	mg-200*

do-build:
	${SED} -e "s|/usr/local|${PREFIX}|g" \
		${DISTDIR}/${DISTFILES} > ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
