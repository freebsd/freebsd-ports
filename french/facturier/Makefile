# New ports collection makefile for:	facturier
# Date created:		30 January 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	facturier
PORTVERSION=	2.1.1
CATEGORIES=	french finance
MASTER_SITES=	http://ignu.ungi.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@pompo.net
COMMENT=	Logiciel de facturation pour P.M.I. & P.M.E.

RUN_DEPENDS=	${LOCALBASE}/bin/htmldoc:${PORTSDIR}/textproc/htmldoc			\
		${PBASE}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-Mysql		\
		${PBASE}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_APACHE=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes

.if defined(WITH_APACHE2)
APACHE_CNFDIR=	${LOCALBASE}/etc/apache2
.else
APACHE_CNFDIR=	${LOCALBASE}/etc/apache
.endif

APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
PBASE=		${SITE_PERL}

DBOWN?=		PROP_BD
DBPWD?=		MDP_BD
DBSERV?=	localhost

LFACT_REP?=	www/${PORTNAME}
FACT_REP=	${PREFIX}/${LFACT_REP}
FACT_INC=	${PREFIX}/etc/${PORTNAME}
FACT_CNF=	${FACT_REP}/lib/Conf.pm

PLIST_SUB=	FACT_REP=${LFACT_REP}

SS_REPS=	cgi-bin html lib log sql
REINPLACE_ARGS=	-i.beforeFacturier

PORTDOCS=	COPYING README.txt todo.txt

PKGMESSAGE=	${WRKDIR}/pkg-message

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Vous pouvez définir trois variables :"
	@${ECHO_MSG} "	DBOWN pour le propriétaire de la base MySQL"
	@${ECHO_MSG} "et	DBPWD pour son mot de passe,"
	@${ECHO_MSG} "et	DBSERV pour le nom d'hôte du serveur MySQL"
	@${ECHO_MSG} "		(localhost par défaut)."
	@${ECHO_MSG} ""

post-extract:
	@(cd ${WRKDIR} &&			\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS}	\
		${PORTNAME}-version${PORTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})
	@${RM} ${WRKDIR}/${PORTNAME}-version${PORTVERSION}${EXTRACT_SUFX}

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
	@${REINPLACE_CMD} -e "s:%%FACT_REP%%:${FACT_REP}:;s:%%PREFIX%%:${PREFIX}:;	\
		s:%%DBOWN%%:${DBOWN}:;s:%%DBPWD%%:${DBPWD}:;s:%%DBSERV%%:${DBSERV}:"	\
		${FACT_CNF}
	@${RM} ${FACT_CNF}.beforeFacturier
	@${CP} -p ${FACT_CNF} ${FACT_CNF}.dist
# Set perms
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${FACT_REP}
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
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${SED} -e "s:/usr/local/www/facturier:${FACT_REP}:"			\
			-e "s:/usr/local/share/doc/facturier:${DOCSDIR}:"	\
			-e "s:%%DBOWN%%:${DBOWN}:;s:%%DBPWD%%:${DBPWD}:"	\
			-e "s:%%DBSERV%%:${DBSERV}:"				\
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
