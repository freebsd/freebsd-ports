# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-shell
PORTVERSION=	8.1.1
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Shell handles git commands for GitLab

LICENSE=	MIT

BUILD_DEPENDS=	gem:devel/ruby-gems \
		go>=1.5.3:lang/go

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-shell/tags
GL_COMMIT=	5287eee65e7f29e8d5296eb3ef24a06a9a60b3f1

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
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly-upload-pack
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly-receive-pack
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly-upload-archive

.include <bsd.port.mk>
