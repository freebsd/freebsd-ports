# New ports collection makefile for:	p5-AcePerl
# Date created:		26 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	AcePerl
PORTVERSION=	1.67
CATEGORIES=	biology databases perl5
MASTER_SITES=	http://stein.cshl.org/AcePerl/archive/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Ace
PKGNAMEPREFIX=	p5-

MAINTAINER=	bio@freebsd.net

PERL_CONFIGURE=	YES

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

post-patch:
	@ ${SED} -e 's/XX__CC__XX/${CC}/' < ${FILESDIR}/FREEBSD_DEF \
	  > ${WRKSRC}/ace/wmake/FREEBSD_DEF

.include <bsd.port.mk>
