# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	SOAP-WSDL
PORTVERSION=	3.003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for SOAP with WSDL support

BUILD_DEPENDS=	p5-Class-Load>=0.2:${PORTSDIR}/devel/p5-Class-Load \
		p5-Class-Std-Fast>=0.0.5:${PORTSDIR}/devel/p5-Class-Std-Fast \
		p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Term-ReadKey>=2.30:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-TimeDate>=1.16:${PORTSDIR}/devel/p5-TimeDate \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
		p5-XML-Parser>=2.36:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
