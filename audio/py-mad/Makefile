# New ports collection makefile for:	py-mad
# Date created:		8 October 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	mad
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymad-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module that provides the MPEG Audio Decoder interface

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad

PROJECTHOST=	pymad
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pymad

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/madmodule.so

post-patch:
	@${REINPLACE_CMD} 's/^\(.*compile.*\)\?\(.*\)\?\(.*\)$$/\1\2\3/' \
		${WRKSRC}/setup.py

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} config_unix.py --prefix ${PYTHONBASE}

.include <bsd.port.mk>
