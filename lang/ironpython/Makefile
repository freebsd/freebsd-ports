# New ports collection makefile for:    ironpython
# Date created:		29 July 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	ironpython
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	lang python
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/
DISTNAME=	IronPython-1.0.1-Src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	New Python implementation targeting the .NET

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

WRKSRC=	${WRKDIR}/IronPython-${PORTVERSION}
USE_ZIP=	yes
USE_GMAKE=	yes

post-extract:
	@(${ECHO} '#!${SH}' > ${WRKDIR}/ironpython)
	@(${ECHO} '${LOCALBASE}/bin/mono ${PREFIX}/lib/ironpython/ipy.exe -X:ColorfulConsole $$*' \
		>> ${WRKDIR}/ironpython)

pre-build:
	@${MKDIR} ${WRKSRC}/Src/IronPythonTest/bin

do-build:
	cd ${WRKSRC}/Src && ${GMAKE}

do-install:
	@${MKDIR} ${PREFIX}/lib/ironpython
	cd ${WRKSRC}; for f in *.exe *.dll; do \
		${INSTALL_DATA} $$f ${PREFIX}/lib/ironpython; \
	done
	@${INSTALL_SCRIPT} ${WRKDIR}/ironpython ${PREFIX}/bin/

.include <bsd.port.mk>
