# New ports collection makefile for:	audio/mp3splt
# Date created:				30.05.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	mp3splt
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	q@uni.de
COMMENT=	Utility to split mp3 and ogg files (via CUE sheets)

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		ogg.5:${PORTSDIR}/audio/libogg

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_TARGET:=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		mp3splt.1
PLIST_FILES=	bin/mp3splt bin/oggsplt

.include <bsd.port.mk>
