# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Acme-Lou
PORTVERSION=	0.03
PORTREVISION=	2
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

DEPRECATED=	Needs ja-p5-Text-MeCab that does not work with 5.18 or above
EXPIRATION_DATE=2015-07-31

.include <bsd.port.mk>
