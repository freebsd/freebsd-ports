# Created by: Johan Strom <johan@stromnet.se>
# $FreeBSD$

PORTNAME=	owfs
PORTVERSION=	3.1p1
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF/owfs/owfs/${PORTVERSION}

MAINTAINER=	johan@stromnet.se
COMMENT=	OWFS -- 1-Wire file system

LICENSE=	GPLv2

USES=		autoreconf gmake libtool pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include "Makefile.options"

OPTIONS_SUB=yes

CONFIGURE_ARGS=		--enable-owlib

# Linux specific kernel driver
CONFIGURE_ARGS+=	--disable-w1
CONFIGURE_ARGS+=	--disable-parport

OWDEBUG_CONFIGURE_ENABLE=	debug
OWMUTEXDEBUG_CONFIGURE_ENABLE=	mutexdebug
OWSHELL_CONFIGURE_ENABLE=	owshell
OWNET_CONFIGURE_ENABLE=		ownet

I2C_CONFIGURE_ENABLE=		i2c
OWHTTPD_CONFIGURE_ENABLE=	owhttpd
OWFTPD_CONFIGURE_ENABLE=	owftpd
OWSERVER_CONFIGURE_ENABLE=	owserver

OWTAP_CONFIGURE_ENABLE=		owtap
OWTAP_USES=			tk:wrapper

OWMALLOC_CONFIGURE_ENABLE=	owmalloc
OWTRAFFIC_CONFIGURE_ENABLE=	owtraffic

OWMON_CONFIGURE_ENABLE=		owmon
OWMON_USES=			tk:wrapper

OWCAPI_CONFIGURE_ENABLE=	owcapi

OWPERL_CONFIGURE_ENABLE=	owperl
OWPERL_USES=			perl5
OWPERL_USE=			perl5=build,run

# Broken/untested
OWPHP_CONFIGURE_ENABLE=		owphp

OWPYTHON_CONFIGURE_ENABLE=	owpython
OWPYTHON_USES=			python:2.7

# Additional CONFIGURE_ARGS is done below
OWTCL_CONFIGURE_ENABLE=		owtcl
OWTCL_USES=			tcl

# XXX Broken due to -lgcc_p
PROFILING_CONFIGURE_ENABLE=	profiling

# work on 10.1 amd64, USB DS9097, --passive=/dev/cuaU0
OWFS_CONFIGURE_ENABLE=		owfs
OWFS_USES=			fuse

ZERO_CONFIGURE_ENABLE=		zero
USB_CONFIGURE_ENABLE=		usb

.include <bsd.port.options.mk>

# If OW Network and C API is requested, build libownet as well
.if ${PORT_OPTIONS:MOWNET} && ${PORT_OPTIONS:MOWCAPI}
CONFIGURE_ARGS+=		--enable-ownetlib
PLIST_SUB+=			OWNETLIB=""
.else
CONFIGURE_ARGS+=		--disable-ownetlib
PLIST_SUB+=			OWNETLIB="@comment "
.endif

# If OW Network and Perl is requested, we get ownet perl files
.if ${PORT_OPTIONS:MOWPERL} && ${PORT_OPTIONS:MOWNET}
PLIST_SUB+=			OWNETPERL=""
.else
PLIST_SUB+=			OWNETPERL="@comment "
.endif

# If OW Network and Python is requested, we get ownet python files
.if ${PORT_OPTIONS:MOWPYTHON} && ${PORT_OPTIONS:MOWNET}
PLIST_SUB+=			OWNETPYTHON=""
.else
PLIST_SUB+=			OWNETPYTHON="@comment "
.endif

# If Perl, Python or PHP is requested, enable SWIG
.if ${PORT_OPTIONS:MOWPERL} || ${PORT_OPTIONS:MOWPYTHON} || ${PORT_OPTIONS:MOWPHP}
BUILD_DEPENDS+=			swig3.0:devel/swig30
CONFIGURE_ARGS+=		--enable-swig SWIG=${LOCALBASE}/bin/swig3.0
.else
CONFIGURE_ARGS+=		--disable-swig
.endif

.if ${PORT_OPTIONS:MOWTCL}
CONFIGURE_ARGS+=		--enable-owtcl --with-tcl=${TCL_LIBDIR}
.endif

# This takes a few seconds so give the user some notice
pre-configure:
	@${MKDIR} ${WRKSRC}/m4
	@echo "Preparing build using autotools..."

# Workarounds for different problems
post-install-OWPYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/ow/_OW.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*
	(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	(cd ${STAGEDIR}${PREFIX} \
		&& ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

post-install-OWPERL-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/OW/OW.so

.include <bsd.port.mk>
