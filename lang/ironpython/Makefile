# New ports collection makefile for:    ironpython
# Date created:		29 July 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	ironpython
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://www.ironpython.com/
DISTNAME=	IronPython-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	New Python implementation targeting the .NET

RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_ZIP=	yes
NO_BUILD=	yes
EXTRACT_BEFORE_ARGS=	-q -a

post-extract:
	${ECHO} '#!${SH}' > ${WRKDIR}/ironpython
	${ECHO} '${LOCALBASE}/bin/mono ${PREFIX}/lib/ironpython/IronPythonConsole.exe $$*' >> ${WRKDIR}/ironpython

do-install:
	${MKDIR} ${PREFIX}/lib/ironpython
	cd ${WRKSRC}/bin; for f in *.exe *.dll; do \
		${INSTALL_DATA} $$f ${PREFIX}/lib/ironpython; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/ironpython ${PREFIX}/bin/

.include <bsd.port.mk>
