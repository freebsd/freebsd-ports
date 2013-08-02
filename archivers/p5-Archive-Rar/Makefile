# Created by: Andrey Kostenko <andrey@kostenko.name>
# $FreeBSD$

PORTNAME=	Archive-Rar
PORTVERSION=	2.02
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface with the 'rar' command

BUILD_DEPENDS=	rar>=0:${PORTSDIR}/archivers/rar \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run

USES=		perl5
USE_PERL5=	configure
MAN3=		Archive::Rar.3 \
		Archive::Rar::Passthrough.3

.include <bsd.port.mk>
