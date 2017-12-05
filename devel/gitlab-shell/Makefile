# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-shell
PORTVERSION=	5.9.3
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/gitlab-org/${PORTNAME}/repository/archive.tar.gz?ref=v${PORTVERSION}&dummy=/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

LICENSE=	MIT

MAINTAINER=	idefix@fechner.net
COMMENT=	GitLab Shell handles git commands for GitLab

BUILD_DEPENDS=	gem:devel/ruby-gems \
		go>=1.5.3:lang/go

USERS=		git
GROUPS=		git

post-extract:
	@${MV} ${WRKDIR}/${DISTNAME}-* ${WRKDIR}/${DISTNAME}

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample

pre-install:
	${WRKSRC}/bin/compile
	${RM} -rf ${WRKSRC}/go
	${RM} -rf ${WRKSRC}/go_build

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}/var/log/gitlab-shell
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly-upload-pack
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly-receive-pack

.include <bsd.port.mk>
