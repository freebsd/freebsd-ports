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
		${MANDIR}/rcheckbook.1.gz \
		${MANDIR}/rcheckbook-add.1.gz \
		${MANDIR}/rcheckbook-export.1.gz \
		${MANDIR}/rcheckbook-import.1.gz \
		${MANDIR}/rcheckbook-list.1.gz \
		${MANDIR}/rcheckbook-remove.1.gz \
		${MANDIR}/rcheckbook-summary.1.gz \
		${MANDIR}/rcheckbook-update.1.gz \

SCHEMADIR=		${LOCALBASE}/share/${PORTNAME}
MANDIR=		${LOCALBASE}/share/man/man1

do-install:
	${MKDIR} ${STAGEDIR}${SCHEMADIR}
	${MKDIR} ${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/register.sql \
		${STAGEDIR}${SCHEMADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/rcheckbook \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook.1 \
		${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook-add.1 \
		${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook-export.1 \
		${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook-import.1 \
		${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook-list.1 \
		${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook-remove.1 \
		${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook-summary.1 \
		${STAGEDIR}${MANDIR}
	${INSTALL_DATA} ${WRKSRC}/man/rcheckbook-update.1 \
		${STAGEDIR}${MANDIR}

.include <bsd.port.mk>
