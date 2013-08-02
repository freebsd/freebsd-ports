# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ExtUtils-Constant
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate XS code to import C header constants

USES=		perl5
USE_PERL5=	configure

MAN3=		ExtUtils::Constant.3 ExtUtils::Constant::Base.3 \
		ExtUtils::Constant::Utils.3 ExtUtils::Constant::XS.3

post-patch:
	@${REINPLACE_CMD} -e '/INSTALLDIRS/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
