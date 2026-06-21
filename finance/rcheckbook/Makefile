PORTNAME=	rcheckbook
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.6
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
		bin/${PORTNAME} \
		${MANDIR}/rcheckbook.1 \
		${MANDIR}/rcheckbook-add.1 \
		${MANDIR}/rcheckbook-export.1 \
		${MANDIR}/rcheckbook-import.1 \
		${MANDIR}/rcheckbook-list.1 \
		${MANDIR}/rcheckbook-remove.1 \
		${MANDIR}/rcheckbook-summary.1 \
		${MANDIR}/rcheckbook-update.1 \

SCHEMADIR=		${LOCALBASE}/share/${PORTNAME}
MANDIR=		${LOCALBASE}/share/man/man1

do-install:
	${MKDIR} ${STAGEDIR}${SCHEMADIR}
	${INSTALL_DATA} ${WRKSRC}/register.sql \
		${STAGEDIR}${SCHEMADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/rcheckbook \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
