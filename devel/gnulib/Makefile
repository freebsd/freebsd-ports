# $FreeBSD$

PORTNAME=	gnulib
PORTVERSION=	20130805
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://erislabs.net/ianb/projects/gnulib/
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU portability library

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	check-module


PLIST_FILES=	bin/check-module bin/gnulib-tool
INFO=		${PORTNAME}
PORTDATA=	*

.ifdef		NOPORTDATA
IGNORE=		gnulib requires port data, unset NOPORTDATA to install
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_DIRS+=	%%DOCSDIR%%
PLIST_FILES+=	%%DOCSDIR%%/${PORTNAME}.html
.endif

post-patch:
	${REINPLACE_CMD} -e 's/date -u.*/stat -f %Sa -t "@set UPDATED %F %T" `ls -t $$^ | sed 1q` > $$@/' \
		-e 's: makeinfo$$: ${LOCALBASE}/bin/makeinfo:' \
		${WRKSRC}/doc/Makefile

do-build:
	cd ${WRKSRC} && ${GMAKE} -C doc info html

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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
