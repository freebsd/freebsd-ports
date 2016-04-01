# $FreeBSD$

PORTNAME=	Iodef-Pb-Simple
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SAXJAZMAN/iodef
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl extension providing high level API access to Iodef-Pb

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.34:devel/p5-Class-Accessor \
		p5-Compress-Snappy>=0.18:archivers/p5-Compress-Snappy \
		p5-DateTime>=0.61:devel/p5-DateTime \
		p5-DateTime-Format-DateParse>=0.05:devel/p5-DateTime-Format-DateParse \
		p5-Google-ProtocolBuffers>=0.08:devel/p5-Google-ProtocolBuffers \
		p5-HTML-Table>=2.08:www/p5-HTML-Table \
		p5-JSON-XS>=2.29:converters/p5-JSON-XS \
		p5-MIME-Base64>=0.08:converters/p5-MIME-Base64 \
		p5-Module-Install>=1.00:devel/p5-Module-Install \
		p5-OSSP-uuid>=1.6.2:misc/p5-OSSP-uuid \
		p5-Parse-Range>=0.96:math/p5-Parse-Range \
		p5-Regexp-Common>=2010010201:textproc/p5-Regexp-Common \
		p5-Regexp-Common-net-CIDR>=0.02:textproc/p5-Regexp-Common-net-CIDR \
		p5-Snort-Rule>=1.07:security/p5-Snort-Rule \
		p5-Text-Table>=1.126:textproc/p5-Text-Table
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
