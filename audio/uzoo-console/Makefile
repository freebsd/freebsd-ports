# New ports collection makefile for:	uzoo-console
# Date created:				31 Jan 2002
# Whom:				Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	uzoo-console
PORTVERSION=	1.1.3
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	soriuzoo

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${INSTALL_SCRIPT} ${WRKSRC}/uzoo.py ${PREFIX}/bin
.for f in uzoolib.py uzoolib.pyc uzoolib.pyo
	${INSTALL_DATA} ${WRKSRC}/$f ${PYTHON_SITELIBDIR}
.endfor

.include <bsd.port.mk>
