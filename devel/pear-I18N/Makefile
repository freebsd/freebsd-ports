# Ports collection makefile for:  pear-I18N
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	I18N
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR internationalization package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php.dist:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

.include <bsd.port.pre.mk>

EXAMPLESDIR=	${PREFIX}/share/examples/pear

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_BASE=	${LOCALBASE}
.endif
PEAR=		${LOCALBASE}/bin/pear
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}
MANIFEST=	Common.php Country.php Language.php Negotiator.php
EXAMPLES=	I18N_Message.php I18N_Message_Translate.php \
		I18N_Message_Translate.tpl I18N_Negotiator.php

do-install:
	@${MKDIR} ${PEARDIR}/I18N
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/${FILE} ${PEARDIR}/I18N
.endfor
	@${CHMOD} a-x ${PEARDIR}/I18N/*
	@${CP} -Rp ${WRKSRC}/Messages ${PEARDIR}/I18N
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/I18N
	@${CHMOD} a-x ${PEARDIR}/I18N/Messages/*
.if !defined(NOPORTDOCS)
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
# Register a new package
	@${PEAR} install -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
