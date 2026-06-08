PORTNAME=	rcheckbook
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	finance

MAINTAINER=	tonyhawk2100@gmail.com
COMMENT=	CLI based checkbook ledger
WWW=		https://github.com/bryceac/rcheckbook

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo llvm:lib

USE_GITHUB=	yes
GH_ACCOUNT=	bryceac

MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib

PLIST_FILES=	"@dir ${SCHEMADIR}" \
		${SCHEMADIR}/register.sql \
		bin/${PORTNAME}

SCHEMADIR=		${LOCALBASE}/share/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${SCHEMADIR}
	${INSTALL_DATA} ${WRKSRC}/register.sql \
		${STAGEDIR}${SCHEMADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/rcheckbook \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
