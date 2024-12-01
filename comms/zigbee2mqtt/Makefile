PORTNAME=	zigbee2mqtt
DISTVERSION=	1.42.0
CATEGORIES=	comms
MASTER_SITES=	LOCAL/otis/:nodemodules
DISTFILES=	${DISTCACHEFILES_nodemodules}:nodemodules

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Use your Zigbee devices without the vendor's bridge or gateway
WWW=		https://github.com/Koenkk/zigbee2mqtt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	node${NODEJS_VERSION}>0:www/node${NODEJS_VERSION} \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
RUN_DEPENDS=	node${NODEJS_VERSION}>0:www/node${NODEJS_VERSION}

USES=		nodejs:20

USE_GITHUB=	yes
GH_ACCOUNT=	Koenkk
GH_PROJECT=	zigbee2mqtt
USE_RC_SUBR=	z2m

NO_BUILD=	yes

SUB_FILES=	configuration.yaml pkg-message z2m
SUB_LIST=	Z2M_DATADIR=${Z2M_DATADIR} \
		Z2M_GROUP=${Z2M_GROUP} \
		Z2M_HOME=${Z2M_HOME} \
		Z2M_LOGDIR=${Z2M_LOGDIR} \
		Z2M_USER=${Z2M_USER}

USERS=		${Z2M_USER}
GROUPS=		${Z2M_GROUP}

DISTCACHEFILES=			${DISTCACHEFILES_nodemodules}
DISTCACHEFILES_nodemodules=	zigbee2mqtt-nodemodules-${PKGVERSION}.tar.gz

# user, group and homedir
Z2M_GROUP?=	z2m
Z2M_USER?=	z2m
Z2M_HOME?=	${PREFIX}/z2m
Z2M_DATADIR?=	/var/db/z2m
Z2M_LOGDIR?=	/var/log/z2m

PLIST_SUB+=	Z2M_DATADIR=${Z2M_DATADIR} \
		Z2M_GROUP=${Z2M_GROUP} \
		Z2M_HOME=${Z2M_HOME} \
		Z2M_LOGDIR=${Z2M_LOGDIR} \
		Z2M_USER=${Z2M_USER}

post-extract:
	for f in ${DISTCACHEFILES}; do \
		${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/$${f} -C ${WRKSRC}; \
	done
	for f in .github .gitignore .dockerignore .prettierignore \
		.prettierrc .release-please-manifest.json CHANGELOG.md \
		CODE_OF_CONDUCT.md CONTRIBUTING.md README.md docker \
		update.sh \
		data; do \
		${RM} -rf ${WRKSRC}/$${f}; \
	done

do-install:
	${MKDIR} ${STAGEDIR}${Z2M_HOME}
	${MKDIR} ${STAGEDIR}${Z2M_DATADIR}
	${MKDIR} ${STAGEDIR}${Z2M_LOGDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${Z2M_HOME}
	${INSTALL_DATA} ${WRKDIR}/configuration.yaml ${STAGEDIR}${Z2M_DATADIR}/configuration.yaml.sample
	${INSTALL} -lrs ${STAGEDIR}${Z2M_DATADIR} ${STAGEDIR}${Z2M_HOME}/data

# This should be run after DISTVERSION change
create-caches-tarball: ${WRKSRC}
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} npm install --ignore-scripts --no-progress --no-audit --no-fund && \
		${FIND} ${WRKSRC}/node_modules -type d -a \( -name build -o -name dist \) -print0 | xargs -0 ${RM} -rf && \
		${TAR} czf ${WRKDIR}/zigbee2mqtt-nodemodules-${PKGVERSION}.tar.gz \
		node_modules package-lock.json

.include <bsd.port.mk>
