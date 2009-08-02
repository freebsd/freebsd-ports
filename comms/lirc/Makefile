# New ports collection makefile for:	lirc
# Date created:		4 January 2003
# Whom:			Mike Heffner <mikeh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lirc
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lirc

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	Linux Infared Remote Control

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=		--enable-sandboxed --with-devdir=/var/run/lirc
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

OPTIONS=	IRMAN "Build with libirman support" On

USE_RC_SUBR=	lircd.sh

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libvga.so.1)
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	SMODE2=
.else
PLIST_SUB+=	SMODE2="@comment "
.endif

.if defined(WITH_IRMAN)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libirman.a:${PORTSDIR}/comms/libirman
CONFIGURE_ARGS+=	--with-driver=irman --with-driver=dvico
.else
CONFIGURE_ARGS+=	--with-driver=any --with-driver=dvico
.endif

MAN1=		ircat.1 irexec.1 irpty.1 irrecord.1 irsend.1 irw.1 \
		irxevent.1 lircrcd.1 mode2.1 smode2.1 xmode2.1
MAN8=		lircd.8 lircmd.8

post-install:
	@${MKDIR} /var/run/lirc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
