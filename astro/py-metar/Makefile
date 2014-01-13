# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	metar
PORTVERSION=	0.19
PORTREVISION=	1
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

PYDISTUTILS_PKGNAME=	${REALPORTNAME}
USE_PYDISTUTILS=yes
USE_PYTHON=	2

PLIST_FILES=	bin/${REALPORTNAME} \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.py \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.pyc \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.pyo \
		man/man1/${REALPORTNAME}.1.gz
PORTDOCS=	COPYING README THANKS librarydoc.txt

REALPORTNAME=	pymetar

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E '1 s|/usr/bin/(env *)?python|${PYTHON_CMD}|' \
		${WRKSRC}/${PYSETUP} ${WRKSRC}/bin/${REALPORTNAME}
	@${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' ${WRKSRC}/${PYSETUP}
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} \
		-e 's|"share/doc/pymetar-%s"%pymetar.__version__|"${DOCSDIR}"|' \
		${WRKSRC}/${PYSETUP}
.else
	@${REINPLACE_CMD} \
		-e 's|"share/doc/pymetar-%s"%pymetar.__version__|""|' \
		-e "s|\['README.*'\]|[]|" ${WRKSRC}/${PYSETUP}
.endif

.include <bsd.port.mk>
