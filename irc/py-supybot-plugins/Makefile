# New ports collection makefile for:	supybot-plugins
# Date created:		2005-07-12
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	supybot-plugins
PORTVERSION=	20060723
PORTREVISION=	1
CATEGORIES=	irc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	supybot
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Supybot-plugins-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Official plugin pack for Supybot

RUN_DEPENDS=	supybot:${PORTSDIR}/irc/py-supybot

USE_PYTHON=	2.3+
USE_BZIP2=	yes

post-extract:
# Delete, because it now included in irc/py-supybot
.for data in BadWords Dunno Success _darcs
	@${RM} -rf ${WRKSRC}/${data}
.endfor

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} -c 'import compileall;compileall.compile_dir(".");' && ${PYTHON_CMD} -O -c 'import compileall;compileall.compile_dir(".");'

do-install:
	cd ${WRKSRC} && ${FIND} . | ${CPIO} -pdm -R ${BINOWN}:${BINGRP} ${PYTHONPREFIX_SITELIBDIR}/supybot/plugins

.include <bsd.port.mk>
