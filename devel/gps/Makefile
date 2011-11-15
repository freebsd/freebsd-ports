# New ports collection makefile for:  gps
# Date created:                       12 December 2010
# Whom:                               John Marino <draco@marino.st>
#
# $FreeBSD$
#

PORTNAME=	gps
PORTVERSION=	5.0.1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/

MAINTAINER=	draco@marino.st
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages

BUILD_DEPENDS=	gnat-aux>20110325:${PORTSDIR}/lang/gnat-aux \
		gtkada<2.24:${PORTSDIR}/x11-toolkits/gtkada \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gprbuild-aux>=20101120:${PORTSDIR}/devel/gprbuild-aux
RUN_DEPENDS=	gtkada<2.24:${PORTSDIR}/x11-toolkits/gtkada
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

LATEST_LINK=	gps-ide

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BZIP2=		yes
USE_PERL5_BUILD=	yes
ALL_TARGET=		default
CC=			gnatgcc

CONFIGURE_ENV+=		AWK=/usr/bin/awk
MAKE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat

OPTIONS=		SYSLOG "Enable system logging" on
OPTIONS+=		SQLITE "Enable SQLite database support" off
OPTIONS+=		PGSQL  "Enable PostgreSQL database support" off
OPTIONS+=		PYTHON "Enable Python console" off

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

CONFIGURE_ARGS+=	--with-gmp=${PREFIX}

##############
##  SYSLOG  ##
##############

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--enable-syslog=yes
.else
CONFIGURE_ARGS+=	--enable-syslog=no
.endif

##############
##  SQLITE  ##
##############

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}
BUILD_DEPENDS+=		sqlite3>=3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS+=		sqlite3>=3:${PORTSDIR}/databases/sqlite3
.endif

##################
##  POSTGRESQL  ##
##################

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-postgresql=${PREFIX}
USE_PGSQL=		true
.endif

#####################
##  PYTHON / PYGTK ##
#####################

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python=${PREFIX}
CONFIGURE_ARGS+=	--enable-shared-python=yes
CONFIGURE_ARGS+=	--enable-pygtk
PLIST_SUB+=		PYSUPPORT=""
USE_PYTHON=		26 27
BUILD_DEPENDS+=		py2[67]-gtk>=2.22:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=		py2[67]-gtk>=2.22:${PORTSDIR}/x11-toolkits/py-gtk2
PYCOMPILE=		${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
.else
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--disable-pygtk
PLIST_SUB+=		PYSUPPORT="@comment "
.endif

.include <bsd.port.pre.mk>

pre-install:
.if defined(WITH_PYTHON)
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/plug-ins
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/library
.endif

.include <bsd.port.post.mk>
