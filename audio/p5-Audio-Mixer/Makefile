# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	Audio-Mixer
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for Sound Mixer control

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5 shebangfix
SHEBANG_FILES=	volume.pl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Audio/Mixer/Mixer.so

.include <bsd.port.mk>
