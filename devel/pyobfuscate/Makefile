# Created by: ijliao
# $FreeBSD$

PORTNAME=	pyobfuscate
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~astrand/projects/pyobfuscate/ \
		LOCAL/arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python source code obfuscator

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e "s,'/usr/bin','${PREFIX}/bin'," ${WRKSRC}/setup.py

.include <bsd.port.mk>
