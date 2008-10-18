# New ports collection makefile for:	p5-FormValidator-Simple-Plugin-Number-Phone-JP
# Date created:		May 10, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	FormValidator-Simple-Plugin-Number-Phone-JP
PORTVERSION=	0.03
CATEGORIES=	japanese perl5
MASTER_SITES=	CPAN

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Japanese phone number validation

RUN_DEPENDS=	p5-FormValidator-Simple>=0.03:${PORTSDIR}/textproc/p5-FormValidator-Simple \
	ja-p5-Number-Phone-JP>=0.03:${PORTSDIR}/japanese/p5-Number-Phone-JP

PERL_CONFIGURE=	yes

MAN3=	FormValidator::Simple::Plugin::Number::Phone::JP.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
