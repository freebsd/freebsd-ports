# $FreeBSD$

PORTNAME=	Encode-JP-Mobile
PORTVERSION=	0.30
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encoding for mobile phones in Japan

RUN_DEPENDS=	\
	p5-File-ShareDir>=0.05:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-MIME-Tools>=5.428:${PORTSDIR}/mail/p5-MIME-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
