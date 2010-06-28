# New ports collection makefile for:	p5-Tie-File
# Date created:				17 June 2003
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-File
PORTVERSION=	0.96
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access the lines of a disk file via a Perl array

PERL_CONFIGURE=	yes

MAN3=		Tie::File.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
