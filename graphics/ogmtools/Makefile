# New ports collection makefile for:	ogmtools
# Date created:		Sun Oct 20 13:06:13 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ogmtools
PORTVERSION=	0.9.60
CATEGORIES=	graphics audio
MASTER_SITES=	http://www.bunkus.org/videotools/ogmtools/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.{2})$/\1/}

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis \
		vorbisenc.2:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg-prefix=${LOCALBASE} \
  		--with-vorbis-prefix=${LOCALBASE}

MAN1=		ogmdemux.1 ogminfo.1 ogmmerge.1 ogmsplit.1

post-patch:
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'

post-configure:
# malloc.h -> stdlib.h
	@${FIND} ${WRKSRC} -type f | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!malloc.h!stdlib.h!'

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libdvdread.so.2)
WITH_DVDREAD=yes
.endif

.ifdef(WITH_DVDREAD)
LIB_DEPENDS+=	dvdread.2:${PORTSDIR}/graphics/libdvdread

CONFIGURE_ARGS+=	--with-dvdread \
			--with-dvdread-includes=${LOCALBASE} \
			--with-dvdread-libs=${LOCALBASE}
PLIST_SUB+=	WITH_DVDREAD=""

MAN1+=	dvdxchap.1
.else
CONFIGURE_ARGS+=	--without-dvdread
PLIST_SUB+=	WITH_DVDREAD="@comment "
.endif

pre-everything::
.ifndef(WITH_DVDREAD)
	@${ECHO_MSG} "===> Define WITH_DVDREAD in order to be able to 'Extract chapter information from DVDs'"
.endif

.include <bsd.port.post.mk>
