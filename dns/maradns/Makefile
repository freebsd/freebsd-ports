# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	maradns
PORTVERSION=	2.0.13
CATEGORIES=	dns
MASTER_SITES=	http://maradns.samiam.org/download/2.0/${PORTVERSION}/\
		SF/${PORTNAME}/MaraDNS/${PORTVERSION}/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS server with focus on security and simplicity

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEADWOOD_VER=	3.2.09

REINPLACE_ARGS=	-i ""
MAKE_ENV=	FLAGS="${CFLAGS}"
CONFIGURE_ENV=	LANG=

HAS_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME} zoneserver Deadwood
USES=		tar:bz2 shebangfix
USERS=		bind
GROUPS=		bind
INSTALL_TARGET=	install PREFIX=${STAGEDIR}${PREFIX}
SHEBANG_FILES=	${WRKSRC}/tools/bind2csv2.py

OPTIONS_DEFINE=	IPV6 DOCS EXAMPLES CONV
OPTIONS_SUB=	yes
CONV_DESC=	Install bind2csv2 tool (needs python)

IPV6_CONFIGURE_ON=	--ipv6
CONV_USES=	python:run

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|\<cc\>|${CC}|' ${WRKSRC}/build/Makefile.freebsd
	@${FIND} ${WRKSRC} -type f ! -name "*.orig" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/maradns|${ETCDIR}|g; s|/etc/mararc|${ETCDIR}|g; \
		 s|/etc/deadwood|${ETCDIR}|g; s| = 99| = 53|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deadwood-${DEADWOOD_VER}/src/Deadwood ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/server/maradns ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/fetchzone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/getzone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/zoneserver ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/askmara ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/duende ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/misc/mqhash ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/bind2csv2.py ${STAGEDIR}${PREFIX}/bin/bind2csv2

	${INSTALL_MAN} ${WRKSRC}/doc/en/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/*.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/*.5 ${STAGEDIR}${MANPREFIX}/man/man5

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_full_mararc ${STAGEDIR}${ETCDIR}/mararc.sample
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_csv2 ${STAGEDIR}${ETCDIR}/csv2.sample
	${INSTALL_DATA} ${WRKSRC}/deadwood-${DEADWOOD_VER}/doc/dwood3rc ${STAGEDIR}${ETCDIR}/dwood3rc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${RM} -r ${STAGEDIR}${DOCSDIR}/man \
		${STAGEDIR}${DOCSDIR}/source \
		${STAGEDIR}${DOCSDIR}/pdf
	@${FIND} ${STAGEDIR}${DOCSDIR} -name Makefile -delete

post-install-EXAMPLES-on:
	${MV} ${STAGEDIR}${DOCSDIR}/examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
