# New ports collection makefile for:	py-metar
# Date created:		26 July 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	metar
PORTVERSION=	0.16
CATEGORIES=	astro python geography
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/ \
		http://sunpoet.net/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${REALPORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Python module that provides access to NOAA's METAR weather reports

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PYDISTUTILS_PKGNAME=	${REALPORTNAME}
USE_PYDISTUTILS=	yes
USE_PYTHON=	-2.6

PLIST_FILES=	bin/${REALPORTNAME} \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.py \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.pyc \
		%%PYTHON_SITELIBDIR%%/${REALPORTNAME}.pyo
PORTDOCS=	COPYING README THANKS librarydoc.txt

REALPORTNAME=	pymetar

post-patch:
	@${REINPLACE_CMD} -E '1 s|/usr/bin/(env *)?python|${PYTHON_CMD}|' \
		${WRKSRC}/setup.py ${WRKSRC}/bin/${REALPORTNAME}
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} \
		-e 's|"share/doc/pymetar-%s/"%pymetar.__version__|"${DOCSDIR}"|' \
		${WRKSRC}/setup.py
.else
	@${REINPLACE_CMD} \
		-e 's|"share/doc/pymetar-%s/"%pymetar.__version__|""|' \
		-e "s|\['README.*'\]|[]|" ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
