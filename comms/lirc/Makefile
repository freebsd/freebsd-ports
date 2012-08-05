# New ports collection makefile for:	lirc
# Date created:		4 January 2003
# Whom:			Mike Heffner <mikeh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lirc
PORTVERSION=	0.9.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/LIRC/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p1/-pre1/}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Linux Infrared Remote Control

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:${PORTSDIR}/multimedia/v4l_compat

USE_AUTOTOOLS=	libtool automake autoheader aclocal autoconf
ACLOCAL_ARGS=	-I "${ACLOCAL_DIR}" -I ${LOCALBASE}/share/aclocal
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11
USE_PYTHON=	yes
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=		--enable-sandboxed --with-devdir=/var/run/lirc \
			--sysconfdir=${PREFIX}/etc
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	MINIMAL DEBUG UARTLIRC

MINIMAL_DESC=	Build with minmal dependencies
UARTLIRC_DESC=	Install serial LIRC driver

USE_RC_SUBR=	lircd
PORTDOCS=	html images irxevent.keys lirc.css lirc.hwdb
PORTEXAMPLES=	remotes
SUB_FILES=	pkg-message lircd.conf

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libvga.so.1)
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	SMODE2=
.else
PLIST_SUB+=	SMODE2="@comment "
.endif

.if empty(PORT_OPTIONS:MMINIMAL)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libirman.a:${PORTSDIR}/comms/libirman
LIB_DEPENDS+=		ftdi:${PORTSDIR}/devel/libftdi
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

MAN1=		ircat.1 irexec.1 irpty.1 irrecord.1 irsend.1 irw.1 \
		irxevent.1 lircrcd.1 mode2.1 smode2.1 xmode2.1
MAN8=		lircd.8 lircmd.8

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${INSTALL_DATA} irxevent.keys lirc.css lirc.hwdb ${DOCSDIR}/)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} remotes ${EXAMPLESDIR}/)
.endif
	@${INSTALL_DATA} ${WRKDIR}/lircd.conf ${PREFIX}/etc/lircd.conf.sample
	@if [ ! -f ${PREFIX}/etc/lircd.conf ]; then \
	    ${INSTALL_DATA} ${WRKDIR}/lircd.conf ${PREFIX}/etc; \
	fi
	@${MKDIR} /var/run/lirc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
