# New ports collection makefile for:    p5-WebService-MusicBrainz
# Date created:         2009-12-22
# Whom:                 Tobias Rehbein <tobias.rehbein@web.de>
#
# $FreeBSD$
#

PORTNAME=	MusicBrainz-DiscID
PORTVERSION=	0.03
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Perl interface for the MusicBrainz libdiscid library

BUILD_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod
LIB_DEPENDS=	discid.2:${PORTSDIR}/audio/libdiscid
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	pkgconfig
PERL_MODBUILD=	yes

MAN3=		MusicBrainz::DiscID.3

.include <bsd.port.mk>
