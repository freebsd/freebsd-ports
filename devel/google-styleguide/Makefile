# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-styleguide
PORTVERSION=	66
CATEGORIES=	devel
MASTER_SITES=	http://google-styleguide.googlecode.com/svn/trunk/cpplint/
DISTFILES=	cpplint.py cpplint_unittest.py README
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A tool to assist with Google style guide compliance

USE_PYTHON?=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cpplint.py
PORTDOCS=	README

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -Ee "s,#!.*,#!${PYTHON_CMD}," ${WRKSRC}/*.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cpplint.py ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
