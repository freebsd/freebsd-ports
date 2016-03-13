# Created by: Torsten Zuehlsdorff <ports@toco-domains.de
# $FreeBSD$

PORTNAME=	gitlab-shell
PORTVERSION=	2.6.10
CATEGORIES=	devel
MASTER_SITES=	http://ports.toco-domains.de/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@toco-domains.de
COMMENT=	GitLab Shell handles git commands for GitLab

BUILD_DEPENDS=	ruby>=2.1.5:${PORTSDIR}/lang/ruby21 \
		gem:${PORTSDIR}/devel/ruby-gems

USERS=		git
GROUPS=		git

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample

post-install:
	${MKDIR} ${STAGEDIR}/var/log/
	${TOUCH} ${STAGEDIR}/var/log/gitlab-shell.log
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
