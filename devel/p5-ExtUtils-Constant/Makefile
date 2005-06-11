# New ports collection makefile for:	ExtUtils-Constant
# Date created:	   03 February 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-Constant
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generate XS code to import C header constants

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::Constant.3 ExtUtils::Constant::Base.3 \
		ExtUtils::Constant::Utils.3 ExtUtils::Constant::XS.3

post-patch:
	@${REINPLACE_CMD} -e '/INSTALLDIRS/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
