# New ports collection makefile for:    mysqlman
# Date created:         06.06.2002
# Whom: Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$

PORTNAME=	mysqlman
PORTVERSION=    1.09
CATEGORIES=	databases www
MASTER_SITES=	#http://www.gossamer-threads.com/scripts/mysqlman/index.htm
DISTNAME=	mysqlman

MAINTAINER=	Janos.Mohacsi@bsd.hu

RUN_DEPENDS=    ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${WWW_DIR}:${PORTSDIR}/www/apache13

RESTRICTED=	"not redistributable, license agreement required"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}
USE_PERL5=	yes
NO_BUILD=	yes

# to determine whether apache installed
WWW_DIR=        ${LOCALBASE}/www/
#install dir of mysqlman
MYMANDIR=      www/mysqlman-${PORTVERSION}

#do the substitution according to the install place
PLIST_SUB+=     MYMANDIR=${MYMANDIR}

#FILES to patch
f="mysql.cgi"

#Web user
WEBUSER?=	www:www

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTFILES})
IGNORE=	You need to read the license agreement on \
	http://www.gossamer-threads.com/scripts/mysqlman/index.htm and \
	download on your own. Once ${DISTFILES} has been downloaded, move \
	it to ${DISTDIR} and then restart this build
.endif

do-configure:
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}.bak && ${SED} <${WRKSRC}/${f}.bak \
		s+%%PATHPERLBIN%%+${PERL5}+g >${WRKSRC}/${f}

do-install:
	@${FIND} ${WRKSRC} ! \( -path "*/${f}*" -or -path "*/mysql.cfg" \) | ${XARGS} -n1 ${SH} -c 'if ${TEST} -d $$0; \
		then ${MKDIR} ${PREFIX}/${MYMANDIR}$${0#${WRKSRC}}; \
		else ${INSTALL_DATA} $$0 ${PREFIX}/${MYMANDIR}$${0#${WRKSRC}}; fi'
	@${INSTALL_SCRIPT} ${WRKSRC}/mysql.cgi ${PREFIX}/${MYMANDIR}
	@if [ -L ${PREFIX}/www/mysqlman ]; then \
		${ECHO} "Updating ${PREFIX}/www/mysqlman symbolic link" ; \
		${RM} ${PREFIX}/www/mysqlman ; \
	fi
	${LN} -s ${PREFIX}/${MYMANDIR} ${PREFIX}/www/mysqlman

post-install:
	@${CHOWN} ${WEBUSER} ${PREFIX}/${MYMANDIR}/templates/compiled
	@${INSTALL_DATA} ${WRKSRC}/mysql.cfg ${PREFIX}/${MYMANDIR}/mysql.cfg.dist
	@${ECHO} ""
	@${ECHO} "Sample config installed at \
			${PREFIX}/${MYMANDIR}/mysql.cfg.dist"
	@${ECHO} "Modify to your needs!"
	@${ECHO} ""

.include <bsd.port.post.mk>
