# ex:ts=8
# Ports collection makefile for:	soundgrab
# Date created:			May 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	soundgrab
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactively select and save sections of an audio file

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		rawplay:${PORTSDIR}/audio/rawrec \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac \
		${PERL_SITELIBDIR}/${PERL_VER}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		${PERL_SITELIBDIR}/${PERL_VER}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

PERL_SITELIBDIR=	${LOCALBASE}/lib/perl5/site_perl

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	soundgrab.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/soundgrab ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/soundgrab.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
