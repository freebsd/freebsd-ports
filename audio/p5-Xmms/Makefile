# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	Xmms
PORTVERSION=	0.12
PORTREVISION=	3
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive remote control shell for xmms

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl

USES=		perl5
USE_PERL5=	configure
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|MPEG::MP3Info|MP3::Info|g' \
		${WRKSRC}/Makefile.PL ${WRKSRC}/Remote/Remote.pm \
		${WRKSRC}/lib/Bundle/Xmms.pm ${WRKSRC}/lib/Xmms.pm
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/SongChange/Makefile.PL

.include <bsd.port.mk>
