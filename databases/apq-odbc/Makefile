# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apq-odbc
PORTVERSION=	${APQ_VERSION}
PORTREVISION=	${DRV_ODBC_PR}
CATEGORIES=	databases
MASTER_SITES=	LOCAL/marino

MAINTAINER=	marino@FreeBSD.org
COMMENT=	APQ Ada95 ODBC database driver

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gprbuild:${PORTSDIR}/devel/gprbuild \
		${LOCALBASE}/lib/gnat/apq.gpr:${PORTSDIR}/databases/apq
RUN_DEPENDS=	${LOCALBASE}/lib/gnat/apq.gpr:${PORTSDIR}/databases/apq
LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC

USES=		ada tar:bzip2
HAS_CONFIGURE=	yes
WRKPATH=	${WRKDIR}/build
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--disable-relocatable \
		--work-path=${WRKPATH} \
		--processors=${MAKE_JOBS_NUMBER}

.include "${.CURDIR}/../apq/Makefile.version"

post-extract:
	${RM} ${WRKSRC}/src/test.adb
	${ECHO} ${APQ_VERSION} > ${WRKSRC}/version

post-patch:
	${RM} ${WRKSRC}/src/*.orig
	${REINPLACE_CMD} -e 's|"-march=x86-64",||g' -e '/for Object_Dir/d' \
		${WRKSRC}/gnat/apq-odbc.gpr.in

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/apq-odbc/static \
		${STAGEDIR}${PREFIX}/include/apq-odbc
	${INSTALL_DATA} ${WRKPATH}/src/apq-odbc/* \
		${STAGEDIR}${PREFIX}/include/apq-odbc
	${INSTALL_DATA} ${WRKPATH}/lib/apq-odbc/static/*.a* \
		${STAGEDIR}${PREFIX}/lib/apq-odbc/static
	${INSTALL_DATA} ${WRKPATH}/lib/gnat/apq-odbc.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
