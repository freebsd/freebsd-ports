# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	pyching
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/pyChing/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Consult a I Ching, an ancient Chinese book of wisdom

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

NO_WRKSUBDIR=	yes
USES=		python

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC}; ${SED} 's|/usr/share/|${PYTHON_SITELIBDIR}/|g' \
		< ${PORTNAME}.sh > ${PORTNAME}

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.py *.pyc *.pyo *.xbm  \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME})
	(cd ${WRKSRC} && ${INSTALL_DATA} COPYING CREDITS \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME})
	@${CHMOD} ${BINMODE} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.py
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} BUGS CHANGES NEWS README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
