# Created by: gahr@FreeBSD.org
# $FreeBSD$

PORTNAME=	critcl
PORTVERSION=	3.1.10
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Compiled Runtime in Tcl

OPTIONS_DEFINE=	DOCS

USES+=		tcl
USE_GITHUB=	yes
GH_ACCOUNT=	andreas-kupries
GH_COMMIT=	ea3f253

PLIST_SUB+=	VER=${PORTVERSION}
PORTDOCS=	*

NO_BUILD=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	dtplite:${PORTSDIR}/devel/tcllib
.endif

post-patch:
	${REINPLACE_CMD} -e 's|dtplite|${LOCALBASE}/bin/dtplite|g' ${WRKSRC}/build.tcl
	${REINPLACE_CMD} -e 's|4603|4746|g' ${WRKSRC}/test/cproc.test
	${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' ${WRKSRC}/lib/critcl/Config

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${TCLSH} build.tcl doc
	cd ${WRKSRC}/embedded/www && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif
	cd ${WRKSRC} && ${TCLSH} build.tcl install ${STAGEDIR}${PREFIX}/lib

regression-test:
	cd ${WRKSRC} && ${TCLSH} test/all.tcl

.include <bsd.port.mk>
