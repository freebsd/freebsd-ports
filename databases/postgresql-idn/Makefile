PORTNAME=	idn
PORTVERSION=	0.2
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PostgreSQL extension for libidn2
WWW=		https://github.com/dyninc/postgresql-idn

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libidn.so:dns/libidn \
		libidn2.so:dns/libidn2

USES=		gmake pgsql
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	dyninc
GH_PROJECT=	postgresql-idn
GH_TAGNAME=	d4ffaec

BUILD_WRKSRC=	${WRKSRC}/sources

PLIST_FILES=	\
		lib/postgresql/idn.so \
		share/postgresql/extension/idn.control \
		share/postgresql/extension/idn--0.2.sql

post-patch:
	@${REINPLACE_CMD} -e 's|CreateTemplateTupleDesc(3, false)|CreateTemplateTupleDesc(3)|g' \
		${BUILD_WRKSRC}/idn.c

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/postgresql
	${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql/extension
	${INSTALL_LIB} ${BUILD_WRKSRC}/idn.so ${STAGEDIR}${PREFIX}/lib/postgresql/idn.so
	${INSTALL_DATA} ${BUILD_WRKSRC}/idn--0.2.sql ${STAGEDIR}${PREFIX}/share/postgresql/extension
	${INSTALL_DATA} ${BUILD_WRKSRC}/idn.control ${STAGEDIR}${PREFIX}/share/postgresql/extension

.include <bsd.port.mk>
