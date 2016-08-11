# Created by: ijliao
# $FreeBSD$

PORTNAME=	pyobfuscate
PORTVERSION=	0.3.20131129
CATEGORIES=	devel

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python source code obfuscator

USE_GITHUB=	yes
GH_ACCOUNT=	astrand
GH_TAGNAME=	47cc6e49bf65649c9fc53fbf4ae7d6e23b565550

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e "s,'/usr/bin','${PREFIX}/bin'," ${WRKSRC}/setup.py

.include <bsd.port.mk>
