# Ports collection makefile for:  pear-Config
# Date created:			  02 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	Config
PORTVERSION=	1.8
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Config package provides methods for configuration manipulation

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Apache.php IniCommented.php PHPArray.php GenericConf.php IniFile.php XML.php

do-install:
	@${CP} -p ${WRKSRC}/Config.php ${PEARDIR}
	@${MKDIR} ${PEARDIR}/Config/Container
	@${CP} -p ${WRKSRC}/Config/Container.php ${PEARDIR}/Config
.for FILE in ${MANIFEST}
	@${CP} -p ${WRKSRC}/Config/Container/${FILE} ${PEARDIR}/Config/Container
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Config.php
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Config
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/Apache.php ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/IniCommented.php ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/IniFromScratch.php ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
