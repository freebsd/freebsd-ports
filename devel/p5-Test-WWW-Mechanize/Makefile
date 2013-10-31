# Created by: aturetta@commit.it
# $FreeBSD$

PORTNAME=	Test-WWW-Mechanize
PORTVERSION=	1.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PETDANCE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Testing-specific WWW::Mechanize subclass

LICENSE=	ART20

BUILD_DEPENDS=	p5-Carp-Assert-More>=0:${PORTSDIR}/devel/p5-Carp-Assert-More \
		p5-HTML-Tree>0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Server-Simple>=0.42:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-Test-LongString>=0.15:${PORTSDIR}/devel/p5-Test-LongString \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.68:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-libwww>=6.02:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
