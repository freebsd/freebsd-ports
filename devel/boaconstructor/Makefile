# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	boaconstructor
PORTVERSION=	0.6.1
PORTREVISION=	8
CATEGORIES=	devel python
#MASTER_SITES=	SF/boa-constructor/Boa-Constructor/${PORTVERSION}-alpha
MASTER_SITES=	SF/boa-constructor/Boa-Constructor/${PORTVERSION}-beta
DISTNAME=	boa-constructor-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross platform RAD GUI Building IDE for wxPython

WRKSRC=		${WRKDIR}/boa-constructor-${PORTVERSION}

USES=		dos2unix gettext python:2.7 zip
USE_WX=		3.0+
WX_COMPS=	python
DATADIR=	${PREFIX}/share/Boa

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -x zoa ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -x zoa ${WRKSRC}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py ${WRKSRC}/ZopeLib/zoa/breakpoint.py
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/py_compile.py ${WRKSRC}/ZopeLib/zoa/breakpoint.py

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${TAR} cCf ${WRKSRC} - --exclude "*.orig" . | ${TAR} xUCf ${STAGEDIR}${DATADIR} -
	@printf "#!/bin/sh\n${PYTHON_CMD} ${DATADIR}/Boa.py\n" \
		> ${WRKDIR}/Boa.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/Boa.sh ${STAGEDIR}${PREFIX}/bin/Boa

.include <bsd.port.mk>
