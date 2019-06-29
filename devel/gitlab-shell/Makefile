# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-shell
PORTVERSION=	9.1.0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Shell handles git commands for GitLab

LICENSE=	MIT

BUILD_DEPENDS=	gem:devel/ruby-gems

USES=		go

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-shell/tags
GL_COMMIT=	0e3052be5642c90ee173ff9af1e28358f227fbed

USERS=		git
GROUPS=		git

INSTALL_TARGET=install-strip

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample

do-build:
	export GOCACHE=${WRKSRC}/go && ${WRKSRC}/bin/compile

pre-install:
	${RM} -rf ${WRKSRC}/go
	${RM} -rf ${WRKSRC}/go_build

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}/var/log/gitlab-shell

.include <bsd.port.mk>
