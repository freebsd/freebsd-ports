# Ports collection makefile for:	DNS Balance
# Date created:			5 March 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dns_balance
PORTVERSION=	1.1
CATEGORIES=	dns
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/
DISTNAME=	DNS-Balance-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A dynamic load-balancing DNS server

BROKEN=		Unfetchable

USE_RUBY=	yes
USE_RC_SUBR=	yes

NO_BUILD=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/dns_balance.rb \
			${WRKSRC}/sample/makedb.rb \
			${WRKSRC}/sample/makeringdb.rb \
			${WRKSRC}/sample/make_namespace.rb
ETCS=		addrdb.rb \
		namespace.rb
LIBS=		as_search.rb \
		cache.rb \
		datatype.rb \
		log_writer.rb \
		multilog.rb \
		util.rb
EXAMPLES_EXEC=	make_namespace.rb \
		makedb.rb \
		makeringdb.rb \
		ringupdate.sh
EXAMPLES_DATA=	addr \
		addr.ring \
		addr.ring.txt \
		namespace.txt
DOCS_EN=	Q_and_A.dns_balance.eng \
		README.dns_balance.eng \
		README.dnsbalance+daemontools.eng
DOCS_JA=	ChangeLog \
		Q_and_A.dns_balance \
		README.dns_balance \
		README.dnsbalance+daemontools
SUBST=		PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-patch:
	${SED} ${SUBST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${WRKSRC}/dns_balance.rb > ${WRKSRC}/dns_balance
	${SED} ${SUBST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${FILESDIR}/dns_balance.sh > ${WRKSRC}/dns_balance.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dns_balance ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for f in ${ETCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/${PORTNAME}/${f}-dist
	[ -f ${PREFIX}/etc/${PORTNAME}/${f} ] || ${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/${PORTNAME}/${f}
.endfor
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for f in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/${PORTNAME}/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/dns_balance.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES_EXEC}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${EXAMPLESDIR}/
.endfor
.for f in ${EXAMPLES_DATA}
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f} ${EXAMPLESDIR}/
.endfor
	${MKDIR} ${DOCSDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${DOCSDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
