# Created by: gahr@FreeBSD.org
# $FreeBSD$

PORTNAME=	critcl
PORTVERSION=	3.1.12
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Compiled Runtime in Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${LOCALBASE}/lib/Trf/pkgIndex.tcl:${PORTSDIR}/devel/tcl-trf

USES+=		tcl
USE_GITHUB=	yes
GH_ACCOUNT=	andreas-kupries

PLIST_SUB+=	VER=${PORTVERSION}
PORTDOCS=	*

NO_BUILD=	yes

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|dtplite|${LOCALBASE}/bin/dtplite|g' ${WRKSRC}/build.tcl
	${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' ${WRKSRC}/lib/critcl/Config

do-install:
	(cd ${WRKSRC} && ${TCLSH} build.tcl install ${STAGEDIR}${PREFIX}/lib)
	${INSTALL_MAN} ${WRKSRC}/embedded/man/files/critcl_*.n	\
		${STAGEDIR}${MANPREFIX}/man/mann/

test check regression-test: build
	(cd ${WRKSRC} && ${TCLSH} test/all.tcl)

.include <bsd.port.mk>
