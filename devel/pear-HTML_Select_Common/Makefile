# Ports collection makefile for:  pear-HTML_Select
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Select_Common
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Some small PEAR classes to handle common <select> lists

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common \
		${PEARDIR}/I18N/Common.php:${PORTSDIR}/devel/pear-I18N

NO_BUILD=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/pear/${PORTNAME}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_BASE=	${LOCALBASE}
.endif
PEAR=		${LOCALBASE}/bin/pear
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

MANIFEST=	Country.php FRDepartements.php UKCounty.php USState.php
EXAMPLES=	Country.php FRDepartements.php UKCounty.php USState.php

do-install:
	@${MKDIR} ${PEARDIR}/HTML/Select/Common
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/Select/Common/${FILE} ${PEARDIR}/HTML/Select/Common
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML/Select/Common
	@${CHMOD} a-x ${PEARDIR}/HTML/Select/Common/*
#Note: Select.php is still needed for Kronolith 1.0
#	but should be removed with the next release.
	@${CP} -p ${FILESDIR}/Select.php ${PEARDIR}/HTML
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML/Select.php
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/Select/Common/examples/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
# Register a new package
	@${PEAR} install -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
