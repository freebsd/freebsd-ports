# New ports collection makefile for:	p5-AcePerl
# Date created:		26 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	AcePerl
PORTVERSION=	1.62
CATEGORIES=	biology databases perl5
MASTER_SITES=	http://stein.cshl.org/AcePerl/archive/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Ace
PKGNAMEPREFIX=	p5-

MAINTAINER=	johann@egenetics.com

USE_PERL5=	YES

MAN3=		Ace::Sequence::Feature.3 \
		Ace::Sequence.3 \
		Ace.3 \
		Ace::Sequence::FeatureList.3 \
		Ace::Sequence::Multi.3 \
		Ace::Sequence::Homol.3 \
		Ace::Object.3 \
		Ace::Local.3 \
		Ace::Iterator.3 \
		Ace::Model.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	${CP} ${FILESDIR}/FREEBSD_DEF ${WRKSRC}/ace/wmake/
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
