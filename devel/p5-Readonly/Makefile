# New ports collection makefile for:	Readonly
# Date created:	   31 August 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Readonly
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROODE
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-XS-${PORTVERSION_XS}${EXTRACT_SUFX}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Facility for creating read-only scalars, arrays, hashes

PERL_CONFIGURE=	5.8.0+
CONFIGURE_ARGS=	DIR="${PORTNAME}-XS-${PORTVERSION_XS}"
PORTVERSION_XS=	1.04

MAN3=		Readonly.3 Readonly::XS.3

post-patch:
	${MV} ${WRKDIR}/${PORTNAME}-XS-${PORTVERSION_XS} ${WRKSRC}
	${RM} ${WRKSRC}/*.pl

.include <bsd.port.mk>
