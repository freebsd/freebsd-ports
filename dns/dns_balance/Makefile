# Ports collection makefile for:	DNS Balance
# Date created:			5 March 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dns_balance
PORTVERSION=	2.0
CATEGORIES=	dns
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/
DISTNAME=	DNS-Balance-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dynamic load-balancing DNS server

USE_RUBY=	yes
USE_RC_SUBR=	dns_balance

NO_BUILD=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/dns_balance.rb \
			${WRKSRC}/sample/makedb.rb \
			${WRKSRC}/sample/make_namespace.rb

ETCS=		addrdb.rb \
		namespace.rb
ETCDIR=		${PREFIX}/etc/${PORTNAME}
LIBS=		as_search.rb \
		cache.rb \
		datatype.rb \
		log_writer.rb \
		multilog.rb \
		util.rb

PLIST_SUB+=	ETCDIR=${ETCDIR}
SUB_LIST+=	RUBY=${RUBY}

post-patch:
	${SED} -E -e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%PORTNAME%%,${PORTNAME},g" \
		-e "s,%%ETCDIR%%,${ETCDIR},g" \
		${WRKSRC}/dns_balance.rb > ${WRKSRC}/dns_balance

do-install:
#
# Install main executable
#
	${INSTALL_SCRIPT} ${WRKSRC}/dns_balance ${PREFIX}/sbin/
#
# Install sample configuration files
#
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for FILE in ${ETCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${ETCDIR}/${FILE}.dist
. if !exists(${ETCDIR}/${FILE})
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${ETCDIR}/${FILE}
. endif
.endfor

#
# Install library files
#
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for FILE in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/lib/${PORTNAME}/
.endfor

#
# Install port's documentation
#
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}

	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${WRKSRC}/Q_and_A* ${DOCSDIR}
.endif

.include <bsd.port.mk>
