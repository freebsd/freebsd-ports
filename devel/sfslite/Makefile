# New ports collection makefile for:	sfslite
# Date created:				10 September 2005
# Whom:					max
#
# $FreeBSD$
#

PORTNAME=	sfslite
PORTVERSION=	0.8.4
CATEGORIES=	devel
MASTER_SITES=	http://dist.okws.org/dist/

MAINTAINER=	ports@okws.org
COMMENT=	Standard version of the sfslite library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--with-sfsuser=sfs \
		--with-sfsgroup=sfs
#
# rpcc does not work with byacc, so just require BISON
#
USE_BISON=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
LIB_DEPENDS+=	gmp.6:${PORTSDIR}/math/libgmp4
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-gmp=/usr
.endif

#
# Map X.Y.Z.Q => X.Y
#
SHORTVERSION=	${PORTVERSION:C/^([^\.]+\.[^\.]+).*$/\1/}

#
# if being called from one of the slave distributions (like
# sfslite-dbg), then the build-mode will be set, and we should
# rename the port accordingly so that more than one of them can
# be built.
#
.if defined(BUILD_MODE)
PKGNAMESUFFIX+=	-${BUILD_MODE}
RPCC_BIN?=	lib/${PORTNAME}-${SHORTVERSION}/${BUILD_MODE}
.else
BUILD_MODE?=	shopt
RPCC_BIN?=	bin
.endif # define(BUILD_MODE)

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/${PORTNAME}/${BUILD_MODE}

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--with-mode=${BUILD_MODE}

PLIST_SUB=	VERSION=${SHORTVERSION} \
		TAG=${BUILD_MODE} \
		RPCC_BIN=${RPCC_BIN}

#
# Slave distributions might override this since they won't have a
# pkg-install script in their directory.
#
PKG_INSTALL?=	pkg-install

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKG_INSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.post.mk>
