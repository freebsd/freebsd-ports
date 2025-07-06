PORTNAME=	homebox
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.2
CATEGORIES=	finance
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSION}.frontend${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Inventory and organization system built for the Home User
WWW=		https://homebox.software

LICENSE=	AGPLv3

BROKEN_i386=	cannot use int64(off) (value of type int64) as int32 value in assignment

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	sysadminsmedia

USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_MODULE=	github.com/sysadminsmedia/${PORTNAME}
GO_TARGET=	./app/api:${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
			-X 'main.commit=${GITID}' \
			-X 'main.buildTime=${BUILD_TIME}' \
			-X 'main.version=${DISTVERSIONPREFIX}${DISTVERSION}'"

SUB_LIST=	USER=${USERS:[1]}

WRKSRC_SUBDIR=	backend

USERS=		${HOMEBOX_USER}
GROUPS=		${HOMEBOX_GROUP}

PLIST_FILES=	bin/${PORTNAME} \
		"@dir(${HOMEBOX_USER},${HOMEBOX_GROUP},0700) /var/db/${PORTNAME}"

# Run 'git checkout ${DISTVERSIONPREFIX}${DISTVERSION} && git rev-parse HEAD'
# in the Homebox repository to get the value of GITID.
GITID=		bd604f5867defe38d66a476226546f65f5e0e223

HOMEBOX_USER=	${PORTNAME}
HOMEBOX_GROUP=	${HOMEBOX_USER}

pre-build:
	@${RM} -r ${WRKSRC}/app/api/static/public
	@${MKDIR} ${WRKSRC}/app/api/static/public
	@cd ${WRKDIR}/homebox-frontend && ${COPYTREE_SHARE} . ${WRKSRC}/app/api/static/public

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>
