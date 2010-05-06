# New ports collection makefile for:	p5-Archive-SimpleExtractor
# Date created:		2009-11-02
# Whom:			Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	Archive-SimpleExtractor
PORTVERSION=	0.11
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple module for extract archives

BUILD_DEPENDS=	p5-Archive-Rar>=2.02:${PORTSDIR}/archivers/p5-Archive-Rar \
		p5-Archive-Tar>=1.54:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Archive-Zip>=1.30:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Module-Load>=0.16:${PORTSDIR}/devel/p5-Module-Load \
		p5-Module-Load-Conditional>=0.3:${PORTSDIR}/devel/p5-Module-Load-Conditional
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Archive::SimpleExtractor::Zip.3 \
		Archive::SimpleExtractor::Tar.3 \
		Archive::SimpleExtractor.3 \
		Archive::SimpleExtractor::Rar.3

.include <bsd.port.mk>
