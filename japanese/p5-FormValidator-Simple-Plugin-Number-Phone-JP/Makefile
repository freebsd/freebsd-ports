# New ports collection makefile for:	p5-FormValidator-Simple-Plugin-Number-Phone-JP
# Date created:		May 10, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	FormValidator-Simple-Plugin-Number-Phone-JP
PORTVERSION=	0.02
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIZZY

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for Japanese phone number validation

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-FormValidator-Simple>=0.03:${PORTSDIR}/textproc/p5-FormValidator-Simple \
	ja-p5-Number-Phone-JP>=0.03:${PORTSDIR}/japanese/p5-Number-Phone-JP

PERL_CONFIGURE=	yes

MAN3=	FormValidator::Simple::Plugin::Number::Phone::JP.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
