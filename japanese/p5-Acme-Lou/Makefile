# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Acme-Lou
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Let's together with Lou Ohshiba

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		ja-p5-Text-MeCab>=0:${PORTSDIR}/japanese/p5-Text-MeCab
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Acme::Lou.3

.include <bsd.port.mk>
