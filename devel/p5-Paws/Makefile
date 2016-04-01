# $FreeBSD$

PORTNAME=	Paws
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JLMARTIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of SDK for AWS (Amazon Web Services) APIs

LICENSE=	GPLv3

RUN_DEPENDS=	\
	p5-ARGV-Struct>=0:devel/p5-ARGV-Struct \
	p5-Browser-Open>0:www/p5-Browser-Open \
	p5-Config-INI>0:devel/p5-Config-INI \
	p5-Data-Compare>0:devel/p5-Data-Compare \
	p5-DateTime>0:devel/p5-DateTime \
	p5-DateTime-Format-ISO8601>0:devel/p5-DateTime-Format-ISO8601 \
	p5-Digest-HMAC>0:security/p5-Digest-HMAC \
	p5-Hash-Flatten>0:devel/p5-Hash-Flatten \
	p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL \
	p5-JSON>0:converters/p5-JSON \
	p5-Module-Find>0:devel/p5-Module-Find \
	p5-Moose>0:devel/p5-Moose \
	p5-MooseX-ClassAttribute>0:devel/p5-MooseX-ClassAttribute \
	p5-MooseX-Getopt>0:devel/p5-MooseX-Getopt \
	p5-Net-Amazon-Signature-V3>=0:net/p5-Net-Amazon-Signature-V3 \
	p5-Net-Amazon-Signature-V4>=0:net/p5-Net-Amazon-Signature-V4 \
	p5-String-Util>=0:textproc/p5-String-Util \
	p5-Throwable>=0:devel/p5-Throwable \
	p5-URI>0:net/p5-URI \
	p5-URI-Template>0:net/p5-URI-Template \
	p5-URL-Encode>0:www/p5-URL-Encode \
	p5-URL-Encode-XS>0:www/p5-URL-Encode-XS \
	p5-XML-Simple>0:textproc/p5-XML-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
