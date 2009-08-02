# ex:ts=8
# Ports collection makefile for:	gcc with gcj+AWT
# Date created:				17 April 2006
# Whom:					Maho Nakata <maho@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-withgcjawt

MAINTAINER=	maho@FreeBSD.org

MASTERDIR=	${.CURDIR}/../../lang/gcc42

DESCR=	${.CURDIR}/pkg-descr

WITH_JAVA_AWT=	yes
USE_XORG=	xtst xt xaw xmu

#weird libtool issue http://gcc.gnu.org/bugzilla/show_bug.cgi?id=28442
EXTRA_PATCHES+=	${.CURDIR}/files/patch-configure
USE_AUTOTOOLS=	libtool:22

.if ${MACHINE_ARCH} != i386
BROKEN=	Only for gcj supported platforms
.endif

pre-build:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${SRCDIR}/libjava/configure
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${SRCDIR}/libjava/classpath/configure

.include "${MASTERDIR}/Makefile"
