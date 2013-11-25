# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	maradns
PORTVERSION=	1.4.12
CATEGORIES=	dns
MASTER_SITES=	http://www.maradns.org/download/1.4/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS server with focus on security and simplicity

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

REINPLACE_ARGS=	-i ""
MAKE_ENV=	FLAGS="${CFLAGS}"
CONFIGURE_ENV=	LANG=

USE_BZIP2=	yes
USE_RC_SUBR=	${PORTNAME} zoneserver
USERS=		bind
GROUPS=		bind

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/maradns|${ETCDIR}|g; s|/etc/mararc|${ETCDIR}|g'
	@${FIND} ${WRKSRC} -name '*Makefile*' | ${XARGS} ${REINPLACE_CMD} -e \
		's|make|\$$\{MAKE\}|g ; \
		 s|^FLAGS =|#FLAGS =|g'

do-install:
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

	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_full_mararc ${STAGEDIR}${PREFIX}/etc/mararc.sample

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_csv2 ${STAGEDIR}${ETCDIR}/example_csv2
	${MKDIR} ${STAGEDIR}${ETCDIR}/logger

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc/en/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.* ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/QuickStart ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/README ${STAGEDIR}${DOCSDIR}/en
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} misc ${STAGEDIR}${DOCSDIR}/en)
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} pdf ${STAGEDIR}${DOCSDIR}/en)
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} tutorial ${STAGEDIR}${DOCSDIR}/en)
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} text ${STAGEDIR}${DOCSDIR}/en)
.endif

.include <bsd.port.mk>
