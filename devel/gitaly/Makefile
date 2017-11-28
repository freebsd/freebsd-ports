# $FreeBSD$

PORTNAME=	gitaly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/gitlab-org/${PORTNAME}/repository/archive.tar.gz?ref=${DISTVERSIONPREFIX}${PORTVERSION}&dummy=/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.8:lang/go

USES=	gmake
USE_RUBY=	yes

post-extract:
	${MV} ${WRKDIR}/${DISTNAME}-* ${WRKDIR}/${DISTNAME}

post-patch:
	${MV} ${WRKDIR}/${DISTNAME}/config.toml.example ${WRKDIR}/${DISTNAME}/config.toml.sample

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	(cd ${WRKSRC}/_build/bin/ && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}/bin && \
	cd ${WRKSRC} && ${COPYTREE_SHARE} config.toml.sample  ${STAGEDIR}${DATADIR})

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly

.include <bsd.port.mk>
