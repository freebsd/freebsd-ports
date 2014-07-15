# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Archive-Any
PORTVERSION=	0.09.41
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Single interface to deal with file archives

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Zip>=1.07:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-File-MMagic>=1.27:${PORTSDIR}/devel/p5-File-MMagic \
		p5-MIME-Types>=1.16:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Module-Find>=0.05:${PORTSDIR}/devel/p5-Module-Find
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
