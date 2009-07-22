# New ports collection makefile for:	ExtUtils-PkgConfig
# Date created:	   18 October 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-PkgConfig
PORTVERSION=	1.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Simplistic interface to pkg-config

USE_GNOME=	pkgconfig
PERL_CONFIGURE=	yes

MAN3=		ExtUtils::PkgConfig.3

post-patch:
	@${PERL} -pi -e '$$_="" if $$.==1' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
