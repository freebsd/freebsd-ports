# $FreeBSD$

PORTNAME=	zpu-gcc
PORTVERSION=	1.0
CATEGORIES=	devel
#MASTER_SITES=	http://people.freebsd.org/~db/
MASTER_SITES=	http://opensource.zylin.com/zpudownload.html/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	zpu-toolchain-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	ZPU gcc compiler

BUILD_DEPENDS=	${LOCALBASE}/zpu/bin/zpu-elf-as:${PORTSDIR}/devel/zpu-binutils

WRKSRC=		${WRKDIR}/${DISTNAME}/toolchain
USE_GMAKE=	yes
USES=		gettext
MANPREFIX=	${PREFIX}/zpu
MAN1=		zpu-elf-cpp.1 zpu-elf-gcc.1 zpu-elf-gcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		zpuc/cpp zpuc/cppinternals zpuc/gcc zpuc/gccinstall zpuc/gccint

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/%%CC%%/${CC}/' ${WRKSRC}/build.sh
	${CP}	${FILESDIR}/install.sh ${WRKSRC}
	@${REINPLACE_CMD} -e 's/%%GMAKE%%/${GMAKE}/' ${WRKSRC}/build.sh \
		${WRKSRC}/install.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/build.sh

do-install:
	cd ${WRKSRC} && ${SH} install.sh

do-build:
	cd ${WRKSRC} && ${SH} build.sh

.include <bsd.port.mk>
