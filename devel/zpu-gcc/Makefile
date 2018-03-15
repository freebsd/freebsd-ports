# $FreeBSD$

PORTNAME=	zpu-gcc
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://opensource.zylin.com/zpudownload.html/
MASTER_SITES=	LOCAL/db
DISTNAME=	zpu-toolchain-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	ZPU gcc compiler

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/zpu/bin/zpu-elf-as:devel/zpu-binutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN_powerpc64=	fails to compile: libgcc2.h: conflicting types for '__structdi3'

WRKSRC=		${WRKDIR}/${DISTNAME}/toolchain
USES=		gettext gmake makeinfo
MANDIRS=	${PREFIX}/zpu/man
INFO=		zpuc/cpp zpuc/cppinternals zpuc/gcc zpuc/gccinstall \
		    zpuc/gccint

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' ${WRKSRC}/build.sh
	${CP}	${FILESDIR}/install.sh ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%MAKE_CMD%%|${MAKE_CMD}|' ${WRKSRC}/build.sh \
		${WRKSRC}/install.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/build.sh
	@${REINPLACE_CMD} -e 's|%%DESTDIR%%|${STAGEDIR}|g' ${WRKSRC}/gcc/Makefile.in

do-install:
	cd ${WRKSRC} && ${SH} install.sh

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/zpu/lib/libiberty.a
	@${RMDIR} ${STAGEDIR}${PREFIX}/zpu/include

do-build:
	cd ${WRKSRC} && ${SETENV} CONFIG_SITE=${CONFIG_SITE} ${SH} build.sh

.include <bsd.port.mk>
