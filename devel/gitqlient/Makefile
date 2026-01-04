PORTNAME=	gitqlient
DISTVERSION=	1.6.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/francescmm/GitQlient/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Graphical interface to git repositories
WWW=		https://francescmm.github.io/GitQlient/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang cpe gl qmake:outsource qt:6
USE_GL=		gl
USE_QT=		base 5compat tools:build

QMAKE_SOURCE_PATH=	${WRKSRC}/GitQlient.pro

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/GitQlient.pro
	@${REINPLACE_CMD} -e 's|%%SHASHORT%%|faf286e|g' \
	    ${PATCH_WRKSRC}/GitQlient.pro

.include <bsd.port.mk>
