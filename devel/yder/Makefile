PORTNAME=	yder
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.19
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Logging library for C applications
WWW=		https://github.com/babelouest/yder

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	orcania>=2.3.2:devel/orcania
LIB_DEPENDS=	liborcania.so:devel/orcania
RUN_DEPENDS=	jansson>=2.4:devel/jansson

USES=		cmake pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	babelouest

CMAKE_OFF=	DOWNLOAD_DEPENDENCIES WITH_JOURNALD
PIE_UNSAFE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTEXAMPLES=	Makefile log_callback.c log_combined.c log_console.c log_file.c \
		log_journald.c log_newline.c log_syslog.c

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
