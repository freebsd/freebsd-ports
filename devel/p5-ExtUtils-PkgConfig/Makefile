# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ExtUtils-PkgConfig
PORTVERSION=	1.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simplistic interface to pkg-config

LICENSE=	LGPL3

USES=		pkgconfig:both
PERL_CONFIGURE=	yes

MAN3=		ExtUtils::PkgConfig.3

post-patch:
	@${REINPLACE_CMD} -i '' -e '1d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
