# $FreeBSD$

PORTREVISION=	2
PKGNAMESUFFIX=	-tools

COMMENT=	Command line tools from BIND: dig, host, and nslookup

CONFIGURE_ARGS+=	--disable-shared

CONFLICTS+=	bind910-9.10.*

MASTERDIR=	${.CURDIR}/../../dns/bind910

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
PKGINSTALL=	/nonexistent

BIND_TOOLS_SLAVE=	YES

INSTALL_WRKSRC=	${WRKSRC}/bin

post-patch:
	@${REINPLACE_CMD} -e 's#^SUBDIRS.*#SUBDIRS = lib bin#' \
		-e 's#isc-config.sh installdirs#installdirs#' \
		-e 's#.*INSTALL.*isc-config.*##' \
		-e 's#.*INSTALL.*bind.keys.*##' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's#^SUBDIRS.*#SUBDIRS = delv dig dnssec nsupdate \\#' \
		-e 's#^	.*check confgen ##' \
		${WRKSRC}/bin/Makefile.in

.include "${MASTERDIR}/Makefile"
