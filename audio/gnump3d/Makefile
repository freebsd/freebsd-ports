# ex:ts=8
# Ports collection makefile for:	gnump3d
# Date created:			May 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnump3d
PORTVERSION=	1.0.p1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.0-pre1

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

PORTCOMMENT=	A streaming server for MP3, OGG vorbis, and other streamable audio files

USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/gnump3d

MAN1=	gnump3d.1 gnump3d.conf.1 gnump3d-top.1

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS=	vorbis.2:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-vorbis
.endif

pre-everything::
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile without Ogg/Vorbis support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITHOUT_VORBIS=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${TOUCH} -r ${WRKSRC}/aclocal.m4 ${WRKSRC}/aclocal.m4.time
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g ; \
		 s|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/aclocal.m4
# Avoid triggering automake
	@${TOUCH} -r ${WRKSRC}/aclocal.m4.time ${WRKSRC}/aclocal.m4

pre-configure:
.for dir in . mplib libltdl
	@cd ${WRKSRC}/${dir} && ${LOCALBASE}/bin/autoconf
.endfor

post-install:
	@${MKDIR} /var/log/gnump3d

.include <bsd.port.mk>
