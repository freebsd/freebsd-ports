# New ports collection makefile for:	sfslite
# Date created:				10 September 2005
# Whom:					max
#
# $FreeBSD$
#

PORTNAME=	sfslite
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dist.okws.org/dist/

MAINTAINER=	ports@okws.org
COMMENT=	Standard version of the sfslite library

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#
# rpcc does not work with byacc, so just require BISON
#
USE_BISON=	build

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
CONFIGURE_ARGS += --enable-system-bin
.endif # define(BUILD_MODE)

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}/${BUILD_MODE}

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

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
