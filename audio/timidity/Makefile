# $FreeBSD$

PORTNAME=	timidity
PORTVERSION=	0.2i
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES+=	http://www.onicos.com/staff/iz/timidity/dist/:timidity
DISTFILES+=	${DISTNAME}.tar.gz:timidity

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI to PCM software synthesizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	timidity++-2.*

USES=		alias ncurses
INSTALL_TARGET=	install.all

OPTIONS_SINGLE=	FONTS
OPTIONS_SINGLE_FONTS=	GOEMON GUSPAT
OPTIONS_DEFAULT=GOEMON
OPTIONS_SUB=	yes

FONTS_DESC=		Default sound fonts

GUSPAT_DESC=		Use from audio/guspat port
GUSPAT_RUN_DEPENDS=	${LOCALBASE}/share/guspat/power.cfg:audio/guspat
GUSPAT_VARS=		TDIR="${LOCALBASE}/share/timidity" \
			TCONFIG=timidity.cfg-guspat

GOEMON_DESC=		Bundle from Goemon's patchkit #'
GOEMON_MASTER_SITES=	http://www.anime.net/~goemon/timidity/:tiins
GOEMON_DISTFILES=	goemon.tgz:tiins
GOEMON_VARS=		TDIR="${PREFIX}/lib/timidity" \
			TCONFIG=goemon.cfg

post-patch:
	${REINPLACE_CMD} -e 's,machine/soundcard.h,sys/soundcard.h,' \
		${WRKSRC}/linux_a.c
	${REINPLACE_CMD} -e 's|%%TDIR%%|${TDIR}| ; s|%%TCONFIG%%|${TCONFIG}|' \
		${WRKSRC}/timidity.cfg

post-patch-GOEMON-on:
	${REINPLACE_CMD} -i '' -e '/^dir/s,goemon,${TDIR}/&,' \
		${WRKDIR}/${TCONFIG}

post-install-GOEMON-on:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} "goemon*" ${STAGEDIR}${TDIR})

.include <bsd.port.mk>
