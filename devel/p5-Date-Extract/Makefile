# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Date-Extract
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Extract probable dates from strings

BUILD_DEPENDS=	p5-DateTime-Format-Natural>0:devel/p5-DateTime-Format-Natural	\
		p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockTime>=0:devel/p5-Test-MockTime

NO_ARCH=	yes

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
