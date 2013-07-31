# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	facturier
PORTVERSION=	2.1.2
PORTREVISION=	4
CATEGORIES=	french finance
MASTER_SITES=	http://ignu.ungi.org/download/	\
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logiciel de facturation pour P.M.I. & P.M.E.

RUN_DEPENDS=	${LOCALBASE}/bin/htmldoc:${PORTSDIR}/textproc/htmldoc			\
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql	\
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USES=		perl5
USE_APACHE_RUN=	22+
USE_PERL5=	run
USE_MYSQL=	yes

SUB_FILES=	pkg-deinstall

APACHE_CONF=	${LOCALBASE}/${APACHEETCDIR}/httpd.conf

DBOWN?=		PROP_BD
DBPWD?=		MDP_BD
DBSERV?=	localhost
FACT_CNF=	lib/Conf.pm

SS_REPS=	cgi-bin html lib log sql

PORTDOCS=	README.txt todo.txt

FACT_HTTP_CONF=	facturier.conf
SUB_FILES+=	pkg-message ${FACT_HTTP_CONF}
SUB_LIST=	DBOWN=${DBOWN} DBPWD=${DBPWD} DBSERV=${DBSERV} \
		APACHE_CONF=${APACHE_CONF}
PKGMESSAGE=	${WRKDIR}/pkg-message

TRASHFILES=	lib/Conf.pm~ cgi-bin/.articlemodif.cgi.swp lib/.Conf.pm.swp	\
		html/UNGI/Editfacturemaj.pm.back html/temp/log_facture.gif.back

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Vous pouvez définir trois variables :"
	@${ECHO_MSG} "	DBOWN pour le propriétaire de la base MySQL"
	@${ECHO_MSG} "et	DBPWD pour son mot de passe,"
	@${ECHO_MSG} "et	DBSERV pour le nom d'hôte du serveur MySQL"
	@${ECHO_MSG} "		(localhost par défaut)."
	@${ECHO_MSG} ""

post-extract:
	-@${RM} -r ${WRKSRC}/CVS
	@${RM} ${TRASHFILES:S|^|${WRKSRC}/|}

post-patch:
# perl PREFIX safeness
	@${FIND} ${WRKSRC}/cgi-bin -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|'

	@${REINPLACE_CMD} -e "s:%%WWWDIR%%:${WWWDIR}:;s:%%PREFIX%%:${PREFIX}:;	\
		s:%%DBOWN%%:${DBOWN}:;s:%%DBPWD%%:${DBPWD}:;s:%%DBSERV%%:${DBSERV}:;	\
		s:%%LOCALBASE%%:${LOCALBASE}:"	${WRKSRC}/lib/Conf.pm

	@${FIND} ${WRKSRC} \( -name "*.bak" -o -name "*.orig" \) -delete
	@${MV} ${WRKSRC}/${FACT_CNF} ${WRKSRC}/${FACT_CNF}.dist

do-install:
	@${MKDIR} ${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/version.txt ${WWWDIR}

.for REP in ${SS_REPS}
	@${CP} -Rp ${WRKSRC}/${REP} ${WWWDIR}
.endfor

	@[ -f ${WWWDIR}/${FACT_CNF} ] || \
		${CP} ${WWWDIR}/${FACT_CNF}.dist ${WWWDIR}/${FACT_CNF}

# Set perms
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 644 ${WWWDIR}
	@${FIND} ${WWWDIR} -type d -exec ${CHMOD} a+x {} \;
	@${CHMOD} -R u+x ${WWWDIR}/cgi-bin
	@${FIND} ${WWWDIR}/lib -type f -exec ${CHMOD} go-r {} \;
	@${CHMOD} -R 775 ${WWWDIR}/log

# Configure Apache
# If apache13 is gone from the ports tree,
# then it's saver to use the Include directory
	${MKDIR} ${ETCDIR}
	${CP} ${WRKDIR}/${FACT_HTTP_CONF} ${ETCDIR}
	@(if [ -f ${APACHE_CONF} ] ; then \
		${ECHO_MSG} "===> Updating ${APACHE_CONF}..." ; \
		${ECHO_CMD} "# Le Facturier's cgi-bin directory" >> ${APACHE_CONF} ; \
		${ECHO_CMD} "Include ${ETCDIR}" >> ${APACHE_CONF} ; \
	fi)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
