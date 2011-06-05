# New ports collection makefile for:	libvirt
# Date created:		2011-05-12
# Whom:			Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	libvirt
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-libssh2 \
		--without-sasl \
		--without-yajl \
		--without-avahi \
		--without-polkit \
		--without-hal \
		--without-udev \
		--without-netcf \
		--without-network
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes
PLIST_SUB=	PORTVERSION="-${PORTVERSION}"

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gcrypt.17:${PORTSDIR}/security/libgcrypt \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gnutls.47:${PORTSDIR}/security/gnutls

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		virsh.1 virt-pki-validate.1 virt-xml-validate.1
MAN8=		libvirtd.8

post-patch:
	@${MV} ${WRKSRC}/daemon/libvirtd.conf ${WRKSRC}/daemon/libvirtd.conf.sample
	@${REINPLACE_CMD} -e 's|libvirtd.conf|libvirtd.conf.sample|' \
		${WRKSRC}/daemon/Makefile.am \
		${WRKSRC}/daemon/Makefile.in

.include <bsd.port.mk>
