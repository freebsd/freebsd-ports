# New ports collection makefile for: cut
# Date created:			December 5 2004
# Whom:       		Sergei Gnezdov <sergeiga@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	cut
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	http://www.falvotech.com/content/cut/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unit Testing Framework for C, C++ and Objective-C

USE_PYTHON_RUN=	yes
ALL_TARGET=	build

post-patch:
.for FILE in common.py cutgen.py options.py parser.py
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PREFIX}/bin/python|' \
		${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/bin/cutgen ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/bin/cutgen.py ${PREFIX}/bin
.for FILE in common.py lexer.py options.py parser.py
	${INSTALL_SCRIPT} ${WRKSRC}/build/bin/${FILE} ${PREFIX}/bin/cutgen_${FILE}
.endfor

.include <bsd.port.mk>
