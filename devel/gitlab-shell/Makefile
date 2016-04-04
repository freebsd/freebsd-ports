# Created by: Torsten Zuehlsdorff <ports@toco-domains.de
# $FreeBSD$

PORTNAME=	gitlab-shell
PORTVERSION=	2.7.1
CATEGORIES=	devel
MASTER_SITES=	http://ports.toco-domains.de/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@toco-domains.de
COMMENT=	GitLab Shell handles git commands for GitLab

BUILD_DEPENDS=	ruby>=2.1.5:lang/ruby21 \
		gem:devel/ruby-gems

USERS=		git
GROUPS=		git

NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}/var/log/gitlab-shell

.include <bsd.port.mk>
