# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	lash
PORTVERSION=	0.5.4
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Session management system for JACK audio applications

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		libdssialsacompat.so:${PORTSDIR}/audio/libdssialsacompat \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

OPTIONS_DEFINE=	READLINE DOCS
OPTIONS_DEFAULT=READLINE

USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa-midi
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/dssi -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
PLIST_SUB+=	READLINE=""
.else
CONFIGURE_ENV+=	vl_cv_lib_readline=no
PLIST_SUB+=	READLINE="@comment "
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
