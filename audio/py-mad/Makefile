# New ports collection makefile for:	py-mad
# Date created:		8 October 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	mad
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://spacepants.org/src/pymad/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymad-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python module that provides the MPEG Audio Decoder interface

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's/^\(.*compile.*\)\?\(.*\)\?\(.*\)$$/\1\2\3/' \
		${WRKSRC}/setup.py
.if ${OSVERSION} < 500028
	@${REINPLACE_CMD} 's/#include <stdint.h>//g' \
		${WRKSRC}/src/pymadfile.c
.endif

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} config_unix.py --prefix ${PREFIX}

.include <bsd.port.post.mk>
