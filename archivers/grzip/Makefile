PORTNAME=	grzip
DISTVERSION=	0.3.1
CATEGORIES=	archivers
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Efficient file compressor
WWW=		https://BSDforge.com/projects/archivers/grzip

LICENSE=	LGPL21

USES=		gettext-runtime localbase:ldflags
USE_LDCONFIG=	yes
ALL_TARGET=	${PORTNAME}
CFLAGS+=	-fPIC
LDFLAGS+=	-lintl
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} ' \
			s|DESTDIR|PREFIX|g; \
			/^CC.*=/d;/^OPTFLAGS/s|-O2||; \
			/^CFLAGS/s|=|+=|; \
			/^PREFIX=/d;/^LDFLAGS/s|=|+=|; \
			s|-Wl,-soname,lib${PORTNAME}.so|-Wl,-soname,lib${PORTNAME}.so.0|' \
		${WRKSRC}/Makefile \
		${WRKSRC}/po/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/grunzip
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/grzcat
	${INSTALL_SCRIPT} ${grztar grzdiff grzgrep grzmore:L:S|^|${WRKSRC}/scripts/|} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0
	${LN} -sf lib${PORTNAME}.so.0 ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include

do-install-NLS-on:
	(cd ${WRKSRC}/po; ${SETENV} ${MAKE_ENV} ${MAKE} PREFIX="${STAGEDIR}${PREFIX}" install)

.include <bsd.port.mk>
