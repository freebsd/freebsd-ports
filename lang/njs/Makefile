PORTNAME=	njs
DISTVERSION=	0.7.6
CATEGORIES=	lang www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	NGINX JavaScript command line utility

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe ssl

CPE_VENDOR=	f5

USE_GITHUB=	yes
GH_TUPLE=	nginx:njs:${DISTVERSION}
HAS_CONFIGURE=	yes

FLAVORS=	pcre pcre2
FLAVOR?=	${FLAVORS:[1]}

pcre_PKGNAMESUFFIX=
pcre2_PKGNAMESUFFIX=	-pcre2

pcre_CONFLICTS_INSTALL=		${PORTNAME}-pcre2
pcre2_CONFLICTS_INSTALL=	${PORTNAME}

.if ${FLAVOR} == pcre
LIB_DEPENDS=		libpcre.so:devel/pcre
CONFIGURE_FLAGS+=	--no-pcre2
.else
LIB_DEPENDS=		libpcre2-8.so:devel/pcre2
.endif

PLIST_FILES=	bin/njs

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} njs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/njs ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
