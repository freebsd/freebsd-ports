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

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/zpu/bin/zpu-elf-as:devel/zpu-binutils
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}/toolchain
USES=		gettext gmake makeinfo
MANDIRS=	${PREFIX}/zpu/man
INFO=		zpuc/cpp zpuc/cppinternals zpuc/dir zpuc/gcc zpuc/gccinstal \
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

do-build:
	cd ${WRKSRC} && ${SH} build.sh

.include <bsd.port.mk>
