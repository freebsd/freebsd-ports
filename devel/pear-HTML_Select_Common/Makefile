# Ports collection makefile for:  pear-HTML_Select
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Select_Common
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Some small PEAR classes to handle common <select> lists

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common	\
		${PEARDIR}/I18N/Common.php:${PORTSDIR}/devel/pear-I18N
RUN_DEPENDS=	${BUILD_DEPENDS}

EXAMPLESDIR=	${PEARDIR}/HTML/Select/Common/examples

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Country.php FRDepartements.php UKCounty.php USState.php
EXAMPLES=	Country.php FRDepartements.php UKCounty.php USState.php

do-install:
	@${MKDIR} ${PEARDIR}/HTML/Select/Common
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/Select/Common/${FILE} ${PEARDIR}/HTML/Select/Common
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/HTML/Select/Common
	@${CHMOD} a-x ${PEARDIR}/HTML/Select/Common/*
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/Select/Common/examples/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.post.mk>
