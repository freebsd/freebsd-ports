# New ports collection makefile for:	glide3
# Date created:				31 Mar 2001
# Whom:					Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	glide3
PORTVERSION=	20020113
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://people.freebsd.org/~anholt/dri/files/
.ifdef WITH_VOODOO3
PKGNAMESUFFIX=	-v3
.else
PKGNAMESUFFIX=	-v5
.endif
DISTNAME=	Glide3-FreeBSD-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2
#The distfile is CVS Glide3-FreeBSD branch with */glide3/tests/* removed

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to support 3dfx Voodoo3/4/5/Banshee with the DRI

USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/Glide3
USE_X_PREFIX=		yes
INSTALLS_SHLIB=		yes
USE_INC_LIBTOOL_VER=	13
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
AUTOMAKE_ARGS=		-a
USE_GMAKE=		yes
MAKEFILE=		makefile.autoconf

# This Glide3 does not work on alpha, and I don't expect it to work right
# on other non-i386 without patches.  Further development is going on in
# x11-servers/driglide.
ONLY_FOR_ARCHS=		i386

# Glide3 DOES NOT work with CFLAGS greater than -O2
CFLAGS+=	-O

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

.ifdef WITH_VOODOO3
CONFIGURE_ARGS+=	--enable-fx-glide-hw=h3
.else
pre-everything::
	@${ECHO_MSG} "Use make -DWITH_VOODOO3 if you have a Voodoo3 or Banshee card"
.endif

pre-configure:
	cd $(WRKSRC) && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal

.include <bsd.port.post.mk>
