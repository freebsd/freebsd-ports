# $FreeBSD$

PORTNAME=	Encode-JP-Mobile
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for encoding for mobile phones in Japan

RUN_DEPENDS=	\
	p5-File-ShareDir>=0.05:devel/p5-File-ShareDir \
	p5-MIME-Tools>=5.428:mail/p5-MIME-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-YAML>0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Encode/JP/Mobile/Mobile.so

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
