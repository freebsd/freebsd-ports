# Created by: Mike Heffner <mikeh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lirc
PORTVERSION=	0.9.0
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/LIRC/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p1/-pre1/}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Linux Infrared Remote Control

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat

INSTALL_TARGET=	install-strip
USES=		alias gmake libtool python tar:bzip2
USE_AUTOTOOLS=	libtoolize automake autoheader aclocal autoconf
AUTOMAKE_ARGS=	-a -c -f
USE_XORG=	sm x11
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

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

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libvga.so.1)
LIB_DEPENDS+=	libvga.so:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	SMODE2=
.else
PLIST_SUB+=	SMODE2="@comment "
.endif

.if empty(PORT_OPTIONS:MMINIMAL)
LIB_DEPENDS+=		libftdi.so:${PORTSDIR}/devel/libftdi \
			libirman.so:${PORTSDIR}/comms/libirman
CONFIGURE_ARGS+=	--with-driver=userspace
.else
CONFIGURE_ARGS+=	--with-driver=dvico
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MUARTLIRC}
RUN_DEPENDS+=		uartlirc>=0.3:${PORTSDIR}/comms/uartlirc
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's/`$${LIBUSB_CONFIG} --libs`/-lusb/' \
		-e 's/`$${LIBUSB_CONFIG} --cflags`//' \
		${WRKSRC}/configure.ac

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${INSTALL_DATA} irxevent.keys lirc.css lirc.hwdb ${STAGEDIR}${DOCSDIR}/)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} remotes ${STAGEDIR}${EXAMPLESDIR}/)
.endif
	@${INSTALL_DATA} ${WRKDIR}/lircd.conf ${STAGEDIR}${PREFIX}/etc/lircd.conf.sample
	@${MKDIR} ${STAGEDIR}/var/run/lirc

.include <bsd.port.post.mk>
