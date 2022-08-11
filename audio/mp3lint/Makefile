PORTNAME=	mp3lint
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	https://erislabs.net/ianb/projects/mp3lint/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Configurable tool to check collections of audio files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Pod-Parser>=0:textproc/p5-Pod-Parser \
		${RUN_DEPENDS}
RUN_DEPENDS=	libmp3-archive-perl>=0:audio/libmp3-archive-perl

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALLSYSCONFDIR/ s|/etc|${PREFIX}&|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
