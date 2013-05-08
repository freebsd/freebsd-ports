# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stymulator
DISTVERSION=	0.21a
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://atariarea.krap.pl/stymulator/files/ \
		CRITICAL
DISTNAME=	STYMulator-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line Yamaha YM2149 (.ym) chiptune player

LICENSE=	GPLv2

USE_DOS2UNIX=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAN1=		ymplayer.1 ym2wav.1
PLIST_FILES=	bin/ym2wav bin/ymplayer bin/stymulator

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ym2wav ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ymplayer ${PREFIX}/bin
	${LN} ${PREFIX}/bin/ymplayer ${PREFIX}/bin/${PORTNAME}
.for f in ${MAN1}
	${INSTALL_MAN} ${FILESDIR}/${f} ${MAN8PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
