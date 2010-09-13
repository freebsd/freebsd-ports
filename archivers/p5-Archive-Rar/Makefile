# New ports collection makefile for:	p5-Archive-Rar
# Date created:		2009-11-02
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	Archive-Rar
PORTVERSION=	2.02
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface with the 'rar' command

BUILD_DEPENDS=	rar>=0:${PORTSDIR}/archivers/rar

PERL_CONFIGURE=	yes
MAN3=		Archive::Rar.3 \
		Archive::Rar::Passthrough.3

.include <bsd.port.mk>
