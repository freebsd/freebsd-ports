# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-shell
PORTVERSION=	3.4.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/gitlab-org/${PORTNAME}/repository/archive.tar.gz?ref=v${PORTVERSION}&dummy=/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	tz@FreeBSD.org
COMMENT=	GitLab Shell handles git commands for GitLab

BUILD_DEPENDS=	gem:devel/ruby-gems

USERS=		git
GROUPS=		git

NO_BUILD=	yes
NO_ARCH=	yes

post-extract:
	@${MV} ${WRKDIR}/${DISTNAME}-* ${WRKDIR}/${DISTNAME}

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}/var/log/gitlab-shell

.include <bsd.port.mk>
