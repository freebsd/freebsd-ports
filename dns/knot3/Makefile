PORTNAME=	knot
DISTVERSION=	${KNOT_VERSION}
CATEGORIES=	dns
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		https://dns.company/downloads/knot-dns/
PKGNAMESUFFIX?=	3

MAINTAINER=	freebsd@dns.company
COMMENT=	High performance authoritative-only DNS server
WWW=		https://www.knot-dns.cz/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		lmdb>=0.9.15:databases/lmdb
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		liblmdb.so:databases/lmdb

USES=		alias compiler:c11 libtool localbase pkgconfig tar:xz
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cap-ng=no \
		--enable-recvmmsg=no \
		--enable-systemd=no \
		--mandir=${PREFIX}/share/man \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

CONFLICTS=	knot-1.* knot1-[0-6].* knot2-[0-9].*

DATADIR=	/var/db/${PORTNAME}
RUNDIR=		/var/run/${PORTNAME}
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB=	RUNDIR=${RUNDIR} \
		GROUPS=${GROUPS} \
		USERS=${USERS}

PORTDOCS=	COPYING NEWS

OPTIONS_DEFINE=			DAEMON UTILS DOCS EXAMPLES
OPTIONS_DEFAULT=		DAEMON FASTPARSER DOH DOQ IDN MODACL MODAUTH \
				MODCOOKIES MODPROXY MODNOUDP MODPROBE MODRRL \
				MODSIGN MODSTATS MODSYNTH MODWHOAMI UTILS
OPTIONS_GROUP=			DAEMONGR UTILGR
OPTIONS_GROUP_DAEMONGR=		DNSTAP FASTPARSER MODACL MODAUTH MODCOOKIES \
				MODPROXY MODGEO MODNOUDP MODPROBE MODRRL \
				MODSIGN MODSTATS MODSYNTH MODWHOAMI
OPTIONS_GROUP_UTILGR=		DOH DOQ IDN
NO_OPTIONS_SORT=		yes
OPTIONS_SUB=			yes

DAEMONGR_DESC=			Options for daemon
DAEMON_DESC=			Install daemon
DNSTAP_DESC=			dnstap support (see dnstap.info)
DOCS_DESC=			Install documentation
DOH_DESC=			Support for DNS over HTTPS (DoH)
DOQ_DESC=			Support for DNS over QUIC (DoQ)
FASTPARSER_DESC=		Fast zone parser (demands compiling)
IDN_DESC=			Support for International Domain Names (IDN)
MODACL_DESC=			Build 'queryacl' module
MODAUTH_DESC=			Build 'authsignal' module
MODCOOKIES_DESC=		Build 'cookies' module
MODGEO_DESC=			Build 'geodb' module
MODNOUDP_DESC=			Build 'noudp' module
MODPROBE_DESC=			Build 'probe' module
MODPROXY_DESC=			Build 'dnsproxy' module
MODRRL_DESC=			Build 'rrl' module
MODSIGN_DESC=			Build 'onlinesign' module
MODSTATS_DESC=			Build 'stats' module
MODSYNTH_DESC=			Build 'synthrecord' module
MODWHOAMI_DESC=			Build 'whoami' module
UTILGR_DESC=			Options for utilities
UTILS_DESC=			Install utulities

DAEMON_LIB_DEPENDS=		liburcu.so:sysutils/liburcu
DAEMON_USES=			libedit
DAEMON_CONFIGURE_ENABLE=	daemon modules
DAEMON_CONFIGURE_WITH=		rundir=${RUNDIR} storage=${DATADIR}
DAEMON_SUB_FILES=		pkg-message
DAEMON_VARS=			USE_RC_SUBR=${PORTNAME}

DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm \
				libprotobuf-c.so:devel/protobuf-c
DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_CONFIGURE_WITH=		module-dnstap=yes
#
# XXX: because `kdig_CPPFLAGS += $(DNSTAP_CFLAGS)' line is missing from
# `src/Makefile.am' file (and thus pre-generated `src/Makefile.in') which
# should contain "$libfstrm_CFLAGS $libprotobuf_c_CFLAGS" set by configure
# script, provide it here explicitly as patching those files would result
# in higher line count.  Ideally this bug should be fixed upstream.
DNSTAP_CPPFLAGS=		-I${LOCALBASE}/include

DOCS_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx
DOCS_CONFIGURE_ENABLE=		documentation

DOH_LIB_DEPENDS=		libnghttp2.so:www/libnghttp2

DOQ_LIB_DEPENDS=		libngtcp2.so:net/libngtcp2 \
				libngtcp2_crypto_gnutls.so:net/libngtcp2-gnutls
DOQ_CONFIGURE_ON=		--enable-quic=yes
DOQ_CONFIGURE_OFF=		--enable-quic=no

FASTPARSER_CONFIGURE_ENABLE=	fastparser

IDN_LIB_DEPENDS=		libidn2.so:dns/libidn2
IDN_CONFIGURE_WITH=		libidn

MODACL_CONFIGURE_WITH=		module-queryacl=yes

MODAUTH_CONFIGURE_WITH=		module-authsignal=yes

MODCOOKIES_CONFIGURE_WITH=	module-cookies=yes

MODGEO_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
MODGEO_CONFIGURE_ENABLE=	maxminddb
MODGEO_CONFIGURE_WITH=		module-geoip=yes

MODNOUDP_CONFIGURE_WITH=	module-noudp=yes

MODPROBE_CONFIGURE_WITH=	module-probe=yes

MODPROXY_CONFIGURE_WITH=	module-dnsproxy=yes

MODRRL_CONFIGURE_WITH=		module-rrl=yes

MODSIGN_CONFIGURE_WITH=		module-onlinesign=yes

MODSTATS_CONFIGURE_WITH=	module-stats=yes

MODSYNTH_CONFIGURE_WITH=	module-synthrecord=yes

MODWHOAMI_CONFIGURE_WITH=	module-whoami=yes

UTILS_CONFIGURE_ENABLE=		utilities

.include <bsd.port.options.mk>

.if ${ARCH} == i386
USES+=		autoreconf
.endif

post-patch-DAEMON-on:
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${RM} -r ${WRKSRC}/src/zscanner/scanner.c

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.8 ${STAGEDIR}${PREFIX}/share/man/man8

post-install-DAEMON-on:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${RUNDIR}

post-install:
.if ${PORT_OPTIONS:MDAEMON} && ${PORT_OPTIONS:MEXAMPLES}
	${MV} ${STAGEDIR}${ETCDIR}/knot.sample.conf ${STAGEDIR}${ETCDIR}/knot.conf.sample
.else
	${RM} ${STAGEDIR}${ETCDIR}/knot.sample.conf
.endif

.include "knotdns.mk"
.include <bsd.port.mk>
