# Created by: Khairil Yusof <kaeru@inigo-tech.com>
# $FreeBSD$

PORTNAME=	pytz
PORTVERSION=	2013b
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	World Timezone Definitions for Python

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|=True|=False|' ${WRKSRC}/setup.py

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
