# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	lash
PORTVERSION=	0.5.4
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Session management system for JACK audio applications

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libjack.so:audio/jack \
		libdssialsacompat.so:audio/libdssialsacompat \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		gmake gnome libtool pathfix pkgconfig
USE_GNOME=	gtk20 libxml2 gdkpixbuf2 cairo
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa-midi
USE_LDCONFIG=	yes
LIBS=		-luuid
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include/dssi -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	READLINE PYTHON DOCS
OPTIONS_DEFAULT=READLINE
OPTIONS_SUB=	yes

PYTHON_DESC=	Build pylash
PYTHON_USES=	python
PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30
PYTHON_BINARY_ALIAS=	swig=swig3.0
PYTHON_CONFIGURE_ENABLE=pylash
PYTHON_BROKEN=	Does not package

READLINE_USES=		readline
READLINE_CONFIGURE_ENV_OFF=	vl_cv_lib_readline=no

DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html
DOCS_CONFIGURE_ENV_OFF=	ac_cv_prog_lash_texi2html=no

post-patch:
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/texi2html/s|--number||' ${WRKSRC}/docs/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/lash-manual-html-one-page/lash-manual.html \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
