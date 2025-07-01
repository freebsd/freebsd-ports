PORTNAME=	Zonemaster-CLI
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.0
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZNMSTR
PKGNAMEPREFIX=	p5-

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Perl command-line for Zonemaster DNS testing
WWW=		https://zonemaster.net/en

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Devel-CheckLib>0:devel/p5-Devel-CheckLib \
		p5-Module-Install>0:devel/p5-Module-Install
RUN_DEPENDS=	p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Locale-libintl>0:devel/p5-Locale-libintl \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-Text-Reflow>0:textproc/p5-Text-Reflow \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		p5-Zonemaster-Engine>0:dns/p5-Zonemaster-Engine

USES=		gmake localbase perl5
USE_PERL5=	configure

.include <bsd.port.mk>
