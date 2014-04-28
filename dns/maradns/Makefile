# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	maradns
PORTVERSION=	2.0.09
CATEGORIES=	dns
MASTER_SITES=	http://www.maradns.org/download/2.0/${PORTVERSION}/\
		SF/${PORTNAME}/MaraDNS/${PORTVERSION}/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS server with focus on security and simplicity

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEADWOOD_VER=	3.2.05

REINPLACE_ARGS=	-i ""
MAKE_ENV=	FLAGS="${CFLAGS}"
CONFIGURE_ENV=	LANG=

HAS_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME} zoneserver Deadwood
USES=		tar:bzip2
USERS=		bind
GROUPS=		bind
INSTALL_TARGET=	install PREFIX=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	IPV6 DOCS EXAMPLES
OPTIONS_DEFAULT=	IPV6
IPV6_DESC=	With support for IPv6

IPV6_CONFIGURE_ON=	--ipv6

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's/cc/${CC}/' ${WRKSRC}/build/Makefile.freebsd
	@${FIND} ${WRKSRC} -type f ! -name "*.orig" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/maradns|${ETCDIR}|g; s|/etc/mararc|${ETCDIR}|g' -e\
		's|/etc/deadwood|${ETCDIR}|g' -e\
		's| = 99| = 53|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deadwood-${DEADWOOD_VER}/src/Deadwood ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/server/maradns ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/getzone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/fetchzone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/zoneserver ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/askmara ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/duende ${STAGEDIR}${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/doc/en/man/askmara.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/getzone.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/fetchzone.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/maradns.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/zoneserver.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/duende.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/mararc.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv1.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv2.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv2_txt.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/Deadwood.1 ${STAGEDIR}${MANPREFIX}/man/man1

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_full_mararc ${STAGEDIR}${ETCDIR}/mararc.sample
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_csv2 ${STAGEDIR}${ETCDIR}/csv2.sample
	${INSTALL_DATA} ${WRKSRC}/deadwood-${DEADWOOD_VER}/doc/dwood3rc ${STAGEDIR}${ETCDIR}/dwood3rc.sample

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${RM} -rf ${STAGEDIR}${DOCSDIR}/man \
		${STAGEDIR}${DOCSDIR}/source \
		${STAGEDIR}${DOCSDIR}/pdf
	@${FIND} ${STAGEDIR}${DOCSDIR} -name Makefile -delete
	${MV} ${STAGEDIR}${DOCSDIR}/examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
