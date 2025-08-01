PORTNAME=	libvirt
DISTVERSION=	11.6.0
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/ \
		ftp://libvirt.org/libvirt/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities
WWW=		https://libvirt.org/

LICENSE=	LGPL3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgnutls.so:security/gnutls
BUILD_DEPENDS=	dnsmasq:dns/dnsmasq \
		ggrep:textproc/gnugrep \
		gsed:textproc/gsed \
		rst2html:textproc/py-docutils@${PY_FLAVOR} \
		xsltproc:textproc/libxslt
RUN_DEPENDS=	dnsmasq:dns/dnsmasq

OPTIONS_DEFINE=	DOCS NLS NSS QEMU READLINE SASL LIBSSH LIBSSH2 ZFS
OPTIONS_DEFAULT=	READLINE LIBSSH LIBSSH2 ZFS
OPTIONS_DEFINE_amd64=	XEN
.if exists(/usr/sbin/bhyveload)
OPTIONS_DEFINE+=	BHYVE
OPTIONS_DEFAULT+=	BHYVE
.else
PLIST_SUB+=		BHYVE="@comment "
SUB_LIST+=		BHYVE="@comment "
MESON_ARGS+=	-Ddriver_bhyve=disabled
.endif
QEMU_DESC=	QEMU driver
BHYVE_DESC=	bhyve driver
XEN_DESC=	Xen support via libxl
NSS_DESC=	Name Service Switch plugin
LIBSSH_DESC=	libssh remote transport
LIBSSH2_DESC=	libssh2 remote transport
ZFS_DESC=	ZFS storage driver

OPTIONS_SUB=	yes

BHYVE_MESON_ENABLED=	driver_bhyve

QEMU_MESON_ENABLED=	driver_qemu
QEMU_RUN_DEPENDS=	dmidecode:sysutils/dmidecode \
			qemu-io:emulators/qemu

NLS_USES=	gettext
NLS_MESON_ENABLED=	nls
NLS_CFLAGS=	-I${LOCALBASE}/include

NSS_MESON_ENABLED=	nss

READLINE_MESON_ENABLED=	readline
READLINE_USES=		readline

SASL_MESON_ENABLED=	sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

XEN_MESON_ENABLED=	driver_libxl
XEN_CFLAGS=	-I${LOCALBASE}/include
XEN_LIB_DEPENDS=	libxenlight.so:sysutils/xen-tools

LIBSSH_MESON_ENABLED=	libssh
LIBSSH_LIB_DEPENDS=	libssh.so:security/libssh

LIBSSH2_MESON_ENABLED=	libssh2
LIBSSH2_LIB_DEPENDS=	libssh2.so:security/libssh2

ZFS_MESON_ENABLED=	storage_zfs

MESON_ARGS+=	\
		-Dapparmor=disabled \
		-Dapparmor_profiles=disabled \
		-Dattr=disabled \
		-Daudit=disabled \
		-Dblkid=disabled \
		-Dcapng=disabled \
		-Ddriver_ch=disabled \
		-Ddriver_hyperv=disabled \
		-Ddriver_interface=disabled \
		-Ddriver_libxl=disabled \
		-Ddriver_lxc=disabled \
		-Ddriver_openvz=disabled \
		-Ddriver_remote=enabled \
		-Ddriver_vz=disabled \
		-Dfirewalld=disabled \
		-Dfirewalld_zone=disabled \
		-Dfuse=disabled \
		-Dglusterfs=disabled \
		-Dlibiscsi=disabled \
		-Dlibnl=disabled \
		-Dlibpcap=disabled \
		-Dnumactl=disabled \
		-Dnumad=disabled \
		-Dopenwsman=disabled \
		-Dpciaccess=disabled \
		-Dpolkit=disabled \
		-Dsanlock=disabled \
		-Dsecdriver_apparmor=disabled \
		-Dsecdriver_selinux=disabled \
		-Dselinux=disabled \
		-Dssh_proxy=disabled \
		-Dstorage_disk=disabled \
		-Dstorage_fs=disabled \
		-Dstorage_gluster=disabled \
		-Dstorage_iscsi=disabled \
		-Dstorage_iscsi_direct=disabled \
		-Dstorage_lvm=disabled \
		-Dstorage_mpath=disabled \
		-Dstorage_rbd=disabled \
		-Dstorage_vstorage=disabled \
		-Dudev=disabled \
		-Dnetcf=disabled \
		-Dsysctl_config=disabled \
		-Dnbdkit=disabled \
		-Dnbdkit_config_default=disabled \
		-Dlogin_shell=disabled \
		-Dwireshark_dissector=disabled \
		-Dinit_script=none \
		-Dbash_completion=disabled \
		-Duserfaultfd_sysctl=disabled \
		-Drunstatedir=/var/run

# random_data fix can be removed when 8.x is eol
CONFIGURE_ENV=	ac_cv_type_struct_random_data=""

# limit production release x.x.x
PORTSCOUT=	limit:\d+\.\d+\.\d+$$

LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector

USES=		gnome charsetfix compiler:c++0x cpe gettext-runtime gmake \
	        meson pathfix perl5 python:build pkgconfig shebangfix tar:xz
USE_GNOME=	glib20 libxml2
USE_RC_SUBR=	libvirtd virtlogd
CPE_VENDOR=	redhat
USE_PERL5=	build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
SHLIB_VER=	0.11006.0
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}
PORTDOCS=	*
#SHEBANG_FILES=	src/keycodemapdb/tools/keymap-gen
BINARY_ALIAS=	python3=${PYTHON_CMD}

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBHYVE} || ${PORT_OPTIONS:MQEMU} || ${PORT_OPTIONS:MNSS}
LIB_DEPENDS+=		libjson-c.so:devel/json-c
MESON_ARGS+=	-Djson_c=enabled
.else
MESON_ARGS+=	-Djson_c=disabled
.endif

.if !${PLIST_SUB:MXEN}
PLIST_SUB+=	XEN="@comment "
.endif

CONF_FILES=	\
		bhyve.conf \
		libvirt-admin.conf \
		libvirt.conf \
		libvirtd.conf \
		libxl.conf \
		network.conf \
		qemu.conf \
		virtbhyved.conf \
		virtlockd.conf \
		virtlogd.conf \
		virtnetworkd.conf \
		virtproxyd.conf \
		virtqemud.conf \
		virtsecretd.conf \
		virtstoraged.conf \
		virtvboxd.conf \
		virtxend.conf

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/qemu/networks/autostart
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS.rst NEWS.rst README.rst
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
	@${MKDIR} "${STAGEDIR}/var/${dir}"
.endfor

.for file in ${CONF_FILES}
	@if test -f ${STAGEDIR}${ETCDIR}/${file}; then \
		${MV} ${STAGEDIR}${ETCDIR}/${file} \
		${STAGEDIR}${ETCDIR}/${file}.sample; fi
.endfor

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
RUN_DEPENDS+=	dmidecode:sysutils/dmidecode
.endif

.include <bsd.port.post.mk>
