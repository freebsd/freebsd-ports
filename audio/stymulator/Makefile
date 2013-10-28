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

NO_STAGE=	yes
USE_DOS2UNIX=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAN1=		ymplayer.1 ym2wav.1
PLIST_FILES=	bin/ym2wav bin/ymplayer bin/stymulator man/man1/ymplayer.1.gz \
		man/man1/ym2wav.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ym2wav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ymplayer ${STAGEDIR}${PREFIX}/bin
	${LN} ${STAGEDIR}${PREFIX}/bin/ymplayer ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for f in ${MAN1}
	${INSTALL_MAN} ${FILESDIR}/${f} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
