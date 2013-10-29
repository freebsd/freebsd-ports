# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Google-Checkout
PORTVERSION=	1.1.1
CATEGORIES=	devel www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl implementation of Google Checkout (GCO)

RUN_DEPENDS=	p5-libwww>=5.65:${PORTSDIR}/www/p5-libwww \
		p5-XML-Simple>=2.09:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Crypt-SSLeay>=0.45:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Date-Manip>=5.40:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Digest-HMAC>=1.01:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-XML-Writer>=0.6:${PORTSDIR}/textproc/p5-XML-Writer
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
