PORTNAME=	maradns
PORTVERSION=	3.5.0036
CATEGORIES=	dns
MASTER_SITES=	https://maradns.samiam.org/download/3.5/${PORTVERSION}/

MAINTAINER=	takefu@airport.fm
COMMENT=	DNS server with focus on security and simplicity
WWW=		https://maradns.samiam.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libeditline.so:devel/editline

USES=		cpe shebangfix tar:xz
USE_RC_SUBR=	${PORTNAME} zoneserver deadwood

SHEBANG_FILES=	${WRKSRC}/doc/en/tutorial/make.index

HAS_CONFIGURE=	yes

USERS=		bind
GROUPS=		bind

OPTIONS_DEFINE=	DOCS EXAMPLES IPV6 MANPAGES
OPTIONS_SUB=	yes

IPV6_CONFIGURE_OFF=	--noipv6
DEADWOOD_VER=	deadwood-${PORTVERSION}
EXAMPLES=	auth_mararc csv2 full_mararc mararc recursive_mararc \
		simple_csv1

post-extract:
	${RM} ${WRKSRC}/doc/en/man/mqhash.1

post-patch:
	cd ${PATCH_WRKSRC} && \
	    ${CAT} ${FILESDIR}/localbase | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/maradns|${ETCDIR}|g; s|/etc/mararc|${ETCDIR}|g; \
		 s|/etc/deadwood|${ETCDIR}|g; s| = 99| = 53|g'

post-patch-IPV6-on:
	${ECHO_MSG} ipv6_bind_address = \"::1\" \
	    >> ${WRKSRC}/doc/en/examples/example_full_mararc
	${REINPLACE_CMD} -e 's|127.0.0.1/16|127.0.0.1/16,\ ::1/128|' \
	    ${WRKSRC}/${DEADWOOD_VER}/doc/dwood3rc

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	cd ${WRKSRC} && ${INSTALL_PROGRAM} \
	    tools/askmara tools/duende tcp/fetchzone tcp/getzone \
	    coLunacyDNS/lunacy/lunacy \
	    ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_PROGRAM} \
	    coLunacyDNS/coLunacyDNS server/maradns tcp/zoneserver \
	    ${DEADWOOD_VER}/src/Deadwood \
	    ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_full_mararc \
	    ${STAGEDIR}${ETCDIR}/mararc.sample
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_csv2 \
	    ${STAGEDIR}${ETCDIR}/csv2.sample
	${INSTALL_DATA} ${WRKSRC}/${DEADWOOD_VER}/doc/dwood3rc \
	    ${STAGEDIR}${ETCDIR}/dwood3rc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/en/text/ && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name Makefile"
	cd ${WRKSRC} && ${INSTALL_DATA} \
	    coLunacyDNS/doc/coLunacyDNS.txt maradns.gpg.key \
	    ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc/en/source && \
	    ${INSTALL_DATA} ${EXAMPLES:S/^/example_/g} ${STAGEDIR}${EXAMPLESDIR}

post-install-MANPAGES-on:
.for N in 1 5 8
	cd ${WRKSRC}/doc/en/man && \
	    ${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man${N} && \
	    ${INSTALL_MAN} *.${N} ${STAGEDIR}${PREFIX}/share/man/man${N}
.endfor

.include <bsd.port.mk>
