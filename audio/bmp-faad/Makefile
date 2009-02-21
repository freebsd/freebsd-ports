# New ports collection makefile for:	bmp-faad
# Date created:			2 Sep, 2004
# Whom:				Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.6.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/faac
PKGNAMEPREFIX=	bmp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Beep Media Player (BMP) plugin for faad

LIB_DEPENDS=	faad.2:${PORTSDIR}/audio/faad \
		beep.2:${PORTSDIR}/multimedia/beep-media-player

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnometarget gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:15 autoheader:262 autoconf:262 libtool:15
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
PLIST_FILES=	lib/bmp/Input/libmp4.so

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/AC_CONFIG_FILES(plugins/d' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|"faad.h"|<faad.h>|g ; \
		 s|<xmms/|<bmp/|g' ${WRKSRC}/plugins/xmms/src/mp4_utils.c
	@${ECHO_CMD} "SUBDIRS = common" > ${WRKSRC}/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
		&& ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake

post-build:
	cd ${WRKSRC}/plugins/xmms/src && ${CC} ${CFLAGS} -fPIC -shared \
		-DHAVE_BMP -I../../../common/mp4ff -I${LOCALBASE}/include \
		`pkg-config --cflags bmp` *.c -o libmp4.so \
		../../../common/mp4ff/.libs/libmp4ff.a \
		-L${LOCALBASE}/lib -lfaad \
		`pkg-config --libs bmp`

do-install:
	${INSTALL_DATA} ${WRKSRC}/plugins/xmms/src/libmp4.so \
		${PREFIX}/lib/bmp/Input

.include <bsd.port.post.mk>
