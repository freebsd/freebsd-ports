# Created by: John Marino <draco@marino.st>
# $FreeBSD$

PORTNAME=	gps
PORTVERSION=	5.0.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	draco@marino.st
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages

BUILD_DEPENDS=	gtkada<2.24:${PORTSDIR}/x11-toolkits/gtkada \
		xmlada>=3.2:${PORTSDIR}/textproc/xmlada \
		gprbuild>=20120510:${PORTSDIR}/devel/gprbuild
RUN_DEPENDS=	gtkada<2.24:${PORTSDIR}/x11-toolkits/gtkada
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

LATEST_LINK=		gps-ide

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BZIP2=		yes
USE_PERL5_BUILD=	yes
ALL_TARGET=		default
USES+=			ada

CONFIGURE_ENV+=		AWK=/usr/bin/awk

OPTIONS_DEFINE=		SYSLOG SQLITE PGSQL PYTHON
OPTIONS_DEFAULT=	SYSLOG

PYTHON_DESC=		Enable Python console

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:L}${OSREL}
.endif

CONFIGURE_ARGS+=	--with-gmp=${PREFIX}

##############
##  SYSLOG  ##
##############

.if ${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--enable-syslog=yes
.else
CONFIGURE_ARGS+=	--enable-syslog=no
.endif

##############
##  SQLITE  ##
##############

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}
BUILD_DEPENDS+=		sqlite3>=3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS+=		sqlite3>=3:${PORTSDIR}/databases/sqlite3
.endif

##################
##  POSTGRESQL  ##
##################

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-postgresql=${PREFIX}
USE_PGSQL=		true
.endif

#####################
##  PYTHON / PYGTK ##
#####################

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--with-python=${PREFIX}
CONFIGURE_ARGS+=	--enable-shared-python=yes
CONFIGURE_ARGS+=	--enable-pygtk
PLIST_SUB+=		PYSUPPORT=""
USE_PYTHON=		-2.7
BUILD_DEPENDS+=		py2[67]-gtk>=2.22:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=		py2[67]-gtk>=2.22:${PORTSDIR}/x11-toolkits/py-gtk2
PYCOMPILE=		${PREFIX}/lib/${PYTHON_VERSION}/compileall.py
.else
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--disable-pygtk
PLIST_SUB+=		PYSUPPORT="@comment "
.endif

pre-install:
.if ${PORT_OPTIONS:MPYTHON}
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/plug-ins
	${PYTHON_CMD} ${PYCOMPILE} ${WRKSRC}/share/library
.endif

.include <bsd.port.mk>
