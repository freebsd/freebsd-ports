# Ports collection makefile for:  pear-I18N
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	I18N
PORTVERSION=	0.8
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/pear

LPHP_LIB=	lib/php
PEARDIR=	${LOCALBASE}/${LPHP_LIB}
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

post-install:
.if !defined(NOPORTDOCS)
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
