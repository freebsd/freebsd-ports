# New ports collection makefile for:	wxGlade
# Date created:				1 May 2003
# Whom:					Michal Pasternak <dotz@irc.pl>
#
# $FreeBSD$

PORTNAME=	wxGlade
PORTVERSION=	0.2.1
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
	(cd ${WRKSRC} && ${FIND} [^d]* \! -name "*.txt" \! -name ".cvsignore" -type f | cpio -pdum ${PYTHON_SITELIBDIR}/${PORTNAME})
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PYTHON_SITELIBDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${FIND} . -type f | cpio -pdum ${DOCSDIR})
	(cd ${WRKSRC} && ${FIND} . -maxdepth 1 -name "*.txt" | cpio -pdum ${DOCSDIR})
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
