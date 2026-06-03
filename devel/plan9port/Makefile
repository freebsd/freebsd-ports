PORTNAME=	plan9port
PORTVERSION=	20250218
CATEGORIES=	devel plan9
DIST_SUBDIR=	plan9port
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	Plan 9 from User Space
WWW=		https://9fans.github.io/plan9port/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	as:devel/binutils
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 localbase:ldflags perl5 shebangfix xorg
USE_PERL5=	build
USE_XORG=	x11 xext xt

USE_GITHUB=	yes
GH_ACCOUNT=	9fans
GH_TAGNAME=	13582b1

SHEBANG_GLOB=	*
SHEBANG_LANG=	rc
rc_OLD_CMD=	/bin/rc /usr/local/plan9/bin/rc
rc_CMD=		${PREFIX}/plan9/bin/rc

SUB_FILES=	pkg-message
SUB_LIST=	OPSYS=${OPSYS}

OPTIONS_DEFINE=		DATA
OPTIONS_DEFAULT=	DATA
OPTIONS_SUB=		yes

DATA_DESC=	Install dictionary, thesaurus, and other data files

DATA_MASTER_SITES=	https://9fans.github.io/plan9port/dist/
DATA_DISTFILES=		pgw.tar.bz2 \
			roget.tar.bz2 \
			scat.tgz

.include <bsd.port.pre.mk>

post-extract-DATA-on:
	@cd ${WRKSRC}/dict && ${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/pgw.tar.bz2
	@cd ${WRKSRC}/dict && ${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/roget.tar.bz2
	@cd ${WRKSRC}/sky && ${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/scat.tgz

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/font/bit|${PREFIX}/plan9/font|' \
		${WRKSRC}/src/cmd/acme/acme.c
# XXX: remove after https://github.com/9fans/plan9port/issues/648 fixed
	@${REINPLACE_CMD} -e 's|kcmp(|${PORTNAME}_&|' \
		${WRKSRC}/src/cmd/sort.c
	@${REINPLACE_CMD} -e 's|#!/bin/rc|#!${PREFIX}/plan9/bin/rc|' \
		${WRKSRC}/src/cmd/upas/ml/mlmgr.c \
		${WRKSRC}/src/cmd/tcs/font/mkfile
	@${REINPLACE_CMD} -e 's|ulong|u64int|' \
		${WRKSRC}/src/libmach/FreeBSD.c

do-configure:
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${ECHO_CMD} 'CC9="${CC}"' > ${WRKSRC}/LOCAL.config
.endif
	@${ECHO_CMD} 'CFLAGS="${CFLAGS}"' >> ${WRKSRC}/LOCAL.config
	@${ECHO_CMD} 'LDFLAGS="${LDFLAGS}"' >> ${WRKSRC}/LOCAL.config
	@${ECHO_CMD} 'FONTSRV=fontsrv' >> ${WRKSRC}/LOCAL.config

do-build:
	@cd ${WRKSRC} && ${SETENV} CC9=${CC} ./INSTALL -b

do-install:
.for f in .gitkeep actions.yaml
	@${FIND} ${WRKSRC} -type f -name ${f} -delete
.endfor
	@${RMDIR} ${WRKSRC}/.github/workflows ${WRKSRC}/.github
	@cd ${WRKSRC} && ${SED} -i '' 's#/usr/local#${PREFIX}#' \
		`${CAT} lib/moveplan9.files`
	@${MKDIR} ${STAGEDIR}${PREFIX}/plan9
	@cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${PREFIX}/plan9
	@${RLN} ${STAGEDIR}${PREFIX}/plan9/bin/9 ${STAGEDIR}${PREFIX}/bin/9
	@cd ${STAGEDIR}${PREFIX}/plan9 && \
		for f in bin/* bin/disk/* bin/fossil/* bin/fs/* bin/venti/* \
		src/cmd/devdraw/o.devdraw; do \
			${STRIP_CMD} $$f > /dev/null 2>&1 || ${TRUE}; \
		done

.include <bsd.port.post.mk>
