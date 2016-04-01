# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-DRI
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Perl library to access Domain Name Registries/Registrars

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-DateTime>0:devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>0.06:devel/p5-DateTime-Format-ISO8601 \
		p5-DateTime-Format-Strptime>0:devel/p5-DateTime-Format-Strptime \
		p5-DateTime-TimeZone>0:devel/p5-DateTime-TimeZone \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Class-Accessor-Chained>0:devel/p5-Class-Accessor-Chained \
		p5-Time-HiRes>0:devel/p5-Time-HiRes \
		p5-Email-Valid>0:mail/p5-Email-Valid \
		p5-IO-Socket-SSL>0.90:security/p5-IO-Socket-SSL \
		p5-XML-LibXML>1.61:textproc/p5-XML-LibXML \
		p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
		p5-SOAP-Lite>0:net/p5-SOAP-Lite \
		p5-SOAP-WSDL>0:devel/p5-SOAP-WSDL \
		p5-libwww>0:www/p5-libwww \
		p5-Digest-MD5>0:security/p5-Digest-MD5 \
		p5-Net-DNS>0:dns/p5-Net-DNS \
		p5-MIME-Tools>0:mail/p5-MIME-Tools

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
