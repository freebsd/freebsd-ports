# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	metar
PORTVERSION=	0.19
PORTREVISION=	2
CATEGORIES=	astro python geography
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module that provides access to NOAA METAR weather reports

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options

PYTHON_FEATURES=autoplist,distutils
USES=		python:2 shebangfix

PORTDOCS=	COPYING README THANKS librarydoc.txt

SHEBANG_FILES=	bin/py${PORTNAME}
python_CMD=	${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' \
		-e 's|"share/doc/pymetar-%s"%pymetar.__version__|"${DOCSDIR}"|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
