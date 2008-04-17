# New ports collection makefile for:	p5-File-Temp
# Date created:		13 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	File-Temp
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Perl5 module to generate temporary files or directories safely

PERL_CONFIGURE=	yes

MAN3=		File::Temp.3

pre-patch:
	@${FIND} ${WRKSRC} -name "._Temp.pm" -delete

.include <bsd.port.mk>
