# Created by: gahr@FreeBSD.org
# $FreeBSD$

PORTNAME=	critcl
PORTVERSION=	3.1.18.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Compiled Runtime in Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${LOCALBASE}/lib/Trf/pkgIndex.tcl:devel/tcl-trf	\
		${LOCALBASE}/lib/tcllib/cmdline/pkgIndex.tcl:devel/tcllib

USES+=		tcl
USE_GITHUB=	yes
GH_ACCOUNT=	andreas-kupries

TEST_TARGET=	test

PLIST_SUB+=	VER=${PORTVERSION:R} \
		ARCH=${ARCH:C/arm.*/arm/:S/i386/ix86/:S/aarch64/arm/:S/mips64/mips/:S/powerpc64/powerpc/}
PORTDOCS=	*

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|dtplite|${LOCALBASE}/bin/dtplite|g' ${WRKSRC}/build.tcl
	${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g' ${WRKSRC}/lib/critcl/Config

do-install:
	(cd ${WRKSRC} && ${TCLSH} build.tcl install ${STAGEDIR}${PREFIX}/lib)
	${INSTALL_MAN} ${WRKSRC}/embedded/man/files/critcl_*.n	\
		${STAGEDIR}${MANPREFIX}/man/mann/

do-test:
	(cd ${WRKSRC} && ${TCLSH} build.tcl test)

.include <bsd.port.mk>
