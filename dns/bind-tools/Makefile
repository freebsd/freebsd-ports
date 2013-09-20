# $FreeBSD$

PORTNAME=	bind-tools

COMMENT=	Command line tools from BIND: dig, host, and nslookup

CONFIGURE_ARGS+=	--disable-shared

CONFLICTS+=	bind99-9.9.*

MASTERDIR=	${.CURDIR}/../../dns/bind99

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

BIND_TOOLS_SLAVE=	YES

MAN1=	dig.1 host.1 nslookup.1

NO_STAGE=	yes
post-patch:
	@${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.presed
	@${SED} -e 's#^SUBDIRS.*#SUBDIRS = lib bin#' \
		-e 's#isc-config.sh installdirs#installdirs#' \
		-e 's#.*INSTALL.*isc-config.*##' \
		-e 's#.*INSTALL.*bind.keys.*##' \
		${WRKSRC}/Makefile.in.presed > ${WRKSRC}/Makefile.in
	@${MV} ${WRKSRC}/bin/Makefile.in ${WRKSRC}/bin/Makefile.in.presed
	@${SED} -e 's#^SUBDIRS.*#SUBDIRS = dig#' \
		-e 's#^	.*check confgen ##' \
		${WRKSRC}/bin/Makefile.in.presed > ${WRKSRC}/bin/Makefile.in

do-install:
.for file in dig host nslookup
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dig/${file} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bin/dig/${file}.1 ${MANPREFIX}/man/man1
.endfor

.include "${MASTERDIR}/Makefile"
