# Ports collection makefile for:  pear-HTML_Select
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Select
PORTVERSION=	1.0
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common \
		${PEARDIR}/I18N/Common.php:${PORTSDIR}/devel/pear-I18N

NO_BUILD=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/pear/HTML_Select

LPHP_LIB=	lib/php
PEARDIR=	${LOCALBASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}
MANIFEST=	Country.php UKCounty.php USState.php
EXAMPLES=	Country.php UKCounty.php USState.php

do-install:
	@${MKDIR} ${PEARDIR}/HTML/Select
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/Select/${FILE} ${PEARDIR}/HTML/Select
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML/Select
	@${CHMOD} a-x ${PEARDIR}/HTML/Select/*
#Note: Select.php is still needed for Kronolith 1.0
#	but should be removed with the next release.
	@${CP} -p ${FILESDIR}/Select.php ${PEARDIR}/HTML
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML/Select.php

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/Select/examples/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
