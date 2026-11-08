PORTNAME=	laminar
DISTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	GH \
		https://cdnjs.cloudflare.com/ajax/libs/vue/2.6.12/:vue \
		https://cdnjs.cloudflare.com/ajax/libs/Chart.js/3.9.1/:chart \
		https://raw.githubusercontent.com/drudru/ansi_up/v5.2.1/:ansi
DISTFILES=	ansi_up.js:ansi \
		vue.min.js:vue \
		chart.min.js:chart
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-${DISTVERSION}-${GH_TAGNAME}_GH0${EXTRACT_SUFX}

PATCH_SITES=	https://github.com/ohwgiles/laminar/commit/
PATCHFILES=	d25b7a46bbbc1e1f84a0fe35d352f307ea5ccc16.patch:-p1 \
		e62148b5f59c618970fda2c699fae3a9187e324c.patch:-p1

MAINTAINER=	cingel.marian@gmail.com
COMMENT=	Lightweight CI service
WWW=		https://laminar.ohwg.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	"Requires to translate 'uname -m' to linker '-m' flag in CMakeLists.txt"

BUILD_DEPENDS=	${LOCALBASE}/include/boost/multi_index_container.hpp:devel/boost-libs \
		${LOCALBASE}/include/rapidjson/rapidjson.h:devel/rapidjson
LIB_DEPENDS=	libcapnp.so:devel/capnproto \
		libinotify.so:devel/libinotify

USES=		cmake pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	ohwgiles
GH_TAGNAME=	23abdd2712bc259aa2880a8533886bc8c5a1fc86

USE_RC_SUBR=	laminard

HOMEDIR=	/var/db/${PORTNAME}
LAMINARD=	laminard

CMAKE_ARGS=	-DBASH_COMPLETIONS_DIR=${PREFIX}/share/bash-completion/completions \
		-DLAMINAR_VERSION=${DISTVERSION} \
		-DZSH_COMPLETIONS_DIR=${PREFIX}/share/zsh/site-functions

SUB_FILES=	laminard.env

SUB_LIST=	HOMEDIR=${HOMEDIR} \
		LAMINARD=${LAMINARD} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}

PLIST_SUB=	GROUPS=${GROUPS} \
		HOMEDIR=${HOMEDIR} \
		LAMINARD=${LAMINARD} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ansi_up.js ${WRKDIR}/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/vue.min.js ${WRKDIR}/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/chart.min.js ${WRKDIR}/Chart.min.js

pre-configure:
	${MKDIR} ${CONFIGURE_WRKSRC}/js
	${CP} ${WRKDIR}/ansi_up.js ${CONFIGURE_WRKSRC}/js/
	${CP} ${WRKDIR}/Chart.min.js ${CONFIGURE_WRKSRC}/js/
	${CP} ${WRKDIR}/vue.min.js ${CONFIGURE_WRKSRC}/js/

post-install:
	${MKDIR} ${STAGEDIR}${HOMEDIR} \
		 ${STAGEDIR}${HOMEDIR}/cfg \
		 ${STAGEDIR}${HOMEDIR}/cfg/jobs \
		 ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/laminard.env ${STAGEDIR}${ETCDIR}/${LAMINARD}.env.sample
	${RM} -r ${STAGEDIR}/etc/laminar.conf

.include <bsd.port.mk>
