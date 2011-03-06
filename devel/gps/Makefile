# New ports collection makefile for:  gps
# Date created:                       12 December 2010
# Whom:                               John Marino <draco@marino.st>
#
# $FreeBSD$
#

PORTNAME=	gps
PORTVERSION=	5.0.0
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/

MAINTAINER=	draco@marino.st
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages

BUILD_DEPENDS=	gnat-aux>20101204:${PORTSDIR}/lang/gnat-aux \
		gtkada>=2.22:${PORTSDIR}/x11-toolkits/gtkada \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gprbuild-aux>=20101120:${PORTSDIR}/devel/gprbuild-aux
RUN_DEPENDS=	gtkada>=2.22:${PORTSDIR}/x11-toolkits/gtkada
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

LATEST_LINK=	gps-ide

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BZIP2=		yes
USE_PERL5_BUILD=	yes
ALL_TARGET=		default
CC=			gnatgcc

MAKE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat

OPTIONS=		SYSLOG "Enable system logging" on
OPTIONS+=		SQLITE "Enable SQLite database support" off
OPTIONS+=		PGSQL  "Enable PostgreSQL database support" off
OPTIONS+=		PYTHON "Enable Python scripts support" off
OPTIONS+=		PYGTK  "Enable Python bindings to GTK" off

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

CONFIGURE_ARGS+=	--with-gmp=${PREFIX}
CONFIGURE_ARGS+=	--enable-shared-python=yes

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

##############
##  PYTHON  ##
##############

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python=${PREFIX}
BUILD_DEPENDS+=		python26>=2.6:${PORTSDIR}/lang/python26
RUN_DEPENDS+=		python26>=2.6:${PORTSDIR}/lang/python26
.else
CONFIGURE_ARGS+=	--without-python
.endif

#############
##  PYGTK  ##
#############

.if defined(WITH_PYGTK)
CONFIGURE_ARGS+=	--enable-pygtk
BUILD_DEPENDS+=		py-gtk2>=2.22:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=		py-gtk2>=2.22:${PORTSDIR}/x11-toolkits/py-gtk2
.else
CONFIGURE_ARGS+=	--disable-pygtk
.endif

.include <bsd.port.post.mk>
