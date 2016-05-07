# Created by: Mike Heffner <mikeh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lirc
PORTVERSION=	0.9.0
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/LIRC/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux Infrared Remote Control

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:multimedia/v4l_compat

INSTALL_TARGET=	install-strip
USES=		alias autoreconf gmake libtool python tar:bzip2
USE_XORG=	sm x11
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sandboxed --with-devdir=/var/run/lirc \
		--sysconfdir=${PREFIX}/etc
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	MINIMAL DEBUG UARTLIRC DOCS EXAMPLES

MINIMAL_DESC=	Build with minmal dependencies
UARTLIRC_DESC=	Install serial LIRC driver

USE_RC_SUBR=	lircd
PORTDOCS=	html images irxevent.keys lirc.css lirc.hwdb
PORTEXAMPLES=	remotes
SUB_FILES=	pkg-message lircd.conf

.if exists(${LOCALBASE}/lib/libvga.so.1)
LIB_DEPENDS+=	libvga.so:graphics/svgalib
PLIST_SUB+=	SMODE2=
.else
PLIST_SUB+=	SMODE2="@comment "
.endif

MINIMAL_LIB_DEPENDS_OFF=		libftdi.so:devel/libftdi \
			libirman.so:comms/libirman
MINIMAL_CONFIGURE_OFF=	--with-driver=userspace
MINIMAL_CONFIGURE_ON=	--with-driver=dvico

DEBUG_CONFIGURE_ENABLE=	debug

UARTLIRC_RUN_DEPENDS=		uartlirc>=0.3:comms/uartlirc

post-patch:
	@${REINPLACE_CMD} \
		-e 's/`$${LIBUSB_CONFIG} --libs`/-lusb/' \
		-e 's/`$${LIBUSB_CONFIG} --cflags`//' \
		${WRKSRC}/configure.ac

post-install-DOCS-on:
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${INSTALL_DATA} irxevent.keys lirc.css lirc.hwdb ${STAGEDIR}${DOCSDIR}/)
post-install-EXAMPLES-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} remotes ${STAGEDIR}${EXAMPLESDIR}/)
post-install:
	@${INSTALL_DATA} ${WRKDIR}/lircd.conf ${STAGEDIR}${PREFIX}/etc/lircd.conf.sample
	@${MKDIR} ${STAGEDIR}/var/run/lirc

.include <bsd.port.mk>
