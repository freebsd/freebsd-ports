# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	MP3-Find
PORTVERSION=	0.07
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search and sort MP3 files based on their ID3 tags

BUILD_DEPENDS=	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
