# Created by: Ruben van Staveren
# $FreeBSD$

PORTNAME=	threads-shared
PORTVERSION=	1.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Perl extension for sharing data structures between threads

PERL_CONFIGURE=	yes

MAN3=	threads::shared.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501100
BUILD_DEPENDS+=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads
RUN_DEPENDS+=	p5-threads>=1.73:${PORTSDIR}/devel/p5-threads
.endif

.include <bsd.port.post.mk>
