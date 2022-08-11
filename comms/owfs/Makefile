PORTNAME=	owfs
PORTVERSION=	3.2p4
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	https://github.com/owfs/owfs/releases/download/v${PORTVERSION}/

MAINTAINER=	johan@stromnet.se
COMMENT=	1-wire file system implementation

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash

USES=		gmake libtool pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include "Makefile.options"

OPTIONS_SUB=yes

CONFIGURE_ARGS=		--enable-owlib

# Linux specific kernel driver
CONFIGURE_ARGS+=	--disable-w1
CONFIGURE_ARGS+=	--disable-parport

AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app

FTDI_CONFIGURE_ENABLE=		ftdi
FTDI_LIB_DEPENDS=		libftdi.so:devel/libftdi

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

OWMON_CONFIGURE_ENABLE=		owmon
OWMON_USES=			tk:wrapper

OWCAPI_CONFIGURE_ENABLE=	owcapi
OWEXTERNAL_CONFIGURE_ENABLE=	owexternal

OWPERL_CONFIGURE_ENABLE=	owperl
OWPERL_USES=			perl5
OWPERL_USE=			perl5=build,run

# Broken/untested
OWPHP_CONFIGURE_ENABLE=		owphp

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

# If Perl or PHP is requested, enable SWIG
.if ${PORT_OPTIONS:MOWPERL} || ${PORT_OPTIONS:MOWPHP}
BUILD_DEPENDS+=			swig:devel/swig
CONFIGURE_ARGS+=		--enable-swig SWIG=${LOCALBASE}/bin/swig
.else
CONFIGURE_ARGS+=		--disable-swig
.endif

.if ${PORT_OPTIONS:MOWTCL}
CONFIGURE_ARGS+=		--enable-owtcl --with-tcl=${TCL_LIBDIR}
.endif

.if ${PORT_OPTIONS:MOWEXTERNAL}
PLIST_SUB+=			OWEXTERNAL=""
.else
PLIST_SUB+=			OWEXTERNAL="@comment "
CONFIGURE_ARGS+=		--disable-owexternal
.endif

# This takes a few seconds so give the user some notice
pre-configure:
	@${MKDIR} ${WRKSRC}/m4
	@echo "Preparing build using autotools..."

# Workarounds for different problems

post-install-OWPERL-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/OW/OW.so

.include <bsd.port.mk>
