# Created by: Johan Strom <johna@stromnet.se>
# $FreeBSD$

PORTNAME=	owfs
PORTVERSION=	2.9p5
CATEGORIES=	comms
MASTER_SITES=	SF/owfs/owfs/${PORTVERSION}

MAINTAINER=	johan@stromnet.se
COMMENT=	OWFS -- 1-Wire file system

LICENSE=	GPLv2

USES=		libtool
ACLOCAL_ARGS=	-I${LOCALBASE}/share/aclocal

USE_AUTOTOOLS=	libtoolize aclocal autoheader autoconf automake
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	On
INSTALL_TARGET=	install-strip

.include "Makefile.options"

OPTIONS_SUB=yes

CONFIGURE_ARGS=		--enable-owlib

# Linux specific kernel driver
CONFIGURE_ARGS+=	--disable-w1
CONFIGURE_ARGS+=	--disable-parport

OWDEBUG_CONFIGURE_ENABLE=	debug
OWSHELL_CONFIGURE_ENABLE=	owshell
OWNET_CONFIGURE_ENABLE=		ownet

I2C_CONFIGURE_ENABLE=		i2c
OWHTTPD_CONFIGURE_ENABLE=	owhttpd
OWFTPD_CONFIGURE_ENABLE=	owftpd
OWSERVER_CONFIGURE_ENABLE=	owserver

OWTAP_CONFIGURE_ENABLE=		owtap
OWTAP_USE=			tk=yes tk_wrapper=yes

OWMALLOC_CONFIGURE_ENABLE=	owmalloc
OWTRAFFIC_CONFIGURE_ENABLE=	owtraffic

OWMON_CONFIGURE_ENABLE=		owmon
OWMON_USE=			tk=yes tk_wrapper=yes

OWCAPI_CONFIGURE_ENABLE=	owcapi

OWPERL_CONFIGURE_ENABLE=	owperl
OWPERL_USES=			perl5
OWPERL_USE=			perl5=build,run,fixpacklist

# Broken/untested
OWPHP_CONFIGURE_ENABLE=		owphp

OWPYTHON_CONFIGURE_ENABLE=	owpython
OWPYTHON_USES=			python

# Additional CONFIGURE_ARGS is done below
OWTCL_CONFIGURE_ENABLE=		owtcl
OWTCL_USES=			tcl

# XXX Broken due to -lgcc_p
PROFILING_CONFIGURE_ENABLE=	profiling

# XXX: Not tested, it compiles, but not sure if fusefs actually works
OWFS_CONFIGURE_ENABLE=		owfs
OWFS_USES=			fuse

ZERO_CONFIGURE_ENABLE=		zero
USB_CONFIGURE_ENABLE=		usb
USB_LDFLAGS=			-lusb

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
BUILD_DEPENDS+=			${LOCALBASE}/bin/swig2.0:${PORTSDIR}/devel/swig20
CONFIGURE_ARGS+=		--enable-swig SWIG=${LOCALBASE}/bin/swig2.0
.else
CONFIGURE_ARGS+=		--disable-swig
.endif

.if ${PORT_OPTIONS:MOWTCL}
CONFIGURE_ARGS+=		--enable-owtcl --with-tcl=${TCL_LIBDIR}
.endif

# These __version__ fixes should be unnecessary on next release
post-patch:
	@${REINPLACE_CMD} \
		-e "s/^\(__version__ = '[[:digit:]]\.[[:digit:]]\).*/\1'/" \
		${WRKSRC}/module/swig/python/unittest/*.py \
		${WRKSRC}/module/ownet/python/ownet/__init__.py
	@${REINPLACE_CMD} -e "s/\(__version__ =\).*/\1 '1.9'/" \
		${WRKSRC}/module/ownet/python/ownet/connection.py
	@${REINPLACE_CMD} -e "s/\(__version__ = .*\) [+].*/\1/" \
		${WRKSRC}/module/swig/python/ow/__init__.py

# This takes a few seconds so give the user some notice
pre-configure:
	${MKDIR} ${WRKSRC}/m4
	@echo "Preparing build using autotools..."

# Workarounds for different problems
post-install:
.if ${PORT_OPTIONS:MOWPYTHON}
	(cd ${STAGEDIR}${PREFIX} \
	 && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	 -d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/python2.7/site-packages/ow/_OW.so
.endif
.if ${PORT_OPTIONS:MOWPERL}
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal.pod*
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/OW/OW.so
.endif

.include <bsd.port.mk>
