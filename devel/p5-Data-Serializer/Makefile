# New ports collection makefile for:	Data-Serializer
# Date created:	   07 June 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Data-Serializer
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Digest.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Data::Serializer.3 Data::Serializer::Data::Denter.3 \
		Data::Serializer::Data::Dumper.3 Data::Serializer::FreezeThaw.3 \
		Data::Serializer::Storable.3

.include <bsd.port.mk>
