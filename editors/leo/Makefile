# New ports collection makefile for:	leo
# Date created:			2002/11/17
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	leo
PORTVERSION=	4.2.1
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-final
DIST_SUBDIR=	leo

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Advanced outline editor for programmers

RUN_DEPENDS=	${TKINTER}:${PORTSDIR}/x11-toolkits/py-tkinter

USE_ZIP=	yes
USE_PYTHON=	yes
TKINTER=	${PYTHON_SITELIBDIR}/_tkinter.so

LEO_DIR=	${PYTHONPREFIX_SITELIBDIR}/leo
DOCS=		doc/LICENSE.TXT doc/README.TXT

do-build:
	${SED} -e 's|@PKGDATADIR@|${LEO_DIR}/src|' ${FILESDIR}/leo.in \
		> ${WRKDIR}/leo

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/leo ${PREFIX}/bin/leo
	@${MKDIR} ${LEO_DIR}
.for dir in Icons config plugins src
	@${MKDIR} ${LEO_DIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${LEO_DIR}/${dir}
.endfor
	@${RM} -f ${LEO_DIR}/Icons/*.bmp ${LEO_DIR}/Icons/*.ico
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@${MKDIR} ${LEO_DIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/LeoDocs.leo ${LEO_DIR}/doc
.endif

.include <bsd.port.mk>
