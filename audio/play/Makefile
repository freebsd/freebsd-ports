PORTNAME=	play
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	PORTS_JP

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple audio file player

LICENSE=	NONE

USES=		uidfix

MAKE_ARGS=	CFLAGS="${CFLAGS}" MANDIR="${PREFIX}/man/ja/man" BINDIR="${PREFIX}/bin"
# XXX PIE static libraries are not supported by base system /usr/share/mk
MAKE_ARGS+=	WITHOUT_PIE=true

CONFLICTS=	sox

PLIST_FILES=	bin/play man/ja/man1/play.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
.for file in play_audio.c mixer_ctl.c encode_sun.c speed.c
	@${REINPLACE_CMD} '/soundcard\.h/s,machine,sys,' ${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
