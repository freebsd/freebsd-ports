# ex:ts=8
# New ports collection makefile for:	p5-tagged
# Date created:			Apr 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tagged
PORTVERSION=	0.40
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	MP3 ${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Read, change and write different tags of MP3 audio files

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	MP3::Tag::ID3v2.3 MP3::Tag.3 MP3::Tag::File.3 \
	MP3::Tag::ID3v2-Data.3 MP3::Tag::ID3v1.3

.include <bsd.port.mk>
