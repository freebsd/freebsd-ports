# Created by: Dominic Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	Audio-Wav
PORTVERSION=	0.13
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules for reading and writing Microsoft WAV files

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Audio::Wav.3 Audio::Wav::Read.3 Audio::Wav::Write.3

.include <bsd.port.mk>
