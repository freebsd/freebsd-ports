# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	lash
PORTVERSION=	0.5.4
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Session management system for JACK audio applications

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		libdssialsacompat.so:${PORTSDIR}/audio/libdssialsacompat \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USES=		gmake pathfix pkgconfig libtool
USE_GNOME=	gtk20 libxml2
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
PYTHON_BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
PYTHON_CONFIGURE_OFF=	--disable-pylash

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
.else
CONFIGURE_ENV+=	vl_cv_lib_readline=no
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
.else
CONFIGURE_ENV+=	ac_cv_prog_lash_texi2html=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/texi2html/s|--number||' ${WRKSRC}/docs/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/lash-manual-html-one-page/lash-manual.html \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
