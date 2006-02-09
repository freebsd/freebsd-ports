# New ports collection makefile for:	py-flac
# Date created:				5 January 2006
# Whom:					Byung-Hee HWANG <bh@izb.knu.ac.kr>
#
# $FreeBSD$

PORTNAME=	flac
PORTVERSION=	0.0.4
CATEGORIES=	audio python
MASTER_SITES=	http://www.sacredchao.net/~piman/software/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyflac-${PORTVERSION}

MAINTAINER=	changbom.yoon@gmail.com
COMMENT=	Python module that provides the Free Lossless Audio Codec interface

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.X
.endif

do-build:
	@cd ${WRKSRC} && ${GMAKE} build

.include <bsd.port.post.mk>
