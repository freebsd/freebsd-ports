# New ports collection makefile for:	utah-glx
# Date created:         		13 September 1999
# Whom:                 		Marc E E van Woerkom  <van.woerkom@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	utah-glx
PORTVERSION=	0.9.20010504
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/mesa3d/g}
MASTER_SITE_SUBDIR=	sobomax
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		MesaLib-${MESA_VER}${EXTRACT_SUFX} \
		MesaDemos-${MESA_VER}${EXTRACT_SUFX}

MAINTAINER=	3d@FreeBSD.org
COMMENT=	A hardware OpenGL support for XFree86 X-Servers

BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83 \
		autoconf:${PORTSDIR}/devel/autoconf

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MESA_VER=	3.2.1

GLVER?=		14
GLUTVER?=	3

AGP_DEVICE=	/dev/agpgart

CFLAGS+=	-DAGP_DEVICE=\\\"${AGP_DEVICE}\\\"
CONFIGURE_SCRIPT=autogen.sh
CONFIGURE_ARGS=	--enable-extra \
		--with-mesa=${WRKDIR}/Mesa-${MESA_VER} \
		--sysconfdir=${PREFIX}/etc \
		--with-moduledir=${PREFIX}/lib/modules
CONFIGURE_ENV=	TCLSH="tclsh8.3"
MAKE_ENV=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"
PLIST_SUB=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"

.if defined(DEBUG)
CFLAGS+=	-g
CONFIGURE_ARGS+=--enable-debug
.endif

ALL_TARGET=	depend all

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} > 3
IGNORE=		"Requires XFree86 3.3.* - will not work with XFree86 4.*"
.endif

pre-build:
	@${FIND} ${WRKSRC} -type f | ${XARGS} grep -l linux/agpgart | \
		${XARGS} perl -pi -e "s|linux/agpgart|sys/agpio|"

pre-install:
.if exists(${PREFIX}/lib/libGL.so.${GLVER}) && !defined(GL_CHECK_OVERRIDE) && !defined(PACKAGE_BUILDING)
	@${ECHO_MSG}
	@${ECHO_MSG} "ERROR: It seems that another GL implementation currently installed in"
	@${ECHO_MSG} "       ${PREFIX}/lib/libGL.so.${GLVER}"
	@${ECHO_MSG}
	@${ECHO_MSG} "       You have to deinstall it prior to Utah-Glx installation."
	@${ECHO_MSG}
	@false
.endif

post-install:
.if exists(/usr/include/sys/agpio.h)
	@${ECHO_MSG}
	@${ECHO_MSG} "The module has been built with experimental AGP support. To use it you should"
	@${ECHO_MSG} "create device node for agp driver (cd /dev ; sh MAKEDEV agpgart) and enable"
	@${ECHO_MSG} "AGP support in ${PREFIX}/etc/glx.conf file."
	@${ECHO_MSG}
.endif
	${MKDIR} ${PREFIX}/share/doc/utah-glx
	${INSTALL_MAN} ${WRKSRC}/docs/README.* ${PREFIX}/share/doc/utah-glx

.include <bsd.port.post.mk>
