# New ports collection makefile for:	py-eyed3
# Date created:		22 August 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	eyed3
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://www.travisshirk.net/eyeD3/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	eyeD3-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python module for processing ID3 tags

LIB_DEPENDS=	id3:${PORTSDIR}/audio/id3lib
RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/optparse.py:${PORTSDIR}/devel/py-optik

USE_PYTHON=	yes
USE_PYTHON_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON="${PYTHON_CMD}"
MAKE_ENV=	SETUP_ARGS_BUILD="${PYDISTUTILS_BUILDARGS}" \
		SETUP_ARGS_INSTALL="${PYDISTUTILS_INSTALLARGS}"
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's,PYTHON="",,g' -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,\(setup.py build\),\1 $${SETUP_ARGS_BUILD},g' \
		-e 's,\(setup.py install\),\1 $${SETUP_ARGS_INSTALL} ,g' \
		-e 's,^DOC_DIR.*,DOC_DIR=${DOCSDIR},g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
