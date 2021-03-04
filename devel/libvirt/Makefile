# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	7.1.0
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/ \
		ftp://libvirt.org/libvirt/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libxml2.so:textproc/libxml2
BUILD_DEPENDS=	dnsmasq:dns/dnsmasq \
		rst2html-${PYTHON_VER}:textproc/py-docutils@${PY_FLAVOR} \
		xsltproc:textproc/libxslt
RUN_DEPENDS=	dnsmasq:dns/dnsmasq

OPTIONS_DEFINE=	DOCS NLS NSS QEMU READLINE SASL LIBSSH LIBSSH2 ZFS
OPTIONS_DEFAULT=	READLINE LIBSSH LIBSSH2 ZFS
OPTIONS_DEFINE_amd64=	XEN
.if exists(/usr/sbin/bhyve)
OPTIONS_DEFINE_amd64+=	BHYVE
OPTIONS_DEFAULT_amd64+=	BHYVE
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

VARDIR=		/var

MESON_ARGS+=	\
		-Ddbus=disabled \
		-Dpolkit=disabled \
		-Dhal=disabled \
		-Dudev=disabled \
		-Dnetcf=disabled \
		-Dsysctl_config=disabled \
		-Dlogin_shell=disabled \
		-Dwireshark_dissector=disabled \
		-Dinit_script=none \
		-Dbash_completion=disabled \
		-Dlocalstatedir=${VARDIR}

# random_data fix can be removed when 8.x is eol
CONFIGURE_ENV=	ac_cv_type_struct_random_data=""

# limit production release x.x.x
PORTSCOUT=	limit:\d+\.\d+\.\d+$$

LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector

USES=		gnome charsetfix compiler:c++0x cpe gettext-runtime gmake libtool \
	        meson pathfix perl5 python:3.6+,build pkgconfig shebangfix tar:xz
USE_GNOME=	glib20
USE_RC_SUBR=	libvirtd virtlogd
CPE_VENDOR=	redhat
USE_PERL5=	build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
SHLIB_VER=	0.7001.0
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER}
PORTDOCS=	*
SHEBANG_FILES=	src/keycodemapdb/tools/keymap-gen
BINARY_ALIAS=	python3=${PYTHON_CMD} \
		rst2man.py=rst2man.py-${PYTHON_VER} \
		rst2html5.py=rst2html5.py-${PYTHON_VER}

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQEMU} || ${PORT_OPTIONS:MNSS}
LIB_DEPENDS+=		libyajl.so:devel/yajl
MESON_ARGS+=	-Dyajl=enabled
.else
MESON_ARGS+=	-Dyajl=disabled
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

post-patch:
	${REINPLACE_CMD} -e 's|HAVE_BSD_NSS|WITH_BSD_NSS|' \
		${WRKSRC}/tools/nss/libvirt_nss.c \
		${WRKSRC}/tools/nss/libvirt_nss.h

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
	@${MKDIR} "${STAGEDIR}/${VARDIR}/${dir}"
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
