# Created by: Serge Gagnon <serge.gagnon@b2b2c.ca>
# $FreeBSD$

PORTNAME=	plan9port
PORTVERSION=	20200330
CATEGORIES=	devel plan9
DIST_SUBDIR=	plan9port
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Plan 9 from User Space

LICENSE=	LUCENT
LICENSE_NAME=	Lucent Public License Version 1.02
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_armv6=	fails to compile: thread.c:130:5: no member named 'arm_r0' in 'mcontext_t'
BROKEN_armv7=	fails to compile: thread.c:130:5: no member named 'arm_r0' in 'mcontext_t'

BUILD_DEPENDS=	as:devel/binutils
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		localbase:ldflags perl5 shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	9fans
GH_TAGNAME=	4650064aa757c217fa72f8819a2cf67c689bcdef
USE_PERL5=	build
USE_XORG=	x11 xext xt

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

post-extract-DATA-on:
	@cd ${WRKSRC}/dict && ${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/pgw.tar.bz2
	@cd ${WRKSRC}/dict && ${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/roget.tar.bz2
	@cd ${WRKSRC}/sky && ${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/scat.tgz

post-patch:
	@${REINPLACE_CMD} -e 's|/lib/font/bit|${PREFIX}/plan9/font|' \
		${WRKSRC}/src/cmd/acme/acme.c
	@${REINPLACE_CMD} -e 's|#!/bin/rc|#!${PREFIX}/plan9/bin/rc|' \
		${WRKSRC}/src/cmd/upas/ml/mlmgr.c \
		${WRKSRC}/src/cmd/tcs/font/mkfile
	@${REINPLACE_CMD} -e 's|ulong|u64int|' ${WRKSRC}/src/libmach/FreeBSD.c

do-configure:
	@${ECHO_CMD} 'CFLAGS="${CFLAGS}"' > ${WRKSRC}/LOCAL.config
	@${ECHO_CMD} 'LDFLAGS="${LDFLAGS}"' >> ${WRKSRC}/LOCAL.config
	@${ECHO_CMD} 'FONTSRV=fontsrv' >> ${WRKSRC}/LOCAL.config

do-build:
	@cd ${WRKSRC} && ${SETENV} CC9=${CC} ./INSTALL -b

do-install:
.for l in .cvsignore .hg .hgignore .hgtags .gitignore .gitkeep *.bak *.orig *.beforesubst .travis.yml
	@${FIND} ${WRKSRC} -name "${l}" -delete
.endfor
	@cd ${WRKSRC} && ${SED} -i '' 's#/usr/local#${PREFIX}#' \
		`${CAT} lib/moveplan9.files`
	@${MKDIR} ${STAGEDIR}${PREFIX}/plan9
	@cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${PREFIX}/plan9
	@${RLN} ${STAGEDIR}${PREFIX}/plan9/bin/9 ${STAGEDIR}${PREFIX}/bin/9

post-install:
	@cd ${STAGEDIR}${PREFIX}/plan9 && \
		for f in bin/* bin/disk/* bin/fossil/* bin/fs/* bin/venti/* src/cmd/devdraw/o.devdraw; do \
			${STRIP_CMD} $$f > /dev/null 2>&1 || ${TRUE}; \
		done

.include <bsd.port.mk>
