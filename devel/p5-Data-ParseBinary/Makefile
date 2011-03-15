# New ports collection makefile for:	p5-Data-ParseBinary
# Date created:		2008-12-29
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-ParseBinary
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SEMUELF
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	Yet Another parser for binary structures

BUILD_DEPENDS=	p5-Math-BigInt>=1.993:${PORTSDIR}/math/p5-Math-BigInt

TEST_DEPENDS=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Data::ParseBinary::Graphics::WMF.3 \
	Data::ParseBinary::Graphics::EMF.3 \
	Data::ParseBinary.3 \
	Data::ParseBinary::Graphics::BMP.3 \
	Data::ParseBinary::Executable::ELF32.3 \
	Data::ParseBinary::Executable::PE32.3 \
	Data::ParseBinary::Data::Cap.3 \
	Data::ParseBinary::Data::Netflow.3 \
	Data::ParseBinary::Graphics::PNG.3 \
	Data::ParseBinary::FileSystem::MBR.3

.include <bsd.port.mk>
