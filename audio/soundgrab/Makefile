# Created by: ijliao
# $FreeBSD$

PORTNAME=	soundgrab
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Interactively select and save sections of an audio file

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		rawplay:${PORTSDIR}/audio/rawrec \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes

LICENSE=	GPLv2

USES=		perl5
NO_STAGE=	yes
NO_BUILD=	yes

MAN1=	soundgrab.1
PLIST_FILES=	bin/soundgrab

do-install:
	@pod2man ${WRKSRC}/src/soundgrab ${WRKSRC}/src/soundgrab.1
	${INSTALL_SCRIPT} ${WRKSRC}/src/soundgrab ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/soundgrab.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
