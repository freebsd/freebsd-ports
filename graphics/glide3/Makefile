# New ports collection makefile for:	glide3
# Date created:				31 Mar 2001
# Whom:					Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	glide3
PORTVERSION=	20020113
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

MAINTAINER=	anholt@freebsd.org

USE_BZIP2=		yes
WRKSRC=			${WRKDIR}/Glide3
USE_X_PREFIX=		yes
XFREE86_VERSION=	4
INSTALLS_SHLIB=		yes
USE_LIBTOOL=		yes
USE_AUTOMAKE_VER=	14
AUTOMAKE_ARGS=		-a
USE_GMAKE=		yes
MAKEFILE=		makefile.autoconf

#Glide3 DOES NOT work with CFLAGS greater than -O2
CFLAGS+= -O

.ifdef WITH_VOODOO3
CONFIGURE_ARGS+=	--enable-fx-glide-hw=h3
.else
pre-everything::
	@${ECHO_MSG} "Use make -DWITH_VOODOO3 if you have a Voodoo3 or Banshee card"
.endif

post-extract:
	cd $(WRKSRC) && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal

.include <bsd.port.mk>
