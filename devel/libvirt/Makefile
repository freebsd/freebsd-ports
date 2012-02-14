# New ports collection makefile for:	libvirt
# Date created:		2011-05-12
# Whom:			Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	libvirt
PORTVERSION=	0.9.10
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gcrypt.18:${PORTSDIR}/security/libgcrypt \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gnutls.47:${PORTSDIR}/security/gnutls

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake autoconf
CONFIGURE_ARGS=	--without-libssh2 \
		--without-sasl \
		--without-yajl \
		--without-avahi \
		--without-polkit \
		--without-hal \
		--without-udev \
		--without-netcf \
		--without-network
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

USE_GMAKE=	yes
USE_GNOME=	gnomehack
GNOME_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes
SHLIB_VER=	9
PLIST_SUB=	PORTVERSION="-${PORTVERSION}" \
		SHLIB_VER=${SHLIB_VER}

.if !defined(WITHOUT_NLS)
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

post-patch:
	@${MV} ${WRKSRC}/daemon/libvirtd.conf ${WRKSRC}/daemon/libvirtd.conf.sample
	@${REINPLACE_CMD} -e 's|libvirtd.conf|libvirtd.conf.sample|' \
		${WRKSRC}/daemon/Makefile.am \
		${WRKSRC}/daemon/Makefile.in

	@${MV} ${WRKSRC}/src/libvirt.conf ${WRKSRC}/src/libvirt.conf.sample
	@${REINPLACE_CMD} -e 's|conf_DATA = libvirt.conf|conf_DATA = libvirt.conf.sample|' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
