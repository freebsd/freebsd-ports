# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	myitcrm
PORTVERSION=	0.2.9.3
CATEGORIES=	deskutils
MASTER_SITES=	SF/myitcrm/
DISTNAME=	MyITCRM1-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MyIT CRM is a CRM project designed for Computer Servicing and Repairs

LICENSE=	GPLv3

USE_ZIP=	yes
USE_PHP=	mysql session xml
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/MyITCRM-${PORTVERSION}

SUB_FILES=	pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%
PATCH_STRIP=	-p1
WRITEABLE=	conf.php log/access.log cache
PORTEXAMPLES=	htaccess.txt
PORTDOCS=	changelog.txt README.textile
USE_DOS2UNIX=	yes

OPTIONS=	APACHE		"Use Apache webserver" on \
		PHPMOD		"Use php module for Apache" off \
		LIGHTTPD	"Use Lighttpd webserver" off \
		NGINX		"Use Nginx" off

.include <bsd.port.options.mk>

.if defined(WITH_PHPMOD)
WANT_PHP_MOD=	yes
.else
WANT_PHP_CGI=	yes
.endif

.if !defined(WITHOUT_APACHE)
USE_APACHE_RUN=	22+
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif
.if defined(WITH_NGINX)
RUN_DEPENDS+=	nginx:${PORTSDIR}/www/nginx
.endif

# Set files to ignore.
.for file in ${PORTEXAMPLES} ${PORTDOCS} LICENSE.txt
WWW_IGNORE+=	-not -name ${file}
.endfor

.if defined(MAINTAINER_MODE)
trace-distfile: distclean
	@cd ${.CURDIR} && make FETCH_ARGS=-vFpr makesum

rm-install:
	${SU_CMD} '${RM} -rf ${WWWDIR}/install'

.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR} '${WWW_IGNORE}'
	@if [ ! -f ${WWWDIR}/conf.php ]; then \
		${CP} ${WWWDIR}/conf-default.php ${WWWDIR}/conf.php; \
	 fi
.for ent in ${WRITEABLE}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/${ent}
	@${CHMOD} u+w ${WWWDIR}/${ent}
.endfor
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for ex in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${ex} ${EXAMPLESDIR}
.endfor
.endif # NOPORTEXAMPLES
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS

post-install:
	@${CAT} ${PKGMESSAGE}
.if defined(MAINTAINER_MODE)
	@${MAKE} -C ${.CURDIR} rm-install
.endif

.include <bsd.port.mk>
