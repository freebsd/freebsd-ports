# New ports collection makefile for:	p5-MP3-Find
# Date created:				2006-07-12
# Whom:					Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	MP3-Find
PORTVERSION=	0.06
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
#MASTER_SITE_SUBDIR=	../../authors/id/P/PE/PEICHMAN
MASTER_SITE_SUBDIR=	MP3
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Search and sort MP3 files based on their ID3 tags

BUILD_DEPENDS=	${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN1=	mp3db.1 mp3find.1
MAN3=	MP3::Find::DB.3 MP3::Find::Filesystem.3 MP3::Find.3 MP3::Find::Base.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
