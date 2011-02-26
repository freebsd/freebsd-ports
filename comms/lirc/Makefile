# New ports collection makefile for:	lirc
# Date created:		4 January 2003
# Whom:			Mike Heffner <mikeh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lirc
PORTVERSION=	0.9.0p1
PORTREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	http://lirc.org/software/snapshots/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p1/-pre1/}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Linux Infrared Remote Control

USE_AUTOTOOLS=	libtool automake autoheader aclocal autoconf
ACLOCAL_ARGS=	-I "${ACLOCAL_DIR}" -I ${LOCALBASE}/share/aclocal
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=		--enable-sandboxed --with-devdir=/var/run/lirc
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

OPTIONS=	MINIMAL "Build with minmal dependencies" Off \
		DEBUG "Build debug version" Off

USE_RC_SUBR=	lircd.sh
PORTDOCS=	html images irxevent.keys lirc.css lirc.hwdb
PORTEXAMPLES=	remotes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libvga.so.1)
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	SMODE2=
.else
PLIST_SUB+=	SMODE2="@comment "
.endif

.if defined(WITHOUT_MINIMAL)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libirman.a:${PORTSDIR}/comms/libirman
LIB_DEPENDS+=		ftdi.18:${PORTSDIR}/devel/libftdi
CONFIGURE_ARGS+=	--with-driver=userspace
.else
CONFIGURE_ARGS+=	--with-driver=dvico
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

MAN1=		ircat.1 irexec.1 irpty.1 irrecord.1 irsend.1 irw.1 \
		irxevent.1 lircrcd.1 mode2.1 smode2.1 xmode2.1
MAN8=		lircd.8 lircmd.8

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} images ${DOCSDIR}/)
	@(cd ${WRKSRC}/doc && ${INSTALL_DATA} irxevent.keys lirc.css lirc.hwdb ${DOCSDIR}/)
.endif
.if !defined(NOPORTEXAMPLES)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} remotes ${EXAMPLESDIR}/)
.endif
	@${MKDIR} /var/run/lirc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
