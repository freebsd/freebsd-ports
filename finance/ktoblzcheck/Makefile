# New ports collection makefile for:    ktoblzcheck
# Date created:         25 November 2003
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktoblzcheck
PORTVERSION=	0.4
CATEGORIES=	german finance
MASTER_SITES=	http://ktoblzcheck.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check bank codes of German banks

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

GNU_CONFIGURE=	yes

MAN1=		ktoblzcheck.1

DATAFILE=	bankdata.zip

post-extract:
	@unzip -qo ${DISTDIR}/${DATAFILE} -d ${WRKSRC}/src/bankdata

.include <bsd.port.mk>
