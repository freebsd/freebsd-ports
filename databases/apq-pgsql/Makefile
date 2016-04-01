# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apq-pgsql
PORTVERSION=	${APQ_VERSION}
PORTREVISION=	${DRV_PGSQL_PR}
CATEGORIES=	databases
MASTER_SITES=	LOCAL/marino

MAINTAINER=	marino@FreeBSD.org
COMMENT=	APQ Ada95 PostgreSQL database driver

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		gprbuild:devel/gprbuild \
		${LOCALBASE}/lib/gnat/apq.gpr:databases/apq
RUN_DEPENDS=	${LOCALBASE}/lib/gnat/apq.gpr:databases/apq

USES=		ada tar:bzip2 pgsql
WANT_PGSQL=	lib
HAS_CONFIGURE=	yes
WRKPATH=	${WRKDIR}/build
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--disable-relocatable \
		--work-path=${WRKPATH} \
		--processors=${MAKE_JOBS_NUMBER}

.include "${.CURDIR}/../apq/Makefile.version"

post-patch:
	${RM} ${WRKSRC}/src/*.orig
	@${REINPLACE_CMD} -e '/for Object_Dir/d' \
		${WRKSRC}/src-in/apq-postgresql.gpr.in
	${REINPLACE_CMD} -e 's|processors=2|gprbuild_params="--autoconf=apq.cgpr"|' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-ws|-ws --autoconf=dummy.cgpr|' \
		${WRKSRC}/scripts/buildutil.sh

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/gnat \
		${STAGEDIR}${PREFIX}/lib/apq-postgresql/static \
		${STAGEDIR}${PREFIX}/include/apq-postgresql
	${INSTALL_DATA} ${WRKPATH}/include/apq-postgresql/* \
		${STAGEDIR}${PREFIX}/include/apq-postgresql
	${INSTALL_DATA} ${WRKPATH}/lib/apq-postgresql/static/*.a* \
		${STAGEDIR}${PREFIX}/lib/apq-postgresql/static
	${INSTALL_DATA} ${WRKPATH}/lib/gnat/apq-postgresql.gpr \
		${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
