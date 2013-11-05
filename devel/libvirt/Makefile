# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvirt
PORTVERSION=	1.1.4
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

OPTIONS_DEFINE=	QEMU DOCS NLS
QEMU_DESC=	QEMU bindings

OPTIONS_SUB=	yes

QEMU_CONFIGURE_WITH=	qemu

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sasl \
		--without-yajl \
		--without-avahi \
		--without-polkit \
		--without-hal \
		--without-udev \
		--without-netcf \
		--without-network \
		--without-sysctl \
		--with-ssh2

# workaround to override pkg-config calls
# random_data fix can be removed when 8.x is eol
CONFIGURE_ENV=	SSH2_LIBS="-L${LOCALBASE}/lib -lssh2 -lssl" \
		SSH2_CFLAGS="-I${LOCLABASE}/include" \
		ac_cv_type_struct_random_data=""

# limit production release x.x.x
PORTSCOUT=	limit:\d+\.\d+\.\d+$$

LDFLAGS+=	-L${LOCALBASE}/lib -fstack-protector

USES=		charsetfix pathfix gmake pkgconfig perl5
USE_PERL5=	build
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes
SHLIB_VER=	1001
PLIST_SUB=	PORTVERSION="-${PORTVERSION}" \
		SHLIB_VER=${SHLIB_VER}
PORTDOCS=	*

.include <bsd.port.options.mk>

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

post-install:
	@for configuration in libvirt libvirtd ${QEMU_CONFIG}; do \
	if [ ! -e "${STAGEDIR}${ETCDIR}/$${configuration}.conf" ]; then \
			${ECHO_MSG} "	Installing local configuration file: ${STAGEDIR}${ETCDIR}/$${configuration}.conf"; \
			${CP} ${STAGEDIR}${ETCDIR}/$${configuration}.conf.sample ${STAGEDIR}${ETCDIR}/$${configuration}.conf; \
		else \
			${ECHO_MSG} "	Preserving local configuration file: ${STAGEDIR}${ETCDIR}/$${configuration}.conf"; \
	fi; \
	done
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} check

.include <bsd.port.mk>
