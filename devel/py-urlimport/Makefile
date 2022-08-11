PORTNAME=	urlimport
PORTVERSION=	0.42b
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.py

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python script for importing modules/packages over the net

NO_WRKSUBDIR=	yes

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${PORTNAME}.py
	${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${FILESDIR}/setup.py \
		> ${WRKSRC}/setup.py

.include <bsd.port.mk>
