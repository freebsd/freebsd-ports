# Created by: Sergei Gnezdov <sergeiga@yahoo.com>
# $FreeBSD$

PORTNAME=	cut
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	http://www.falvotech.com/content/cut/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unit Testing Framework for C, C++, and Objective-C

BROKEN=		Does not fetch
USES=		python:run shebangfix
SHEBANG_FILES=	*.py
ALL_TARGET=	build

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/bin/cutgen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/bin/cutgen.py ${STAGEDIR}${PREFIX}/bin
.for FILE in common.py lexer.py options.py parser.py
	${INSTALL_SCRIPT} ${WRKSRC}/build/bin/${FILE} ${STAGEDIR}${PREFIX}/bin/cutgen_${FILE}
.endfor

.include <bsd.port.mk>
