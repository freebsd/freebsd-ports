# New ports collection makefile for:	swarm
# Date created:		26 June 1998
# Whom:			Horance C.H Chou <horance@freedom.ie.cycu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	swarm
PORTVERSION=	2.1.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/swarm/src/swarm/

MAINTAINER=	horance@freera.net
COMMENT=	The Swarm Simulation System

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21
.if defined(WITH_HDF5)
LIB_DEPENDS+=	hdf5.0:${PORTSDIR}/graphics/hdf5
.endif
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		BLT24.3:${PORTSDIR}/x11-toolkits/blt

ONLY_FOR_ARCHS=	i386

USE_JAVA=	1.3+
USE_GMAKE=	yes
USE_XPM=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
TK_VER?=	8.4
CONFIGURE_ARGS=	--with-defaultdir=${PREFIX} \
		--with-tclincludedir=${PREFIX}/include/tcl${TK_VER} \
		--with-tkincludedir=${PREFIX}/include/tk${TK_VER} \
		--with-tclscriptdir=${PREFIX}/lib/tcl${TK_VER} \
		--with-tkscriptdir=${PREFIX}/lib/tk${TK_VER} \
		--with-jdkdir=${JAVA_HOME} \
		--enable-subdirs

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%LTCONFIG%%|${LIBTOOL_SHAREDIR}/ltconfig${LIBTOOL_VERSION}|g' \
		-e 's|%%LTMAIN%%|${LIBTOOL_SHAREDIR}/ltmain.sh|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|%%LTCONFIG%%|${LIBTOOL_SHAREDIR}/ltconfig${LIBTOOL_VERSION}|g' \
		-e 's|%%LTMAIN%%|${LIBTOOL_SHAREDIR}/ltmain.sh|g' \
		${WRKSRC}/libobjc/configure
	@${REINPLACE_CMD} \
		-e 's|%%LTCONFIG%%|${LIBTOOL_SHAREDIR}/ltconfig${LIBTOOL_VERSION}|g' \
		-e 's|%%LTMAIN%%|${LIBTOOL_SHAREDIR}/ltmain.sh|g' \
		${WRKSRC}/avcall/configure

pre-everything::
.if !defined(WITH_HDF5)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> To enable hdf5 support , please define WITH_HDF5"
	@${ECHO_MSG} "===>"
.endif

post-patch:

post-install:
	${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"

.include <bsd.port.mk>
