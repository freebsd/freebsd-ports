# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	dns_balance
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.netlab.cs.tsukuba.ac.jp/~yokota/archive/ \
		http://BSDforge.com/projects/source/dns/dns_balance/
DISTNAME=	DNS-Balance-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Dynamic load-balancing DNS server

USE_RUBY=	yes
USES=		shebangfix
USE_RC_SUBR=	dns_balance

NO_BUILD=	yes
BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

SHEBANG_FILES=	${WRKSRC}/dns_balance.rb \
		${WRKSRC}/sample/makedb.rb \
		${WRKSRC}/sample/make_namespace.rb

ETCS=		addrdb.rb \
		namespace.rb
LIBS=		as_search.rb \
		cache.rb \
		datatype.rb \
		log_writer.rb \
		multilog.rb \
		util.rb

PLIST_SUB+=	ETCDIR=${ETCDIR}
SUB_LIST+=	RUBY=${RUBY}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${SED} -E -e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%PORTNAME%%,${PORTNAME},g" \
		-e "s,%%ETCDIR%%,${ETCDIR},g" \
		${WRKSRC}/dns_balance.rb > ${WRKSRC}/dns_balance

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dns_balance ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for FILE in ${ETCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${ETCDIR}/${FILE}.dist
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${LIBS} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${WRKSRC}/Q_and_A* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
