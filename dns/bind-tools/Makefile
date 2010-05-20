# New ports collection makefile for:	BIND Tools
# Date created:				1 April 2010
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	bind-tools
PORTVERSION=	9.7.0.2
CATEGORIES=	dns net ipv6
MASTER_SITES=	${MASTER_SITE_ISC} \
		http://dougbarton.us/Downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
DISTNAME=	bind-${ISCVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	The command line tools from BIND: dig, host, and nslookup

# ISC releases things like 9.4.0b3, which our versioning doesn't like
ISCVERSION=	9.7.0-P2

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--disable-symtable \
		--disable-shared \
		--with-randomdev=/dev/random

CONFLICTS=	bind9*-9.[34567].* bind9-sdb-* host-*

OPTIONS=	SSL "Building without OpenSSL removes DNSSEC" on \
		IDN "Add IDN support to dig, host, etc." off \
		REPLACE_BASE "Replace base BIND with this version" off \
		LARGE_FILE "64-bit file support" off \
		SIGCHASE "dig/host/nslookup will do DNSSEC validation" off \
		IPV6 "IPv6 Support (autodetected by default)" off

# Just in case
USE_OPENSSL=	yes

PLIST_FILES=	bin/dig bin/host bin/nslookup

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

# We are ok by default from 7.0-RELEASE on
.if ${OSVERSION} >= 700055
OPTIONS+=	THREADS	"Compile with thread support" on
.else
OPTIONS+=	THREADS	"Compile w/threads (Not Recommended <FreeBSD-7)" off
.endif

.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--disable-openssl-version-check
CONFIGURE_ARGS+=	--without-openssl
.endif

.if defined(WITH_IDN)
CONFIGURE_ARGS+=	--with-idn=${LOCALBASE} --with-libiconv=${LOCALBASE}
LIB_DEPENDS+=		idnkit.1:${PORTSDIR}/dns/idnkit
.else
CONFIGURE_ARGS+=	--without-idn
.endif

.if defined(WITH_LARGE_FILE)
CONFIGURE_ARGS+=	--enable-largefile
.endif

.if defined(WITH_SIGCHASE)
CONFIGURE_ARGS+=	STD_CDEFINES="-DDIG_SIGCHASE=1"
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_REPLACE_BASE)
PKGNAMESUFFIX=	-base
PREFIX=		/usr
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

MAN1=	dig.1 host.1 nslookup.1

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

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

.include <bsd.port.post.mk>
