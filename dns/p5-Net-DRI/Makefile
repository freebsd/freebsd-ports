# Created by: Mark Felder <feld@freebsd.org>
# $FreeBSD$
#

PORTNAME=	Net-DRI
PORTVERSION=	0.96
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	feld@freebsd.org
COMMENT=	A Perl library to access Domain Name Registries/Registrars

RUN_DEPENDS=	p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>0.06:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601 \
		p5-DateTime-Format-Strptime>0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime-TimeZone>0:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Accessor-Chained>0:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		p5-Time-HiRes>0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-Email-Valid>0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-IO-Socket-SSL>0.90:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-XML-LibXML>1.61:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-SOAP-Lite>0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-SOAP-WSDL>0:${PORTSDIR}/devel/p5-SOAP-WSDL \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-Digest-MD5>0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Net-DNS>0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-MIME-Tools>0:${PORTSDIR}/mail/p5-MIME-Tools

PERL_CONFIGURE=	yes

.include "${.CURDIR}/Makefile.man"

.include <bsd.port.mk>
