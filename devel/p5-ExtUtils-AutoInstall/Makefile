# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ExtUtils-AutoInstall
PORTVERSION=	0.63
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic install of dependencies via CPAN

BUILD_DEPENDS=	p5-version>=0.28:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	extract configure

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^features, .. m,^\);,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
