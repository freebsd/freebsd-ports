# $FreeBSD$

PKGNAMESUFFIX=	-tools

COMMENT=	Command line tools from BIND: dig, host, and nslookup

CONFIGURE_ARGS+=	--disable-shared

CONFLICTS+=	bind910-9.10.*

MASTERDIR=	${.CURDIR}/../../dns/bind910

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
PKGINSTALL=	/nonexistent

BIND_TOOLS_SLAVE=	YES

post-patch:
	@${REINPLACE_CMD} -e 's#^SUBDIRS.*#SUBDIRS = lib bin#' \
		-e 's#isc-config.sh installdirs#installdirs#' \
		-e 's#.*INSTALL.*isc-config.*##' \
		-e 's#.*INSTALL.*bind.keys.*##' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's#^SUBDIRS.*#SUBDIRS = delv dig dnssec nsupdate#' \
		-e 's#^	.*check confgen ##' \
		${WRKSRC}/bin/Makefile.in

do-install:
.for file in dig host nslookup
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dig/${file} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bin/dig/${file}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
.for file in delv nsupdate
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file}/${file} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bin/${file}/${file}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
.for file in dnssec-dsfromkey dnssec-importkey dnssec-keyfromlabel \
	dnssec-keygen dnssec-revoke dnssec-settime dnssec-signzone \
	dnssec-verify
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dnssec/${file} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bin/dnssec/${file}.8 ${STAGEDIR}${MANPREFIX}/man/man8
.endfor

.include "${MASTERDIR}/Makefile"
