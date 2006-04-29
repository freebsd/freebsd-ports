# New ports collection makefile for:	lirc
# Date created:		4 January 2003
# Whom:			Mike Heffner <mikeh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lirc
PORTVERSION=	0.7.2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lirc

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	Linux Infared Remote Control

USE_XLIB=	yes
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--disable-manage-devices --with-devdir=/var/lirc

OPTIONS=	IRMAN "Build with libirman support" On

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	SMODE2=
.else
PLIST_SUB+=	SMODE2="@comment "
.endif

.if defined(WITH_IRMAN)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libirman.a:${PORTSDIR}/comms/libirman
CONFIGURE_ARGS+=	--with-driver=irman
.if ${OSVERSION} >= 500041
# These are already included in the getopt_long case on < 50041
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif
.else
CONFIGURE_ARGS+=	--with-driver=any
.endif

MAN1=		ircat.1 irexec.1 irpty.1 irrecord.1 irsend.1 irw.1 \
		irxevent.1 mode2.1 smode2.1 xmode2.1
MAN8=		lircd.8 lircmd.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
