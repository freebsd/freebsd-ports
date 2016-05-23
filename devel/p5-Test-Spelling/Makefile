# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Spelling
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Check for spelling errors in POD files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Pod-Spell>=0:textproc/p5-Pod-Spell \
		p5-IPC-Run3>=0:devel/p5-IPC-Run3
RUN_DEPENDS=	p5-Pod-Spell>=0:textproc/p5-Pod-Spell \
		p5-IPC-Run3>=0:devel/p5-IPC-Run3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
