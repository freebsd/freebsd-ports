# New ports collection makefile for:	devel/p5-Parse-CPAN-Packages
# Date created:				Mar 27 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Parse-CPAN-Packages
PORTVERSION=	2.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse 02packages.details.txt.gz from CPAN

RUN_DEPENDS=	p5-CPAN-DistnameInfo>0:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-version>=0:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Parse::CPAN::Packages.3 \
	Parse::CPAN::Packages::Distribution.3 \
	Parse::CPAN::Packages::Package.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
