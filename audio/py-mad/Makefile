# New ports collection makefile for:	py-mad
# Date created:		8 October 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	mad
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://spacepants.org/src/pymad/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymad-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module that provides the MPEG Audio Decoder interface

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/madmodule.so
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	pymad

post-patch:
	@${REINPLACE_CMD} 's/^\(.*compile.*\)\?\(.*\)\?\(.*\)$$/\1\2\3/' \
		${WRKSRC}/setup.py

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py --prefix ${PREFIX}

.include <bsd.port.mk>
