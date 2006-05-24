# New ports collection makefile for:	py-mutagen
# Date created:			15 May 2006
# Whom:				Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$

PORTNAME=	mutagen
PORTVERSION=	1.2
CATEGORIES=	audio python
MASTER_SITES=	http://www.sacredchao.net/~piman/software/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	changbom.yoon@gmail.com
COMMENT=	A Python-based audio metadata tag reader and writer

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS=	VORBIS	"Support to tag Vorbis Files"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
SUB_LIST+=	VORBIS=
.else
SUB_LIST+=	VORBIS="@comment "
.endif

.include <bsd.port.post.mk>
