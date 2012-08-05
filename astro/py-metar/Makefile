# New ports collection makefile for:	py-metar
# Date created:		26 July 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	metar
PORTVERSION=	0.17
CATEGORIES=	astro python geography
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${REALPORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module that provides access to NOAA METAR weather reports

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

PYDISTUTILS_PKGNAME=	${REALPORTNAME}
USE_PYDISTUTILS=	yes
USE_PYTHON=	-2.7

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PLIST_FILES=	bin/${REALPORTNAME} \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.py \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.pyc \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.pyo
PORTDOCS=	COPYING README THANKS librarydoc.txt

REALPORTNAME=	pymetar

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -E '1 s|/usr/bin/(env *)?python|${PYTHON_CMD}|' \
		${WRKSRC}/setup.py ${WRKSRC}/bin/${REALPORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} \
		-e 's|"share/doc/pymetar-%s/"%pymetar.__version__|"${DOCSDIR}"|' \
		${WRKSRC}/setup.py
.else
	@${REINPLACE_CMD} \
		-e 's|"share/doc/pymetar-%s/"%pymetar.__version__|""|' \
		-e "s|\['README.*'\]|[]|" ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
