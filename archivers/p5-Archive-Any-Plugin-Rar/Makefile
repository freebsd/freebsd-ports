# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Archive-Any-Plugin-Rar
PORTVERSION=	0.02
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Wrapper around Archive::Rar

BUILD_DEPENDS=	p5-Archive-Any>=0:${PORTSDIR}/archivers/p5-Archive-Any \
		p5-Archive-Rar>=0:${PORTSDIR}/archivers/p5-Archive-Rar \
		p5-lib-abs>=0.90:${PORTSDIR}/devel/p5-lib-abs
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Archive::Any::Plugin::Rar.3

.include <bsd.port.mk>
