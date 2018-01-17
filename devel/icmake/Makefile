# $FreeBSD$

PORTNAME=	icmake
PORTVERSION=	9.02.04
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Intelligent C-like Maker

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed

WRKSRC_SUBDIR=	${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

REINPLACE_ARGS=	-I ""

USES=		shebangfix
SHEBANG_FILES=	build comp/build comp/icm_bootstrap comp/updategrammar \
		comp/updateparser comp/updatescanner dep/build dep/icm_bootstrap \
		exec/build exec/icm_bootstrap exec/list/test/build exec/string/test/build \
		icm_bootstrap icm_github icm_install icm_prepare icmake/build \
		icmake/icm_bootstrap icmake/setlinks icmbuild/build icmbuild/icm_bootstrap \
		iuo/bootstrapinstall iuo/install iuo/uninstall pp/build pp/icm_bootstrap \
		rss/build rss/icm_bootstrap scripts/convert un/build un/icm_bootstrap

USE_GITHUB=	yes
GH_ACCOUNT=	fbb-git

post-patch:
	@${REINPLACE_CMD} -e 's|find|find .|g' \
		${WRKSRC}/icm_prepare
	@${REINPLACE_CMD} -e 's|sed|gsed|g' \
		${WRKSRC}/scripts/conversions \
		${WRKSRC}/scripts/convert
	@${REINPLACE_CMD} -e 's|"usr/bin"|"bin"| ; \
		s|"usr/share/icmake"|"share/icmake-${PORTVERSION}"| ; \
		s|"usr/share/man"|"man"| ; \
		s|"usr/lib/icmake"|"lib/icmake-${PORTVERSION}"| ; \
		s|"usr/share/doc/icmake"|"share/doc/icmake-${PORTVERSION}"| ; \
		s|"usr/share/doc/icmake-doc"|"share/doc/icmake-${PORTVERSION}/doc"|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|cp -r|cp -R|' \
		${WRKSRC}/icm_bootstrap \
		${WRKSRC}/icm_install
	@${REINPLACE_CMD} -e 's|#!.*/usr/bin/icmake|#!${PREFIX}/bin/icmake|' \
		${WRKSRC}/comp/build \
		${WRKSRC}/doc/icmake.1 \
		${WRKSRC}/doc/manpage/icmake.yo \
		${WRKSRC}/doc/manpage/build \
		${WRKSRC}/examples/am \
		${WRKSRC}/examples/bup \
		${WRKSRC}/examples/defines \
		${WRKSRC}/examples/ds \
		${WRKSRC}/examples/ftpxfer \
		${WRKSRC}/examples/idir \
		${WRKSRC}/examples/initialization \
		${WRKSRC}/examples/killprog \
		${WRKSRC}/examples/nesteddirectives \
		${WRKSRC}/examples/r \
		${WRKSRC}/examples/tolower \
		${WRKSRC}/exec/build \
		${WRKSRC}/pp/build \
		${WRKSRC}/rss/build
	@${REINPLACE_CMD} -e 's|"gcc"|"${CC}"|g; s|-Wall -O2|${CFLAGS}|g' \
		${WRKSRC}/comp/build \
		${WRKSRC}/doc/icmake.doc \
		${WRKSRC}/exec/icmconf \
		${WRKSRC}/usr/share/icmake/icmconf \
		${WRKSRC}/exec/build \
		${WRKSRC}/pp/build \
		${WRKSRC}/rss/build \
		${WRKSRC}/un/build

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_prepare ${PREFIX}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_bootstrap x

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install strip all ${STAGEDIR}

.include <bsd.port.mk>
