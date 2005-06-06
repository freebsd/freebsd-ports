# New ports collection makefile for:	bind
# Date created:		18 July 1997
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

# I stay very aware of developments regarding BIND. I frequently delay updating
# this port from a known-stable version due to concerns about stability of a
# newer version. If you are interested in using the most recent ISC release
# you can generally build it cleanly from the source. - Doug

PORTNAME=	bind
PORTVERSION=	8.3.7
CATEGORIES?=	dns net
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind/src/${PORTVERSION}
DISTFILES=	bind-src.tar.gz bind-doc.tar.gz
DIST_SUBDIR=	bind-${PORTVERSION}

MAINTAINER?=	DougB@FreeBSD.org
COMMENT=	The Berkeley Internet Name Domain, an implementation of DNS

.if defined(PORT_REPLACES_BASE_BIND8_INCLUDES)
PORT_REPLACES_BASE_BIND8=	yes
INCLUDE_PATH=	include
PLIST_SUB+=	INCLUDE_PATH=${INCLUDE_PATH}
.else
INCLUDE_PATH=	include/bind
PLIST_SUB+=	INCLUDE_PATH=${INCLUDE_PATH}
.endif

.if defined(PORT_REPLACES_BASE_BIND8)
PKGNAMESUFFIX=	-base
PREFIX=		/usr
BIND_DESTETC=	/etc/namedb
PLIST_SUB+=	FAKE_SBIN=sbin
.else
BIND_DESTETC=	${PREFIX}/etc
PLIST_SUB+=	FAKE_SBIN=bin
.endif

MAN1=		dig.1 dnskeygen.1 dnsquery.1 host.1
MAN3=		getaddrinfo.3 gethostbyname.3 getipnodebyname.3 getnetent.3 \
		getnameinfo.3 inet_cidr.3 hesiod.3 resolver.3 tsig.3
MAN5=		irs.conf.5 named.conf.5 resolver.5
MAN7=		hostname.7 mailaddr.7
MAN8=		named-bootconf.8 named-xfer.8 named.8 ndc.8 nslookup.8 \
		nsupdate.8

PATCH_ARGS=	-s -d ${WRKDIR}
PATCH_DIST_ARGS=	-s -d ${WRKDIR}

WRKSRC=		${WRKDIR}/src

post-patch:
	@${SED} -e "s#\'DESTETC=.*#'DESTETC=${BIND_DESTETC}'#" \
		-e "s#-O2 -g#${CFLAGS}#" \
		${WRKSRC}/port/freebsd/Makefile.set > \
		${WRKSRC}/port/freebsd/Makefile.set.sed
	@${MV} ${WRKSRC}/port/freebsd/Makefile.set.sed \
		${WRKSRC}/port/freebsd/Makefile.set

	@${SED} -e "s#{DESTEXEC}#{DESTBIN}#g" \
		${WRKSRC}/bin/dnskeygen/Makefile > \
		${WRKSRC}/bin/dnskeygen/Makefile.sed
	@${MV} ${WRKSRC}/bin/dnskeygen/Makefile.sed \
		${WRKSRC}/bin/dnskeygen/Makefile

	@${SED} -e "s#\'DESTINC=.*#'DESTINC=${PREFIX}/${INCLUDE_PATH}'#" \
		${WRKSRC}/port/freebsd/Makefile.set > \
		${WRKSRC}/port/freebsd/Makefile.set.sed
	@${MV} ${WRKSRC}/port/freebsd/Makefile.set.sed \
		${WRKSRC}/port/freebsd/Makefile.set

.if defined(PORT_REPLACES_BASE_BIND8)
.for dir in nslookup nsupdate
	@${SED} -e "s#{DESTBIN}#{DESTSBIN}#g" \
	${WRKSRC}/bin/${dir}/Makefile > ${WRKSRC}/bin/${dir}/Makefile.sed
	@${MV} ${WRKSRC}/bin/${dir}/Makefile.sed ${WRKSRC}/bin/${dir}/Makefile
.endfor
.endif

.for f in named.conf.5 named.8
	@${SED} -e "s#/etc/named.conf#${BIND_DESTETC}/named.conf#g" \
		${WRKDIR}/doc/man/${f} > ${WRKDIR}/doc/man/${f}.sed
	@${MV} ${WRKDIR}/doc/man/${f}.sed ${WRKDIR}/doc/man/${f}
.endfor

post-install:
	cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} clean all ${INSTALL_TARGET}

	${INSTALL_DATA} ${WRKSRC}/include/isc/ctl.h \
		${PREFIX}/${INCLUDE_PATH}/isc

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html ${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKDIR}/doc/html/*.html ${DOCSDIR}/html
	${CP} -Rp ${WRKDIR}/src/conf ${DOCSDIR}
.for f in CHANGES DNSSEC LICENSE LICENSE_RSA README SUPPORT TODO
	${INSTALL_DATA} ${WRKDIR}/src/${f} ${DOCSDIR}
.endfor
.for f in DynamicUpdate FAQ.* *.txt
	${INSTALL_DATA} ${WRKDIR}/doc/misc/${f} ${DOCSDIR}/misc
.endfor
.endif

.include <bsd.port.mk>
