# New ports collection makefile for:	devel/p5-Hash-Merge-Simple
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Hash-Merge-Simple
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Recursively merge two or more hashes, simply

RUN_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Hash::Merge::Simple.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
