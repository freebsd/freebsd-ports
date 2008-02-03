# New ports collection makefile for:	audio/mp3splt
# Date created:				30.05.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	mp3splt
PORTVERSION=	2.1c
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	Utility to split mp3 and ogg files (via CUE sheets)

OPTIONS=	VORBIS	"Ogg Vorbis support" On

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.5:${PORTSDIR}/audio/libogg
.else
CONFIGURE_ARGS+=--disable-ogg
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		mp3splt.1
PLIST_FILES=	bin/mp3splt bin/oggsplt

.include <bsd.port.post.mk>
