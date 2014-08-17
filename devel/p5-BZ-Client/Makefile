# $FreeBSD$

PORTNAME=	BZ-Client
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JWIED
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Client for the Bugzilla web services API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-DateTime-Format-ISO8601>=0:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
