# Ports collection makefile for:  pear-I18N
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	I18N
PORTVERSION=	0.8.6
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR internationalization package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Common.php Country.php Currency.php DateTime.php Format.php	\
		Language.php Negotiator.php Number.php
SUBDIRS=	Common Messages
EXAMPLES=	I18N_Currency.php I18N_DateTime.php I18N_Message.php		\
		I18N_Message_Translate.php I18N_Message_Translate.tpl		\
		I18N_Negotiator.php I18N_Number.php

do-install:
	@${MKDIR} ${PEARDIR}/I18N
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/${FILE} ${PEARDIR}/I18N
.endfor
.for FILE in ${SUBDIRS}
	@${CP} -Rp ${WRKSRC}/${FILE} ${PEARDIR}/I18N
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/I18N
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/docs/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
