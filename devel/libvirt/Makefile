# New ports collection makefile for:	libvirt
# Date created:		2011-05-12
# Whom:			Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	libvirt
PORTVERSION=	0.10.1
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gcrypt.18:${PORTSDIR}/security/libgcrypt \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gnutls.47:${PORTSDIR}/security/gnutls \
		ssh2.1:${PORTSDIR}/security/libssh2

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoconf
CONFIGURE_ARGS=	--without-sasl \
		--without-yajl \
		--without-avahi \
		--without-polkit \
		--without-hal \
		--without-udev \
		--without-netcf \
		--without-network \
		--without-sysctl \
		--with-libssh2

#limit to non-stable release x.x.x
PORTSCOUT=	limit:\d+\.\d+\.\d+$$

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

USE_GMAKE=	yes
USE_GNOME=	gnomehack
GNOME_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes
SHLIB_VER=	10
PLIST_SUB=	PORTVERSION="-${PORTVERSION}" \
		SHLIB_VER=${SHLIB_VER}

.if empty(PORT_OPTIONS:MNLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--enable-nls \
			--with-libintl-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		virsh.1 virt-pki-validate.1 virt-xml-validate.1 virt-host-validate.1
MAN8=		libvirtd.8

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|1.11.3|%%AUTOMAKE_APIVER%%|g' \
		${WRKSRC}/aclocal.m4
	@${MV} ${WRKSRC}/daemon/libvirtd.conf ${WRKSRC}/daemon/libvirtd.conf.sample
	@${REINPLACE_CMD} -e 's|libvirtd\.conf|libvirtd.conf.sample|' \
		${WRKSRC}/daemon/Makefile.am \
		${WRKSRC}/daemon/Makefile.in

	@${MV} ${WRKSRC}/src/libvirt.conf ${WRKSRC}/src/libvirt.conf.sample
	@${REINPLACE_CMD} -e 's|conf_DATA = libvirt.conf|conf_DATA = libvirt.conf.sample|' \
		${WRKSRC}/src/Makefile.am

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} check

.include <bsd.port.mk>
