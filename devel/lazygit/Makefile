# $FreeBSD$

PORTNAME=	lazygit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
CATEGORIES=	devel

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Simple terminal UI for git commands

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	jesseduffield

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	${MKDIR} ${GO_WRKSRC:H}
	${LN} -sf ${WRKSRC} ${GO_WRKSRC:H}/${PORTNAME}
	${MKDIR} ${GO_WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}/
	${MV} ${GO_WRKSRC}/pkg ${GO_WRKSRC}/vendor/github.com/${GH_ACCOUNT}/${PORTNAME}/

.include <bsd.port.mk>
