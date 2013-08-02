# New ports collection makefile for:	Xmms
# Date created:			10 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
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

MAN3=		Bundle::Xmms.3 \
		Xmms.3 \
		Xmms::Config.3 \
		Xmms::Remote.3 \
		Xmms::SongChange.3

post-patch:
	@${REINPLACE_CMD} -e 's|MPEG::MP3Info|MP3::Info|g' \
		${WRKSRC}/Makefile.PL ${WRKSRC}/Remote/Remote.pm \
		${WRKSRC}/lib/Bundle/Xmms.pm ${WRKSRC}/lib/Xmms.pm
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/SongChange/Makefile.PL

.include <bsd.port.mk>
