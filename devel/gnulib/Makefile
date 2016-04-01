# $FreeBSD$

PORTNAME=	gnulib
PORTVERSION=	20140202
CATEGORIES=	devel
MASTER_SITES=	http://erislabs.net/ianb/projects/gnulib/
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU portability library

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:print/texinfo

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	check-module

PLIST_FILES=	bin/check-module bin/gnulib-tool
INFO=		${PORTNAME}
PORTDOCS=	gnulib.html
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's/date -u.*/stat -f %Sa -t "@set UPDATED %F %T" `ls -t $$^ | sed 1q` > $$@/' \
		-e 's: makeinfo$$: ${LOCALBASE}/bin/makeinfo:' \
		${WRKSRC}/doc/Makefile

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C doc info html

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
	for p in check-module gnulib-tool;\
		do ${INSTALL_SCRIPT} ${WRKSRC}/$$p ${STAGEDIR}${DATADIR};\
			cd ${STAGEDIR}${PREFIX}/bin;\
			${LN} -s ../${DATADIR_REL}/$$p;\
		done
	${TAR} -cf - -C ${WRKSRC} build-aux config doc lib m4 modules \
		tests top | ${TAR} -xof - -C ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
