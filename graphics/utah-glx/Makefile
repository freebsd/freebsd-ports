# New ports collection makefile for:	utah-glx
# Date created:         		13 September 1999
# Whom:                 		Marc E E van Woerkom  <van.woerkom@netcologne.de>
#
# $FreeBSD$
#

PORTNAME=	utah-glx
PORTVERSION=	0.9.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax

MAINTAINER=	3d@FreeBSD.org

BUILD_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82 \
		autoconf:${PORTSDIR}/devel/autoconf \
		nonexistent:${PORTSDIR}/graphics/Mesa3:patch

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

GLVER?=		14
GLUTVER?=	3

AGP_DEVICE=	/dev/agpgart

CFLAGS+=	-DAGP_DEVICE=\\\"${AGP_DEVICE}\\\"
CONFIGURE_SCRIPT=autogen.sh
CONFIGURE_ARGS=	--enable-extra \
		--with-mesa=${WRKDIRPREFIX}${.CURDIR}/../../graphics/Mesa3/work/Mesa-3.2 \
		--sysconfdir=${PREFIX}/etc \
		--with-moduledir=${PREFIX}/lib/modules
CONFIGURE_ENV=	TCLSH="tclsh8.2"
MAKE_ENV=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"
PLIST_SUB=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"

.if defined(DEBUG)
CFLAGS+=	-g
CONFIGURE_ARGS+=--enable-debug
.endif

ALL_TARGET=	depend all

.include <bsd.port.pre.mk>

post-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: This port will only work with XFree86 3.3 series of X-servers."
	@${ECHO_MSG} "         Users of XFree86 4.0 and above should use DRI instead."
	@${ECHO_MSG}

pre-build:
	@find ${WRKSRC} -type f | xargs grep -l linux/agpgart | \
		xargs perl -pi -e "s|linux/agpgart|sys/agpio|"

pre-install:
.if exists(${PREFIX}/lib/libGL.so.${GLVER}) && !defined(GL_CHECK_OVERRIDE)
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
	@${ECHO_MSG} "create device node for agp driver (mknod ${AGP_DEVICE} c 148 0) and enable"
	@${ECHO_MSG} "AGP support in ${PREFIX}/etc/glx.conf file."
	@${ECHO_MSG}
.endif
	${MKDIR} ${PREFIX}/share/doc/utah-glx
	${INSTALL_MAN} ${WRKSRC}/docs/README.* ${PREFIX}/share/doc/utah-glx

.include <bsd.port.post.mk>
