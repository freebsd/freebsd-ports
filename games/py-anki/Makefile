# New ports collection makefile for:	py-anki
# Date created:		12 February 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anki
PORTVERSION=	0.4.3
CATEGORIES=	games
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Spaced-repetition memory training library

BUILD_DEPENDS=	py*-numpy>=0:${PORTSDIR}/math/py-numpy \
		py*-game>=0:${PORTSDIR}/devel/py-game \
		py*-matplotlib>=0.90.0:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		kakasi:${PORTSDIR}/japanese/kakasi

USE_GETTEXT=	yes
USE_PYDISTUTILS=easy_install
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/lib${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|0.4.2|${PORTVERSION}|g'\
		${WRKSRC}/anki/__init__.py

.include <bsd.port.mk>
