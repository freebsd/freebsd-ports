# New ports collection makefile for:	SWF-File
# Date created:	   20 May 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	SWF-File
PORTVERSION=	0.42
PORTEPOCH=	1
CATEGORIES=	graphics www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/Y/YS/YSAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Manipulating Flash movie (SWF) files

BUILD_DEPENDS=	${SITE_PERL}/Data/TemporaryBag.pm:${PORTSDIR}/devel/p5-Data-TemporaryBag \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SWF::BinStream.3 SWF::BinStream::Codec.3 \
		SWF::BinStream::Codec::Zlib.3 SWF::BinStream::File.3 \
		SWF::Element.3 SWF::File.3 SWF::Parser.3

post-patch:
	@${FIND} ${WRKSRC} -type f |\
		${XARGS} ${PERL} -pi -e 's/\x0d(?=\x0a)//'

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
