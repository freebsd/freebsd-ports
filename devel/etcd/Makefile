# $FreeBSD$

PORTNAME=	etcd
PORTVERSION=	0.1.2
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos

MAINTAINER=	ports@robakdesign.com
COMMENT=	Highly-available key value store and service discovery

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	coreos
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	5589b6f

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

post-patch:
	@${REINPLACE_CMD} -e 's|$$VER|${DISTVERSION}|' ${WRKSRC}/scripts/release-version
	@${REINPLACE_CMD} -e '/VER=/d' ${WRKSRC}/scripts/release-version

pre-install:
	@(cd ${WRKSRC}; ${SH} build)

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
