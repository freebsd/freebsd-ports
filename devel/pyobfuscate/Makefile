# Created by: ijliao
# $FreeBSD$

PORTNAME=	pyobfuscate
PORTVERSION=	0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~astrand/projects/pyobfuscate/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python source code obfuscator

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	bin/pyobfuscate

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,'/usr/bin','${PREFIX}/bin'," ${WRKSRC}/setup.py

.include <bsd.port.mk>
