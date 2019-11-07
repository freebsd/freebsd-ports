# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	pythontidy
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.lacusveris.com/PythonTidy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PythonTidy-${PORTVERSION}.python
EXTRACT_SUFX=	#
DIST_SUBDIR=	python

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Cleans up, regularizes, and reformats the text of Python scripts

LICENSE=	GPLv2

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/pythontidy

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKDIR}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTFILES} \
		${STAGEDIR}${PREFIX}/bin/pythontidy

.include <bsd.port.mk>
