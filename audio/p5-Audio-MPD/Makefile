# Created by: chinsan
# $FreeBSD$

PORTNAME=	Audio-MPD
PORTVERSION=	1.120610
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class to talk to MPD (Music Player Daemon) servers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Audio-MPD-Common>=0:${PORTSDIR}/audio/p5-Audio-MPD-Common \
		p5-Getopt-Euclid>=0:${PORTSDIR}/devel/p5-Getopt-Euclid \
		p5-IO-Socket-IP>=0:${PORTSDIR}/net/p5-IO-Socket-IP \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Has-Sugar>=0:${PORTSDIR}/devel/p5-MooseX-Has-Sugar \
		p5-MooseX-SemiAffordanceAccessor>=0:${PORTSDIR}/devel/p5-MooseX-SemiAffordanceAccessor \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Corpus-Audio-MPD>=1.113282:${PORTSDIR}/audio/p5-Test-Corpus-Audio-MPD

USES=		perl5
USE_PERL5=	modbuild

MAN1=		mpd-dynamic.1 \
		mpd-rate.1
MAN3=		Audio::MPD.3 \
		Audio::MPD::Collection.3 \
		Audio::MPD::Playlist.3 \
		Audio::MPD::Types.3

.include <bsd.port.mk>
