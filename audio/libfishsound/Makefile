PORTNAME=	libfishsound
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://ftp.osuosl.org/pub/xiph/releases/libfishsound/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Programming interface to decode/encode audio data
WWW=		https://www.xiph.org/fishsound/ \
		https://gitlab.xiph.org/xiph/libfishsound

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libspeex.so:audio/speex \
		libvorbis.so:audio/libvorbis

USES=		libtool pkgconfig

CONFIGURE_ARGS=	ac_cv_prog_HAVE_DOXYGEN=false
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS
DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile.in

.include <bsd.port.mk>
