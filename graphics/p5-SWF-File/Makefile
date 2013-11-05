# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	SWF-File
PORTVERSION=	0.42
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulating Flash movie (SWF) files

BUILD_DEPENDS=	p5-Data-TemporaryBag>=0:${PORTSDIR}/devel/p5-Data-TemporaryBag
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
