# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Printer
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Colored pretty-print of Perl data structures and objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Clone-PP>=0:devel/p5-Clone-PP \
		p5-File-HomeDir>=0.91:devel/p5-File-HomeDir \
		p5-Package-Stash>=0.30:devel/p5-Package-Stash \
		p5-Sort-Naturally>=0:textproc/p5-Sort-Naturally
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-DBI>=0:databases/p5-DBI \
		p5-IO-Pty-Easy>=0:devel/p5-IO-Pty-Easy \
		p5-Test-Pod>=1.41:devel/p5-Test-Pod

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
