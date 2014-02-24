# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	metar
PORTVERSION=	0.19
PORTREVISION=	2
CATEGORIES=	astro python geography
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${REALPORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module that provides access to NOAA METAR weather reports

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options

PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	2
USES=		shebangfix

PLIST_FILES=	bin/${REALPORTNAME} \
		man/man1/${REALPORTNAME}.1.gz
PORTDOCS=	COPYING README THANKS librarydoc.txt

REALPORTNAME=	pymetar

SHEBANG_FILES=	bin/${REALPORTNAME}
python_CMD=	${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' \
		-e 's|"share/doc/pymetar-%s"%pymetar.__version__|"${DOCSDIR}"|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
