# $FreeBSD$

PORTNAME=	gitaly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.2
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/gitlab-org/${PORTNAME}/repository/archive.tar.gz?ref=${DISTVERSIONPREFIX}${PORTVERSION}&dummy=/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.8:lang/go

USES=	gmake
USE_RUBY=	yes

PLIST_FILES=	bin/gitaly

post-extract:
	@${MV} ${WRKDIR}/${DISTNAME}-* ${WRKDIR}/${DISTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gitaly

.include <bsd.port.mk>
