PORTNAME=	pycount
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://python.net/crew/gherman/playground/pycount/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.py
EXTRACT_SUFX=	#
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Initial effort to Python code metrics

USES=		dos2unix python
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKDIR}/${DISTNAME}
	@${FIND} ${WRKSRC} -name \*.bak -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
