# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	pyching
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/pyChing/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Consult a I Ching, an ancient Chinese book of wisdom

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

NO_WRKSUBDIR=	yes
USE_PYTHON=	yes

MAN1=		${PORTNAME}.1

NO_STAGE=	yes
post-patch:
	@cd ${WRKSRC}; ${SED} 's|/usr/share/|${PYTHON_SITELIBDIR}/|g' \
		< ${PORTNAME}.sh > ${PORTNAME}

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
.for ext in py pyc pyo xbm
	${INSTALL_DATA} ${WRKSRC}/*.${ext} ${PYTHON_SITELIBDIR}/${PORTNAME}
.endfor
.for file in COPYING CREDITS
	${INSTALL_DATA} ${WRKSRC}/${file} ${PYTHON_SITELIBDIR}/${PORTNAME}
.endfor
	@${CHMOD} ${BINMODE} ${PYTHON_SITELIBDIR}/${PORTNAME}/${PORTNAME}.py
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CHANGES NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
