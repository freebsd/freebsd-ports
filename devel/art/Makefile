# New ports collection makefile for: art
# Date created: 2011-11-05
# Whom: Vladimir Gorelov <virtual.lark@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	art
PORTVERSION=	0.9.01
CATEGORIES=	devel
MASTER_SITES=	http://skylark.tsu.ru/art/0.9/download/src/ \
		SF/art-project/src/

MAINTAINER=	virtual.lark@gmail.com
COMMENT=	A resource tracing, debugging, and profiling tool

LICENSE=	GPLv3

LIB_DEPENDS=	xml++-2.6:${PORTSDIR}/textproc/libxml++26

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/artlibgen/src/artlibgen ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/artrepgen/artrepgen ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in posix-gcc-mt-file-lint.xml posix-gcc-mt-netw-lint.xml \
 posix-gcc-mt-file-special.xml
	@${INSTALL_DATA} ${WRKSRC}/artlibgen/templates/${docs} ${DOCSDIR}
.endfor
.endif

.if defined(MAINTAINER_MODE)
full-regression-test: build
	cd ${WRKSRC}; ${GMAKE} test
.endif

.include <bsd.port.mk>
