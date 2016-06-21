# Created by: ijliao
# $FreeBSD$

PORTNAME=	soundgrab
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactively select and save sections of an audio file

RUN_DEPENDS=	sox:audio/sox \
		rawplay:audio/rawrec \
		oggenc:audio/vorbis-tools \
		flac:audio/flac \
		p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu \
		p5-Time-HiRes>=0:devel/p5-Time-HiRes

LICENSE=	GPLv2

USES=		perl5 shebangfix
SHEBANG_FILES=	src/soundgrab
NO_BUILD=	yes

PLIST_FILES=	bin/soundgrab man/man1/soundgrab.1.gz

do-install:
	@pod2man ${WRKSRC}/src/soundgrab ${WRKSRC}/src/soundgrab.1
	${INSTALL_SCRIPT} ${WRKSRC}/src/soundgrab ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/soundgrab.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
