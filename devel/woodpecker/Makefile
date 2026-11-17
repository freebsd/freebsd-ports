PORTNAME=	woodpecker
DISTVERSIONPREFIX=	v
DISTVERSION=	3.20.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/woodpecker-ci/woodpecker/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	woodpecker-src
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT?=	Simple yet powerful CI/CD engine
WWW=		https://woodpecker-ci.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

.if ${PKGNAMESUFFIX:U:M-agent}
RUN_DEPENDS=	git:devel/git \
		plugin-git:devel/woodpecker-plugin-git
.endif

USES=		go:1.27+,modules

# The release's source tarball carries vendor/ and the built web UI
# (web/dist), so neither Go modules nor pnpm are fetched at build time.
NO_WRKSUBDIR=	yes

GO_LDFLAGS=	-X go.woodpecker-ci.org/woodpecker/v3/version.Version=${DISTVERSION}

SUB_FILES=	pkg-message${PKGNAMESUFFIX:U}
SUB_LIST=	WOODPECKER_USER=${USERS}

USERS=		woodpecker
GROUPS=		woodpecker

# devel/woodpecker-agent is a slave of this port.
.if ${PKGNAMESUFFIX:U:M-agent}
ROLE=		agent
GO_TARGET=	./cmd/agent:${PREFIX}/bin/woodpecker-agent
.else
ROLE=		server
GO_TARGET=	./cmd/cli:${PREFIX}/bin/woodpecker-cli \
		./cmd/server:${PREFIX}/bin/woodpecker-server
GO_BUILDFLAGS=	-tags sqlite_unlock_notify
.endif
USE_RC_SUBR=	woodpecker_${ROLE}
PKGMESSAGE=	${WRKDIR}/pkg-message${PKGNAMESUFFIX:U}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/db/woodpecker
	${INSTALL_DATA} ${FILESDIR}/${ROLE}.env.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
