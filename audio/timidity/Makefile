# $FreeBSD$

PORTNAME=	timidity
PORTVERSION=	0.2i
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES+=	http://www.onicos.com/staff/iz/timidity/dist/:timidity
DISTFILES+=	${DISTNAME}.tar.gz:timidity
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI to PCM software synthesizer

CONFLICTS=	timidity++-2.*

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias ncurses
TIINS=		goemon.tgz
INSTALL_TARGET=	install.all

OPTIONS_DEFINE=	GUSPAT
GUSPAT_DESC=	Use audio/guspat instead of included sound fonts (goemon)

.include <bsd.port.options.mk>

# Set up sound fonts from audio/guspat.
.if ${PORT_OPTIONS:MGUSPAT}
RUN_DEPENDS+=	${LOCALBASE}/share/guspat/power.cfg:audio/guspat
TDIR=		${LOCALBASE}/share/timidity
TCONFIG=	timidity.cfg-guspat
PLIST_SUB+=	GOEMON="@comment "
.else
# Set up default sound fonts (goemon).
MASTER_SITES+=	http://www.anime.net/~goemon/timidity/:tiins
DISTFILES+=	${TIINS}:tiins
TDIR=		${PREFIX}/lib/timidity
TCONFIG=	goemon.cfg
PLIST_SUB+=	GOEMON=""
.endif

post-patch:
	${REINPLACE_CMD} -e 's,machine/soundcard.h,sys/soundcard.h,' \
		${WRKSRC}/linux_a.c
	${REINPLACE_CMD} -e 's|%%TDIR%%|${TDIR}| ; s|%%TCONFIG%%|${TCONFIG}|' \
		${WRKSRC}/timidity.cfg

post-install:
.if ! ${PORT_OPTIONS:MGUSPAT}
	cd ${STAGEDIR}${PREFIX}/lib/timidity && \
	${TAR} --no-same-owner --no-same-permissions -zxf ${DISTDIR}/${TIINS} && \
	${REINPLACE_CMD} -i "" -e 's,dir goemon,dir ${PREFIX}/lib/timidity/goemon,' \
		goemon.cfg
.endif

.include <bsd.port.mk>
