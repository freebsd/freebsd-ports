# Created by: Jui-Nan Lin <jnlin@freebsd.cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Amazon-Route53
PORTVERSION=	0.122310
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@freebsd.cs.nctu.edu.tw
COMMENT=	Manage your DNS entries on Amazon's Route53 service

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-XML-Bare>=0:textproc/p5-XML-Bare \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	py[23][0-9]-boto-devel-[0-9]*

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
