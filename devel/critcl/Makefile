# Created by: gahr@FreeBSD.org
# $FreeBSD$

PORTNAME=	critcl
PORTVERSION=	3.1.17
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Compiled Runtime in Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${LOCALBASE}/lib/Trf/pkgIndex.tcl:devel/tcl-trf	\
		${LOCALBASE}/lib/tcllib/cmdline/pkgIndex.tcl:devel/tcllib

BROKEN_aarch64=		fails to package: pkg-static: Unable to access file lib/critcl_md5c0.12/freebsd-armv6/md5c.so:No such file or directory
BROKEN_armv6=		fails to package: pkg-static: Unable to access file lib/critcl_md5c0.12/freebsd-armv6/md5c.so:No such file or directory
BROKEN_armv7=		fails to package: pkg-static: Unable to access file lib/critcl_md5c0.12/freebsd-armv7/md5c.so:No such file or directory

USES+=		tcl:85+
USE_GITHUB=	yes
GH_ACCOUNT=	andreas-kupries

TEST_TARGET=	test

PLIST_SUB+=	VER=${PORTVERSION} \
		ARCH=${ARCH:S/i386/ix86/}
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

do-test:
	(cd ${WRKSRC} && ${TCLSH} build.tcl test)

.include <bsd.port.mk>
