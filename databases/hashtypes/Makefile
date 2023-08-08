PORTNAME=	hashtypes
PORTVERSION=	0.1.4
CATEGORIES=	databases security
MASTER_SITES=	http://api.pgxn.org/dist/hashtypes/${PORTVERSION}/ \
		http://oss-files.dreamindustries.co/mirror/

PATCH_SITES=	https://github.com/adjust/${PORTNAME}/commit/
PATCHFILES+=	1c08e29edab2541ab06bd1c990ae68beb417e542.patch:-p1

MAINTAINER=	oss-contrib@dreamindustries.co
COMMENT=	Hash data types for PostgreSQL
WWW=		https://pgxn.org/dist/hashtypes/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pgsql zip

MAKE_ARGS=	USE_PGXS=1 MODULEDIR=extension
INSTALL_TARGET=	install-strip

LLD_UNSAFE=	yes

MODULEDIR=	${PREFIX}/share/postgresql/extension

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.control ${STAGEDIR}${MODULEDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/hashtypes.so

.include <bsd.port.mk>
