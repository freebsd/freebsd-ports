# New ports collection makefile for:	wxGlade
# Date created:				1 May 2003
# Whom:					Michal Pasternak <dotz@irc.pl>
#
# $FreeBSD$

PORTNAME=	wxGlade
PORTVERSION=	0.3.5.1
PORTREVISION=	1
CATEGORIES=	devel x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxglade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI builder for wxPython/wxWindows written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/wx.py:${PORTSDIR}/x11-toolkits/py-wxPython24

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${FIND} [^d]* \! -name .cvsignore -type f | \
		${CPIO} -R ${SHAREOWN}:${SHAREGRP} -pdum \
		${PYTHON_SITELIBDIR}/${PORTNAME})
	@${CHMOD} -R a+rX ${PYTHON_SITELIBDIR}/wxGlade
	@${ECHO_CMD} "#!/bin/sh" > ${LOCALBASE}/bin/wxglade
	@${ECHO_CMD} "exec python ${PYTHON_SITELIBDIR}/wxGlade/wxglade.py $$@" \
		>> ${LOCALBASE}/bin/wxglade
	@${CHMOD} 755 ${LOCALBASE}/bin/wxglade
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${FIND} . \! -name .cvsignore -type f | \
		${CPIO} -R ${SHAREOWN}:${SHAREGRP} -pdum ${DOCSDIR})
	@${CHMOD} -R 644 ${DOCSDIR}
	@${CHMOD} -R a+X ${DOCSDIR}
.endif

.include <bsd.port.mk>
