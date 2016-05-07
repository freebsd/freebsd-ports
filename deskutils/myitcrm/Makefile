# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	myitcrm
PORTVERSION=	0.2.9.3
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	SF/myitcrm/
DISTNAME=	MyITCRM1-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MyIT CRM is a CRM project designed for Computer Servicing and Repairs

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

USES=		dos2unix zip
USE_PHP=	mysqli session xml
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/MyITCRM-${PORTVERSION}

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
PATCH_STRIP=	-p1
WRITEABLE=	conf.php.sample log/access.log cache
PORTEXAMPLES=	htaccess.txt
PORTDOCS=	changelog.txt README.textile

OPTIONS_DEFINE=	APACHE PHPMOD LIGHTTPD NGINX DOCS EXAMPLES
OPTIONS_DEFAULT=	APACHE
PHPMOD_DESC=	Use PHP module for Apache
NGINX_DESC=	Use Nginx

APACHE_USE=	APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
NGINX_RUN_DEPENDS=	nginx:www/nginx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHPMOD}
WANT_PHP_MOD=	yes
.else
WANT_PHP_CGI=	yes
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

post-patch:
	${MV} ${WRKSRC}/conf-default.php ${WRKSRC}/conf.php.sample

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} '${WWW_IGNORE}')
.for ent in ${WRITEABLE}
	@${CHMOD} u+w ${STAGEDIR}${WWWDIR}/${ent}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${ex} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
.if defined(MAINTAINER_MODE)
	@${MAKE} -C ${.CURDIR} rm-install
.endif

.include <bsd.port.mk>
