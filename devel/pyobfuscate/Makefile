# ex:ts=8
# Ports collection makefile for:	pyobfuscate
# Date created:			May 4, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyobfuscate
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.lysator.liu.se/~astrand/projects/pyobfuscate/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python source code obfuscator

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	bin/pyobfuscate

post-patch:
	@${REINPLACE_CMD} -e "s,/usr,${PREFIX}," ${WRKSRC}/setup.py

.include <bsd.port.mk>
