PORTNAME=	retcl
PORTVERSION=	0.6.0
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl client library for Redis
WWW=		https://github.com/gahr/retcl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tcl:run
USE_GITHUB=	yes
GH_ACCOUNT=	gahr

NO_BUILD=	yes

LIBDIR=		${TCL_LIBDIR:S/${LOCALBASE}/${PREFIX}/}
PLIST_FILES=	${LIBDIR}/${PORTNAME}-${DISTVERSION}.tm

do-install:
	${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.tm \
	    ${STAGEDIR}${LIBDIR}/${PORTNAME}-${DISTVERSION}.tm

.include <bsd.port.mk>
