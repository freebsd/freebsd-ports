PORTNAME=	ktx
DISTVERSION=	1.46
CATEGORIES=	games

PATCH_SITES=	https://github.com/QW-Group/ktx/commit/
PATCHFILES=	18ce9990e07f08f433759d68f47115e93fa05067.patch:-p1 \
		c166537fafc128cdcbe6f1d126d8089461a812bb.patch:-p1 \
		1f324ab0dd99c55bf8a4c126be7d72ba1992c779.patch:-p1 \
		0b8bf7ac91f8b47c15f926d2c3214dd9d413e1a6.patch:-p1 \
		c43aafcdc31e66812bb9116c7eca4bc736b76376.patch:-p1 \
		c871f3d2064e1881c694a7357986479b8cb96333.patch:-p1

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Kombat Teams eXtreme is a popular QuakeWorld server modification
WWW=		https://github.com/QW-Group/ktx/

LICENSE=	GPLv2

RUN_DEPENDS=	mvdsv:games/mvdsv

USES=		cmake dos2unix
DOS2UNIX_FILES=	resources/example-configs/id1/maps/arena3.ent \
		resources/example-configs/ktx/ktx.cfg \
		resources/example-configs/ktx/mvdsv.cfg \
		resources/example-configs/ktx/problem.cfg \
		resources/example-configs/ktx/race/routes/ztricks2.route \
		resources/extralog/ktxlog_0.1.xsd
USE_GITHUB=	yes
GH_ACCOUNT=	QW-Group
USE_RC_SUBR=	${PORTNAME}
EXTRACT_AFTER_ARGS=	--exclude ${PKGNAME}/.git* \
			--exclude ${PKGNAME}/build_cmake.sh \
			--exclude ${PKGNAME}/resources/example-configs/id1/"copy PAK0 and PAK1 here" \
			--exclude ${PKGNAME}/tools/cross-cmake \
			--exclude ${PKGNAME}/tools/vs \
			--no-same-owner --no-same-permissions
QWDIR=		${PREFIX}/quake
SUB_LIST=	QWDIR=${QWDIR} QWUSER=${USERS}
USERS=		qw
GROUPS=		qw
PLIST_SUB=	QWGROUP=${GROUPS}
PORTDATA=	*

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.options.mk>

do-install:
	${REINPLACE_CMD} -e 's|^set k_defmap|// set k_defmap|' \
		${WRKSRC}/resources/example-configs/ktx/ktx.cfg
	${MKDIR} ${STAGEDIR}${DATADIR} \
		 ${STAGEDIR}${QWDIR}/ktx/demos \
		 ${STAGEDIR}${QWDIR}/qw
	cd ${WRKSRC}/resources && \
		${COPYTREE_SHARE} 'extralog logo' ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/resources/example-configs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${QWDIR}
	${MV} ${STAGEDIR}${QWDIR}/id1/maps ${STAGEDIR}${QWDIR}/qw
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/qwprogs.so \
		${STAGEDIR}${DATADIR}
	${LN} -s ${DATADIR}/qwprogs.so ${STAGEDIR}${QWDIR}/ktx/
	${LN} -s ${Q1DIR}/id1/pak0.pak ${STAGEDIR}${QWDIR}/id1/
	${LN} -s ${Q1DIR}/id1/pak1.pak ${STAGEDIR}${QWDIR}/id1/
	${LN} -s ${Q1DIR}/id1/maps     ${STAGEDIR}${QWDIR}/id1/

	(cd ${STAGEDIR}${QWDIR} && \
		for f in port1 port2 port3 portffa servers; do \
			${MV} $${f} $${f}.sample; done && \
	cd ktx && \
		for f in ktx.cfg listip.cfg matchless.cfg mvdfinish.qws \
			mvdsv.cfg port1.cfg port2.cfg port3.cfg problem.cfg \
			pwd.cfg server.cfg vip_ip.cfg; do \
			${MV} $${f} $${f}.sample; done)

.include <bsd.port.mk>
