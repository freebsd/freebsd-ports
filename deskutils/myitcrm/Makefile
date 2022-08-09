PORTNAME=	myitcrm
PORTVERSION=	0.2.9.3
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	SF/myitcrm/
DISTNAME=	MyITCRM1-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CRM project designed for Computer Servicing and Repairs

LICENSE=	GPLv3

DEPRECATED=	Abandoned project as last update was on 2012-01-15
EXPIRATION_DATE=	2022-09-30

USES=		dos2unix zip
USE_PHP=	mysqli session xml

PATCH_STRIP=	-p1
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/MyITCRM-${PORTVERSION}

PLIST_SUB=	WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"
PORTDOCS=	README.textile changelog.txt
PORTEXAMPLES=	htaccess.txt

OPTIONS_DEFINE=		APACHE DOCS EXAMPLES LIGHTTPD NGINX PHPMOD
OPTIONS_DEFAULT=	APACHE

NGINX_DESC=	Use Nginx
PHPMOD_DESC=	Use PHP module for Apache

APACHE_USES=		apache:run,2.2+
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
NGINX_RUN_DEPENDS=	nginx:www/nginx
PHPMOD_USES=		php:mod
PHPMOD_USES_OFF=	php:cgi

WRITEABLE=	conf.php.sample log/access.log cache

.include <bsd.port.options.mk>

# Set files to ignore.
.for file in ${PORTEXAMPLES} ${PORTDOCS} LICENSE.txt
WWW_IGNORE+=	-not -name ${file}
.endfor

.if defined(MAINTAINER_MODE)
trace-distfile: distclean
	@cd ${.CURDIR} && make FETCH_ARGS=-vFpr makesum

rm-install:
	${SU_CMD} '${RM} -r ${WWWDIR}/install'

.endif

post-patch:
	${MV} ${WRKSRC}/conf-default.php ${WRKSRC}/conf.php.sample

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} '${WWW_IGNORE}')
.for ent in ${WRITEABLE}
	@${CHMOD} u+w ${STAGEDIR}${WWWDIR}/${ent}
.endfor
.if defined(MAINTAINER_MODE)
	@${MAKE} -C ${.CURDIR} rm-install
.endif

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for ex in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${ex} ${STAGEDIR}${EXAMPLESDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
