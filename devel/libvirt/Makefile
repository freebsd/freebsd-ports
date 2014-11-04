# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/ \
		ftp://libvirt.org/libvirt/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libssh2.so:${PORTSDIR}/security/libssh2
BUILD_DEPENDS=	dnsmasq:${PORTSDIR}/dns/dnsmasq
RUN_DEPENDS=	dnsmasq:${PORTSDIR}/dns/dnsmasq

OPTIONS_DEFINE=	DOCS NLS QEMU
OPTIONS_DEFINE_amd64=	BHYVE
.if exists(/usr/sbin/bhyve)
OPTIONS_DEFAULT_amd64=	BHYVE
.endif
QEMU_DESC=	QEMU driver
BHYVE_DESC=	bhyve driver

OPTIONS_SUB=	yes

QEMU_CONFIGURE_WITH=	qemu yajl
QEMU_CFLAGS=	-I${LOCALBASE}/include
QEMU_LIB_DEPENDS=	libyajl.so:${PORTSDIR}/devel/yajl
QEMU_RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode \
			qemu-io:${PORTSDIR}/emulators/qemu-devel

BHYVE_CONFIGURE_WITH=	bhyve

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}

VARDIR=		/var

USE_RC_SUBR=	libvirtd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sasl \
		--without-avahi \
		--without-polkit \
		--without-hal \
		--without-udev \
		--without-netcf \
		--without-sysctl \
		--without-lxc \
		--without-uml \
		--with-ssh2 \
		--localstatedir=${VARDIR}

# random_data fix can be removed when 8.x is eol
CONFIGURE_ENV=	ac_cv_type_struct_random_data=""

# limit production release x.x.x
PORTSCOUT=	limit:\d+\.\d+\.\d+$$

LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector

USES=		charsetfix gmake libtool pathfix pkgconfig perl5 cpe
CPE_VENDOR=	redhat
USE_PERL5=	build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SHLIB_VER=	0.1002.10
PLIST_SUB=	PORTVERSION="-${PORTVERSION}" \
		SHLIB_VER=${SHLIB_VER}
PORTDOCS=	*

.include <bsd.port.options.mk>

#work around an options bug (thanks mat@)
.if ${ARCH} != amd64
PLIST_SUB+=	BHYVE="@comment "
.endif

.if ${PORT_OPTIONS:MBHYVE}
STRIP_FILES+=	libvirt/connection-driver/libvirt_driver_bhyve.so
.endif

post-patch:
.if ${OSVERSION} < 900000
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||' \
		${WRKSRC}/configure
.endif
	@${MV} ${WRKSRC}/daemon/libvirtd.conf ${WRKSRC}/daemon/libvirtd.conf.sample
	@${REINPLACE_CMD} -e 's|libvirtd\.conf|libvirtd.conf.sample|' \
		${WRKSRC}/daemon/Makefile.in

	@${MV} ${WRKSRC}/src/libvirt.conf ${WRKSRC}/src/libvirt.conf.sample
	@${REINPLACE_CMD} -e 's|conf_DATA = libvirt.conf|conf_DATA = libvirt.conf.sample|' \
		${WRKSRC}/src/Makefile.in

	@${MV} ${WRKSRC}/src/qemu/qemu.conf ${WRKSRC}/src/qemu/qemu.conf.sample
	@${REINPLACE_CMD} -e 's|qemu.conf |qemu.conf.sample |' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|qemu.conf$$|qemu.conf.sample|' \
		${WRKSRC}/src/Makefile.in

	@${REINPLACE_CMD} -e 's|cp $$(DESTDIR)|cp -f $$(DESTDIR)|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.for dir in run/libvirt/network \
	run/libvirt/qemu \
	run/libvirt/lockd \
	log/libvirt/uml \
	log/libvirt/qemu \
	log/libvirt/lxc \
	lib/libvirt/boot \
	lib/libvirt/lockd/files \
	lib/libvirt/images \
	lib/libvirt/dnsmasq \
	lib/libvirt/filesystems \
	lib/libvirt/network \
	lib/libvirt/qemu/channel/target \
	cache/libvirt/qemu
	@${MKDIR} "${STAGEDIR}/${VARDIR}/${dir}"
.endfor

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
