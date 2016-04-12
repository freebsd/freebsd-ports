# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apq-mysql
PORTVERSION=	${APQ_VERSION}
PORTREVISION=	${DRV_MYSQL_PR}
CATEGORIES=	databases
MASTER_SITES=	LOCAL/marino

MAINTAINER=	marino@FreeBSD.org
COMMENT=	APQ Ada95 MySQL database driver

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		gprbuild:devel/gprbuild \
		${LOCALBASE}/lib/gnat/apq.gpr:databases/apq
RUN_DEPENDS=	${LOCALBASE}/lib/gnat/apq.gpr:databases/apq

USES=		ada tar:bzip2
USE_MYSQL=	yes
HAS_CONFIGURE=	yes
WRKPATH=	${WRKDIR}/build
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--disable-relocatable \
		--work-path=${WRKPATH} \
		--processors=${MAKE_JOBS_NUMBER}

.include "${.CURDIR}/../apq/Makefile.version"

post-patch:
	@${REINPLACE_CMD} -e '/for Object_Dir/d' \
		${WRKSRC}/src-in/apq-mysql.gpr.in
	${REINPLACE_CMD} -e 's|processors=2|gprbuild_params="--autoconf=apq.cgpr"|' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-ws|-ws --autoconf=dummy.cgpr|' \
		${WRKSRC}/scripts/buildutil.sh

post-configure:
	# The header generated with MySQL 5.6 comes with two instances of
	# double underscore variables, which is illegal in Ada
	${REINPLACE_CMD} -e 's|__|_|' \
		${WRKDIR}/build/include/apq-mysql/apq-mysql.ads

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/apq-mysql/static \
		${STAGEDIR}${PREFIX}/include/apq-mysql
	${INSTALL_DATA} ${WRKPATH}/include/apq-mysql/* \
		${STAGEDIR}${PREFIX}/include/apq-mysql
	${INSTALL_DATA} ${WRKPATH}/lib/apq-mysql/static/*.a* \
		${STAGEDIR}${PREFIX}/lib/apq-mysql/static
	${INSTALL_DATA} ${WRKPATH}/lib/gnat/apq-mysql.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
