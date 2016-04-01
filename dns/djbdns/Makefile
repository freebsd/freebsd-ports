# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME?=	djbdns
PORTVERSION?=	${DJBDNS_VER}
PORTREVISION?=	21
PORTEPOCH?=	1
CATEGORIES?=	dns
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/
DISTNAME=	djbdns-${DJBDNS_VER}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	lx@FreeBSD.org
COMMENT?=	Collection of secure and reliable DNS tools

RUN_DEPENDS=	setuidgid:sysutils/daemontools \
		tcpserver:sysutils/ucspi-tcp

CONFLICTS=	djbdns-tools-[0-9]*
LEGAL_TEXT=	No license -- see http://cr.yp.to/softwarelaw.html

OPTIONS_DEFINE=	DUMPCACHE IP6 IGNOREIP JUMBO MAN PERSISTENT_MMAP SRV DNSCURVE ADD_USERS
OPTIONS_DEFAULT=	MAN
OPTIONS_SUB=	yes

DUMPCACHE_DESC=	persistent cache for dnscache
IP6_DESC=	IPv6 support by Felix von Leitner
IGNOREIP_DESC=	ignoreip2 patch by Russell Nelson
JUMBO_DESC=	jumbo patch by Claudiu Costin
MAN_DESC=	manual pages by Gerritt Pape
PERSISTENT_MMAP_DESC=	persistent mmap patch by Lennert Buytenhek
SRV_DESC=	SRV record patch by Michael Handler
DNSCURVE_DESC=	DNSCurve support by Matthew Dempsky
ADD_USERS_DESC=	Add dnscache, tinydns and dnslog users/groups

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MADD_USERS}
USERS?=	dnscache tinydns dnslog
GROUPS?=dnscache tinydns dnslog
.endif

.if ${PORT_OPTIONS:MJUMBO}
.if ${PORT_OPTIONS:MIP6} || ${PORT_OPTIONS:MIGNOREIP} || ${PORT_OPTIONS:MSRV} || \
	${PORT_OPTIONS:MDNSCURVE}
BROKEN=		The jumbo patch currently conflicts with the IPv6, ignoreip2, SRV and DNSCURVE patches
.endif

PATCH_SITES+=	http://people.FreeBSD.org/~roam/ports/dns/djbdns/:jumbo \
		LOCAL/roam/dns/djbdns:jumbo
PATCHFILES+=	jumbo-p13.patch.gz:jumbo
PATCH_DIST_STRIP=	-p1
.if ${PORT_OPTIONS:MDUMPCACHE}
CFLAGS+=	-DDUMPCACHE
.endif
.endif

.if ${PORT_OPTIONS:MMAN}
MANDATE=	-20031023
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:manpages
DISTFILES+=	${DISTNAME}-man${MANDATE}.tar.gz:manpages
.endif

.if ${PORT_OPTIONS:MIP6}
PKGNAMESUFFIX=	-ipv6
PORTVERSION=	${DJBDNS_VER}.${DJBDNS_V6_VER:S/test/b/:S/diff//}
PATCH_SITES+=	http://www.fefe.de/dns/:ipv6
PATCHFILES+=	${PORTNAME}-${DJBDNS_VER}-${DJBDNS_V6_VER}.diff.bz2:ipv6
PATCH_DIST_STRIP=	-p1
EXTRA_PATCHES+=	${FILESDIR}/uint32.patch ${FILESDIR}/djbdns-ipv6-ooyama.patch
.endif

.if ${PORT_OPTIONS:MDUMPCACHE} && ! ${PORT_OPTIONS:MJUMBO}
.if ${PORT_OPTIONS:MIP6}
BROKEN=		The IPv6 and dnscache-dumpcache patches are currently in conflict
.endif
PATCH_SITES+=	http://efge.free.fr/djbdns/:dumpcache
PATCHFILES+=	patch-dnscache-dumpcache-v4.txt:dumpcache
PATCH_DIST_STRIP=	-p1
CFLAGS+=	-DDUMPCACHE
.endif

.if ${PORT_OPTIONS:MIGNOREIP}
.if ${PORT_OPTIONS:MIP6}
BROKEN=		The IPv6 patch already includes the ignoreip2 functionality
.endif
PATCH_SITES+=	http://tinydns.org/:ignoreip
PATCHFILES+=	djbdns-1.05-ignoreip2.patch:ignoreip
PATCH_DIST_STRIP=	-p1
.endif

.if ${PORT_OPTIONS:MPERSISTENT_MMAP}
PATCH_SITES+=	http://people.FreeBSD.org/~roam/ports/patches/dns/:persistent
PATCHFILES+=	tinydns-persistmmap-20040418.patch:persistent
PATCH_DIST_STRIP=	-p1
.endif

.if ${PORT_OPTIONS:MSRV}
PATCH_SITES+=	http://tinydns.org/:srv
PATCHFILES+=	srv-patch:srv
PATCH_DIST_STRIP=	-p1
.endif

.if ${PORT_OPTIONS:MDNSCURVE}
.if ${PORT_OPTIONS:MIP6}
BROKEN=	The IPv6 and DNSCurve patches are currently in conflict
.endif
PATCH_SITES+=	http://shinobi.dempsky.org/~matthew/patches/:dnscurve
PATCHFILES+=	djbdns-dnscurve-20090602.patch:dnscurve
PATCH_DIST_STRIP=	-p1
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
BUILD_DEPENDS+=	nacl-sha256:security/nacl
.endif

DJBDNS_VER=	1.05
DJBDNS_V6_VER=	test23

ALL_TARGET=	prog
INSTALL_TARGET=	setup check

.if ${PORT_OPTIONS:MIP6}
PLIST_SUB+=	WITH_IP6=""
.else
PLIST_SUB+=	WITH_IP6="@comment "
.endif

post-patch:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${STAGEDIR}${PREFIX}" > ${WRKSRC}/conf-home.stage
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home

post-build:
	@${ECHO_MSG} "===> Rebuilding DJB installer to respect STAGEDIR"
	@${MV} -f ${WRKSRC}/conf-home ${WRKSRC}/conf-home.sav
	@${MV} -f ${WRKSRC}/conf-home.stage ${WRKSRC}/conf-home
	@cd ${WRKSRC} ; ${RM} -f install instcheck install.o instcheck.o hier.o auto_home.o auto_home.c
	@cd ${WRKSRC} ; ${DO_MAKE_BUILD} install instcheck
	@${TOUCH} ${WRKSRC}/*-conf
	@${MV} -f ${WRKSRC}/conf-home.sav ${WRKSRC}/conf-home

.if ${PORT_OPTIONS:MMAN}
post-install:
	@${INSTALL_MAN} ${WRKDIR}/djbdns-man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKDIR}/djbdns-man/*.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
.endif

.include <bsd.port.mk>
