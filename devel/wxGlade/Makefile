# New ports collection makefile for:	wxGlade
# Date created:				1 May 2003
# Whom:					Michal Pasternak <dotz@irc.pl>
#
# $FreeBSD$

PORTNAME=	wxGlade
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	devel x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxglade

MAINTAINER=	dotz@irc.pl
COMMENT=	GUI builder for wxPython/wxWindows written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/wx.py:${PORTSDIR}/x11-toolkits/py-wxPython

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${FIND} [^d]* \! -name ".cvsignore" -type f | \
		${CPIO} -R ${SHAREOWN}:${SHAREGRP} -pdum \
		${PYTHON_SITELIBDIR}/${PORTNAME})
	${CHMOD} -R 644 ${PYTHON_SITELIBDIR}/${PORTNAME}
	${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} -type d | ${XARGS} ${CHMOD} 755
	${CHMOD} 755 ${PYTHON_SITELIBDIR}/${PORTNAME}/wxglade.py \
		${PYTHON_SITELIBDIR}/${PORTNAME}/xrc2wxg.py
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${FIND} . -type f | \
		${CPIO} -R ${SHAREOWN}:${SHAREGRP} -pdum ${DOCSDIR})
	${CHMOD} -R 644 ${DOCSDIR}
	${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} 755
.endif

.include <bsd.port.mk>
