# New ports collection makefile for:	facturier
# Date created:		30 January 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	facturier
PORTVERSION=	2.0.1
CATEGORIES=	french finance
MASTER_SITES=	http://ignu.ungi.org/download/

MAINTAINER=	thierry@pompo.net
COMMENT=	Logiciel de facturation pour P.M.I. & P.M.E.

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${APACHE_PORT}					\
		${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql323-server	\
		${LOCALBASE}/bin/htmldoc:${PORTSDIR}/textproc/htmldoc			\
		${PBASE}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql		\
		${PBASE}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes

APACHE_PORT?=	${PORTSDIR}/www/apache13
APACHE_CNFDIR?=	${LOCALBASE}/etc/apache
APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
PBASE=		${SITE_PERL}

DBOWN?=		PROP_BD
DBPWD?=		MDP_BD

LFACT_REP?=	www/${PORTNAME}
FACT_REP=	${PREFIX}/${LFACT_REP}
FACT_INC=	${PREFIX}/etc/${PORTNAME}
FACT_CNF=	${FACT_REP}/lib/Conf.pm

PLIST_SUB=	FACT_REP=${LFACT_REP}

SS_REPS=	cgi-bin html lib log sql
REINPLACE_ARGS=	-i.beforeFacturier

DOCS=		COPYING README.txt todo.txt

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Vous pouvez définir deux variables :"
	@${ECHO_MSG} "	DBOWN pour le propriétaire de la base MySQL"
	@${ECHO_MSG} "et	DBPWD pour son mot de passe."
	@${ECHO_MSG} ""

post-patch:
# perl PREFIX safeness
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x \
		${REINPLACE_CMD} -E -e 's|/usr/bin/perl|${PERL}|'
	@${FIND} ${WRKSRC} -name \*.beforeFacturier -exec ${RM} {} \;

do-install:
	@${MKDIR} ${FACT_REP}
.for REP in ${SS_REPS}
	@${CP} -Rp ${WRKSRC}/${REP} ${FACT_REP}
.endfor
	@${REINPLACE_CMD} -e "s:%%FACT_REP%%:${FACT_REP}:;s:%%PREFIX%%:${PREFIX}:; \
		s:%%DBOWN%%:${DBOWN}:;s:%%DBPWD%%:${DBPWD}:" ${FACT_CNF}
	@${RM} ${FACT_CNF}.beforeFacturier
	@${CP} -p ${FACT_CNF} ${FACT_CNF}.dist
# Set perms
	@${CHOWN} -R www:www ${FACT_REP}
	@${CHMOD} -R 644 ${FACT_REP}
	@${FIND} ${FACT_REP} -type d -exec ${CHMOD} a+x {} \;
	@${CHMOD} -R u+x ${FACT_REP}/cgi-bin
	@${FIND} ${FACT_REP}/lib -type f -exec ${CHMOD} go-r {} \;
# Configure Apache
	@(if [ -f ${APACHE_CONF} ] ; then \
		${MKDIR} ${FACT_INC} ; \
		${CP} -p ${FILESDIR}/httpd.conf.facturier ${FACT_INC} ; \
		${REINPLACE_CMD} -e "s:%%FACT_REP%%:${FACT_REP}:g" \
			${FACT_INC}/httpd.conf.facturier ; \
		${RM} ${FACT_INC}/httpd.conf.facturier.beforeFacturier ; \
		${ECHO_MSG} "===> Updating ${APACHE_CONF}..." ; \
		${CP} -p ${APACHE_CONF} ${APACHE_CONF}.beforeFacturier ; \
		${ECHO_CMD} "# Le Facturier's cgi-bin directory" >> ${APACHE_CONF} ; \
		${ECHO_CMD} "Include ${FACT_INC}" >> ${APACHE_CONF} ; \
	fi)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
		${SED} -e "s:%%FACT_REP%%:${FACT_REP}:;s:%%DOCSDIR%%:${DOCSDIR}:; \
			s:%%DBOWN%%:${DBOWN}:;s:%%DBPWD%%:${DBPWD}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
