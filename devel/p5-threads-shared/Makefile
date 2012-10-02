# Created by: Ruben van Staveren
# $FreeBSD$

PORTNAME=	threads-shared
PORTVERSION=	1.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for sharing data structures between threads

BUILD_DEPENDS=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads
RUN_DEPENDS=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads

PERL_CONFIGURE=	yes

MAN3=		threads::shared.3

.include <bsd.port.mk>
