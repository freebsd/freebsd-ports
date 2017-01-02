# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-styleguide
PORTVERSION=	66
CATEGORIES=	devel
MASTER_SITES=	http://google-styleguide.googlecode.com/svn/trunk/cpplint/
DISTFILES=	cpplint.py cpplint_unittest.py README
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to assist with Google style guide compliance

BROKEN=		Unfetchable (google code has gone away)

USES=		python
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cpplint.py
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${DISTDIR}/${DIST_SUBDIR} && ${CP} ${DISTFILES} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -Ee "s,#!.*,#!${PYTHON_CMD}," ${WRKSRC}/*.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cpplint.py ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
