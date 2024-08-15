PORTNAME=	gptscript
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Natural Programming Language
WWW=		https://gptscript.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.22

GO_MODULE=	github.com/gptscript-ai/gptscript
OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's/0.0.0-dev/${PORTVERSION}/1' \
		${WRKSRC}/pkg/version/version.go

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
