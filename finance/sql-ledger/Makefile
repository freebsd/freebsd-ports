# Created by: lth@FreeBSD.org
# $FreeBSD$

PORTNAME=	sql-ledger
PORTVERSION=	3.2.9
CATEGORIES=	finance perl5
MASTER_SITES=	http://www.sql-ledger.com/source/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Double entry accounting system

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		apache:run,2.2+ perl5 pgsql shebangfix

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message sql-ledger-httpd.conf
SHEBANG_FILES=	*.pl locale/*/*.pl bin/*/*.pl
NO_ARCH=	yes

ROOT_DIRS=	SL bin css doc images js locale spool sql templates users
ROOT_FILES=	VERSION favicon.ico index.html menu.ini
ROOT_SCRIPTS=	admin.pl am.pl ap.pl ar.pl bp.pl ca.pl cp.pl ct.pl gl.pl hr.pl \
	       	ic.pl im.pl ir.pl is.pl jc.pl login.pl menu.pl oe.pl pe.pl ps.pl \
	       	rc.pl rd.pl rp.pl setup.pl sm.pl vr.pl

.include <bsd.port.pre.mk>
do-install:
.if ${APACHE_VERSION:M24}
	@${REINPLACE_CMD} -e '/Order/d' \
		-e 's/Deny from All/Require all denied/g' \
		-e 's/Allow from All/Require all granted/g' \
		${WRKDIR}/sql-ledger-httpd.conf
.endif
	${INSTALL_DATA} ${WRKDIR}/sql-ledger-httpd.conf ${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}/${WWWDIR}
.for dir in ${ROOT_DIRS}
	@${MKDIR} ${STAGEDIR}/${WWWDIR}/${dir}
	@cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/${dir}
.endfor
.for f in ${ROOT_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
.for f in ${ROOT_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor

post-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
	${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type d | \
	${SED} -e 's#^${STAGEDIR}#@dir #' >> ${TMPPLIST}
	${INSTALL_DATA} ${WRKSRC}/sql-ledger.conf.default \
	${STAGEDIR}/${WWWDIR}/sql-ledger.conf.sample
	@${ECHO} @sample ${WWWDIR}/sql-ledger.conf.sample >> ${TMPPLIST}
	@${ECHO_CMD} "etc/sql-ledger-httpd.conf" >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}

.include <bsd.port.post.mk>
