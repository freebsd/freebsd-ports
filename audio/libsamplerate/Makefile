# New ports collection makefile for:	libsamplerate
# Date created:				2 February 2003
# Whom:			<dmagda+libsamplerate@ee.ryerson.ca>
#
# $FreeBSD$
#

PORTNAME=	libsamplerate
PORTVERSION=	0.0.14
CATEGORIES=	audio
MASTER_SITES= 	http://www.mega-nerd.com/SRC/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secret Rabbit Code is a Sample Rate Converter for audio

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-gcc-pipe
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

PORTDOCS=	SRC.png SRC.css index.html license.html history.html \
		download.html lists.html quality.html win32.html \
		api.html api_simple.html api_full.html api_misc.html

post-patch:
	@${REINPLACE_CMD} -e \
		's|libdir[)]/pkgconfig|prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
