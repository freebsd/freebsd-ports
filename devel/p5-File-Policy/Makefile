# New ports collection makefile for:	p5-File-Policy
# Date created: 			August 27, 2007
# Whom: 				Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Policy
PORTVERSION=	1.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Simple policy for file I/O functions

BUILD_DEPENDS=	p5-Log-Trace>0:${PORTSDIR}/devel/p5-Log-Trace \
		p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-Assertions>0:${PORTSDIR}/devel/p5-Test-Assertions
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Policy.3 \
		File::Policy::Default.3 \
		File::Slurp::WithinPolicy.3

.include <bsd.port.mk>
