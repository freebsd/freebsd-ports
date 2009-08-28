# New ports collection makefile for:	p5-Audio-MPD
# Date created:				28 Oct 2008
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Audio-MPD
PORTVERSION=	0.19.6
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class to talk to MPD (Music Player Daemon) servers

BUILD_DEPENDS=	p5-Audio-MPD-Common>=0:${PORTSDIR}/audio/p5-Audio-MPD-Common \
		p5-Getopt-Euclid>=0:${PORTSDIR}/devel/p5-Getopt-Euclid \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		mpd-dynamic.1
MAN3=		Audio::MPD.3 Audio::MPD::Collection.3 \
		Audio::MPD::Playlist.3 Audio::MPD::Test.3

.include <bsd.port.mk>
