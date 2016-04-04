# Created by: Zane C. Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	MP3-Tag-Utils
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Assorted utilities for manipulating MP3 files via MP3::Tag

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MP3-Tag>=1.13:audio/p5-MP3-Tag \
		p5-Text-NeatTemplate>=0.10.01:textproc/p5-Text-NeatTemplate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	bin/mp3rename bin/mp3show bin/mp3tag

.include <bsd.port.mk>
