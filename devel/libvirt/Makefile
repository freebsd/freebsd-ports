# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://libvirt.org/sources/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Toolkit to interact with virtualization capabilities

LICENSE=	LGPL3

OPTIONS_DEFINE=	QEMU DOCS
QEMU_DESC=	QEMU bindings

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gcrypt.18:${PORTSDIR}/security/libgcrypt \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		gnutls.47:${PORTSDIR}/security/gnutls \
		ssh2.1:${PORTSDIR}/security/libssh2

GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes
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
GNOME_MAKEFILEIN=	Makefile.in
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes
SHLIB_VER=	1000
PLIST_SUB=	PORTVERSION="-${PORTVERSION}" \
		SHLIB_VER=${SHLIB_VER}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQEMU}
CONFIGURE_ARGS+=	--with-qemu
PLIST_SUB+=	QEMU=""
QEMU_CONFIG=	qemu
.else
CONFIGURE_ARGS+=	--without-qemu
PLIST_SUB+=	QEMU="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
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

post-install:
	@for configuration in libvirt libvirtd ${QEMU_CONFIG}; do \
	if [ ! -e "${ETCDIR}/$${configuration}.conf" ]; then \
			${ECHO_MSG} "	Installing local configuration file: ${ETCDIR}/$${configuration}.conf"; \
			${CP} ${ETCDIR}/$${configuration}.conf.sample ${ETCDIR}/$${configuration}.conf; \
		else \
			${ECHO_MSG} "	Preserving local configuration file: ${ETCDIR}/$${configuration}.conf"; \
	fi; \
	done
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} check

.include <bsd.port.mk>
