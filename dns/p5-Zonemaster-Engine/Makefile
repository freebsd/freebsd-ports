PORTNAME=	Zonemaster-Engine
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.0
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZNMSTR
PKGNAMEPREFIX=	p5-

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Perl backend for Zonemaster DNS testing
WWW=		https://zonemaster.net/en

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Devel-CheckLib>0:devel/p5-Devel-CheckLib \
		p5-Module-Install>0:devel/p5-Module-Install
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Clone>=0:devel/p5-Clone \
		p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib \
		p5-Email-Valid>=0:mail/p5-Email-Valid \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-List-Compare>=0:misc/p5-List-Compare \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Locale-libintl>0:devel/p5-Locale-libintl \
		p5-Locale-libintl>=0:devel/p5-Locale-libintl \
		p5-Locale-PO>=0:devel/p5-Locale-PO \
		p5-Log-Any>=0:devel/p5-Log-Any \
		p5-Mail-SPF>=0:mail/p5-Mail-SPF \
		p5-MIME-Base32>=0:converters/p5-MIME-Base32 \
		p5-Module-Find>=0:devel/p5-Module-Find \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Getopt>=0:devel/p5-MooseX-Getopt \
		p5-MooseX-Singleton>=0:devel/p5-MooseX-Singleton \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-IP-XS>=0:net-mgmt/p5-Net-IP-XS \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Text-Reflow>0:textproc/p5-Text-Reflow \
		p5-Try-Tiny>0:lang/p5-Try-Tiny \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML \
		p5-Zonemaster-LDNS>0:dns/p5-Zonemaster-LDNS

USES=		gmake localbase perl5
USE_PERL5=	configure

.include <bsd.port.mk>
