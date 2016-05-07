# $FreeBSD$

PORTNAME=	icmake
PORTVERSION=	7.22.01
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Intelligent C-like Maker

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

REINPLACE_ARGS=	-I ""

USES=		shebangfix
SHEBANG_FILES=	icm_bootstrap icm_install icm_prepare scripts/convert

.include <bsd.port.options.mk>

post-patch:
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
	@${REINPLACE_CMD} -e '\
		s|"ar"|"${AR}"| ; \
		s|"rsv"|"${ARFLAGS}"| ; \
		s|"gcc"|"${CC}"| ; \
		s|"gzip"|"${GZIP_CMD}"| ; \
		s|"cp"|"${CP}"| ; \
		s|"mkdir"|"${MKDIR}"| ; \
		s|"rm"|"${RM}"| ; \
		s|"strip"|"${STRIP_CMD}"|' \
		${WRKSRC}/def/programs
	@${REINPLACE_CMD} -e 's|cp -r|cp -R|' \
		${WRKSRC}/icm_bootstrap \
		${WRKSRC}/icm_install
	@${REINPLACE_CMD} -e 's|#!.*/usr/bin/icmake|#!${PREFIX}/bin/icmake|' \
		${WRKSRC}/comp/build \
		${WRKSRC}/doc/icmake.1 \
		${WRKSRC}/doc/manpage/icmake.yo \
		${WRKSRC}/doc/manpage/build \
		${WRKSRC}/examples/am \
		${WRKSRC}/examples/defines \
		${WRKSRC}/examples/ds \
		${WRKSRC}/examples/ftpxfer \
		${WRKSRC}/examples/initialization \
		${WRKSRC}/examples/nesteddirectives \
		${WRKSRC}/examples/r \
		${WRKSRC}/exec/build \
		${WRKSRC}/make/build \
		${WRKSRC}/pp/build \
		${WRKSRC}/rss/build \
		${WRKSRC}/un/build
	@${REINPLACE_CMD} -e 's|"gcc"|"${CC}"|g; s|-Wall -O2|${CFLAGS}|g' \
		${WRKSRC}/comp/build \
		${WRKSRC}/def/programs \
		${WRKSRC}/doc/icmake.doc \
		${WRKSRC}/exec/icmconf \
		${WRKSRC}/usr/share/icmake/icmconf \
		${WRKSRC}/exec/build \
		${WRKSRC}/make/build \
		${WRKSRC}/pp/build \
		${WRKSRC}/rss/build \
		${WRKSRC}/un/build
	@${REINPLACE_CMD} -e '\
		s|/usr/lib/icmake|${PREFIX}/lib/icmake-${PORTVERSION}|g; \
		s|/usr/share/icmake|${PREFIX}/share/icmake-${PORTVERSION}|g; \
		s|/etc/icmake/icmake.cf|${PREFIX}/etc/icmake/icmake.rc|g' \
		${WRKSRC}/etc/icmake/icmake.rc

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_bootstrap ${PREFIX}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install strip progs ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install scripts ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install skel ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install etc ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install man ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install doc ${STAGEDIR}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./icm_install docdoc ${STAGEDIR}

.include <bsd.port.mk>
