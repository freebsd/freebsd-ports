# New ports collection makefile for:	Readonly
# Date created:	   31 August 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Readonly
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RO/ROODE
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-XS-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Facility for creating read-only scalars, arrays, hashes

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	DIR="${PORTNAME}-XS-${PORTVERSION}"

MAN3=		Readonly.3 Readonly::XS.3

post-patch:
	${MV} ${WRKDIR}/${PORTNAME}-XS-${PORTVERSION} ${WRKSRC}
	${RM} ${WRKSRC}/*.pl

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	Perl 5.8 or newer required. Install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
