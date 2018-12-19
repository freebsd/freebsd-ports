# Created by: Mike Heffner <mikeh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lirc
PORTVERSION=	0.9.0
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/LIRC/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux Infrared Remote Control

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		alias autoreconf gmake libtool localbase python tar:bzip2
USE_XORG=	sm x11 ice
USE_CSTD=	gnu89
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sandboxed --with-devdir=/var/run/lirc \
		--sysconfdir=${PREFIX}/etc

USE_RC_SUBR=	lircd
PORTDOCS=	html images irxevent.keys lirc.css lirc.hwdb
PORTEXAMPLES=	remotes
SUB_FILES=	pkg-message lircd.conf

OPTIONS_DEFINE=	MINIMAL DEBUG UARTLIRC DOCS EXAMPLES
OPTIONS_DEFINE_i386=	SMODE2 # requires svgalib which is...
OPTIONS_DEFINE_amd64=	SMODE2 # ...only available on x86
OPTIONS_SUB=	yes

MINIMAL_DESC=	Build with minimal dependencies
UARTLIRC_DESC=	Install serial LIRC driver
SMODE2_DESC=	Build smode2 (shows signal waveform), requires svgalib

MINIMAL_LIB_DEPENDS_OFF=libftdi.so:devel/libftdi \
			libirman.so:comms/libirman
MINIMAL_CONFIGURE_OFF=	--with-driver=userspace
MINIMAL_CONFIGURE_ON=	--with-driver=dvico

DEBUG_CONFIGURE_ENABLE=	debug

SMODE2_LIB_DEPENDS=	libvga.so:graphics/svgalib
SMODE2_PLIST_FILES=	bin/smode2

UARTLIRC_RUN_DEPENDS=	uartlirc>=0.3:comms/uartlirc

post-patch:
	@${REINPLACE_CMD} \
		-e 's/`$${LIBUSB_CONFIG} --libs`/-lusb/' \
		-e 's/`$${LIBUSB_CONFIG} --cflags`//' \
		${WRKSRC}/configure.ac

post-install:
	${INSTALL_DATA} ${WRKDIR}/lircd.conf ${STAGEDIR}${PREFIX}/etc/lircd.conf.sample
	@${MKDIR} ${STAGEDIR}/var/run/lirc

post-install-MINIMAL-on:
	# bacause --with-driver is specified, it installs remotes/dvico/lircd.conf.fusionHDTV to etc/lircd/
	# remove to not break the plist, but remote configs handling should probably be fixed...
	@${RM} -r ${STAGEDIR}${PREFIX}/etc/lirc

post-install-DOCS-on:
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "html images irxevent.keys lirc.css lirc.hwdb" ${STAGEDIR}${DOCSDIR}/)

post-install-EXAMPLES-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} remotes ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
