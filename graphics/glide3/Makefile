# New ports collection makefile for:	glide3
# Date created:				31 Mar 2001
# Whom:					Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	glide3
PORTVERSION=	20020113
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://people.freebsd.org/~anholt/dri/files/
DISTNAME=	Glide3-FreeBSD-${PORTVERSION}
#The distfile is CVS Glide3-FreeBSD branch with */glide3/tests/* removed

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to support 3dfx Voodoo3/4/5/Banshee with the DRI

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 xxf86dga xxf86vm
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake autoconf libtool
AUTOMAKE_ARGS=	-a

MAKEFILE=	makefile.autoconf
WRKSRC=		${WRKDIR}/Glide3

# This Glide3 does not work on alpha, and I don't expect it to work right
# on other non-i386 without patches.  Further development is going on in
# x11-servers/driglide.
ONLY_FOR_ARCHS=		i386

# Glide3 DOES NOT work with CFLAGS greater than -O2
CFLAGS+=	-O

OPTIONS=	VOODOO3 "Enable this if you have a Voodoo3 or Banshee card" off

.include <bsd.port.pre.mk>

.if defined(WITH_VOODOO3)
PKGNAMESUFFIX=	-v3
CONFIGURE_ARGS+=	--enable-fx-glide-hw=h3
.else
PKGNAMESUFFIX=	-v5
.endif

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal
	@${REINPLACE_CMD} -e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e \
		's|(float \*)pointers +=|pointers += sizeof(float *) *|' \
		${WRKSRC}/h5/glide3/src/gaa.c \
		${WRKSRC}/h5/glide3/src/gdraw.c \
		${WRKSRC}/h5/glide3/src/distrip.c

.include <bsd.port.post.mk>
