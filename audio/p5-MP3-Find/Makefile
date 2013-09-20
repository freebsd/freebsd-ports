# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	MP3-Find
PORTVERSION=	0.07
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Search and sort MP3 files based on their ID3 tags

BUILD_DEPENDS=	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
NO_STAGE=	yes
USE_PERL5=	configure

MAN1=		mp3db.1 mp3find.1
MAN3=		MP3::Find.3 \
		MP3::Find::Base.3 \
		MP3::Find::DB.3 \
		MP3::Find::Filesystem.3

.include <bsd.port.mk>
