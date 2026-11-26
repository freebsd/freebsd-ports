PORTNAME=	soft-serve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.6
PORTREVISION=	26
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Self-hosted Git server for the command line
WWW=		https://github.com/charmbracelet/soft-serve

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		cpe go:modules
GO_MODULE=	github.com/charmbracelet/soft-serve
GO_TARGET=	./cmd/soft
USE_RC_SUBR=	soft-serve
SUB_FILES=	pkg-message
SUB_LIST+=	CHOWN="${CHOWN}" \
		CUT="${CUT}" \
		DEFAULTHOST=0.0.0.0 \
		DEFAULTKEY=.ssh/soft_serve_server_ed25519 \
		DEFAULTPORT=23231 \
		DEFAULTREPO=.repos \
		DEFAULTDATA=data \
		DIRNAME="${DIRNAME}" \
		GITUSER="${USERS}" \
		MKDIR="${MKDIR}" \
		PW="${PW}" \
		SU="${SU_CMD:[1]}" \
		SETENV="${SETENV}"
USERS=		git
GROUPS=		git
PLIST_FILES=	${DOCSDIR_REL}/README.md \
		bin/${PORTNAME}

CPE_VENDOR=	charm
CPE_PRODUCT=	${PORTNAME:tl:S/-/_/g}

.include <bsd.port.options.mk>

post-install:
		${MV} ${STAGEDIR}${PREFIX}/bin/soft ${STAGEDIR}${PREFIX}/bin/soft-serve
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
