# ex:ts=8
# Ports collection makefile for:	soundgrab
# Date created:			May 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	soundgrab
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Interactively select and save sections of an audio file

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		rawplay:${PORTSDIR}/audio/rawrec \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	soundgrab.1
PLIST_FILES=	bin/soundgrab

do-install:
	@pod2man ${WRKSRC}/src/soundgrab ${WRKSRC}/src/soundgrab.1
	${INSTALL_SCRIPT} ${WRKSRC}/src/soundgrab ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/soundgrab.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
