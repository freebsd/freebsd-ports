PORTNAME=	guile
PORTVERSION=	1.8.8
PORTREVISION=	2
CATEGORIES=	lang scheme
MASTER_SITES=	GNU
PKGNAMESUFFIX=	1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Ubiquitous Intelligent Language for Extension
WWW=		https://www.gnu.org/software/guile/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libgmp.so:math/gmp

# We need to pull the aclocal/guile.m4 from guile3 rather than using
# our own version, in order to avoid conflicts.
RUN_DEPENDS=	guile-aclocal>=3:lang/guile-aclocal

USES=		guile:${PORTVERSION:R},env autoreconf cpe gmake libtool \
		localbase ncurses pathfix readline
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=--program-suffix=-${GUILE_VER} \
		--includedir='$${prefix}/include/guile/${GUILE_VER}/'

INSTALL_TARGET=	install-strip

CFLAGS+=	-fwrapv

PORTSCOUT=	limit:^1\.

INFO=		goops guile-tut guile r5rs
INFO_PATH=	${GUILE_INFO_PATH}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

REINPLACE_FILES_1=	libguile/smob.c libguile/filesys.c libguile/gc.c \
			libguile/mallocs.c libguile/eval.c libguile/gc-malloc.c \
			libguile/ports.c libguile/gc-mark.c libguile/gc_os_dep.c
REINPLACE_FILES_2=	guile-config/guile-config.in
REINPLACE_FILES_3=	PROGRAM frisk read-text-outline generate-autoload \
			scan-api api-diff lint snarf-check-and-output-texi \
			autofrisk punify snarf-guile-m4-docs display-commentary \
			read-rfc822 summarize-guile-TODO doc-snarf \
			read-scheme-source use2dot

post-extract:
	${MV} ${WRKSRC}/doc/guile.1 ${WRKSRC}/doc/guile${GUILE_SFX}.1

post-patch:
	@cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${REINPLACE_FILES_1}
	@${REINPLACE_CMD} -e 's|srfi doc examples|srfi examples|g' \
		${WRKSRC}/Makefile.am
	@${TOUCH} ${WRKSRC}/Makefile.in
	@cd ${WRKSRC} ; \
	  ${REINPLACE_CMD} -e '1s/guile/guile-${GUILE_VER}/' ${REINPLACE_FILES_2}
	@cd ${WRKSRC}/scripts ; \
	  ${REINPLACE_CMD} -e '1,/!#/s/GUILE-guile/GUILE-guile-${GUILE_VER}/' \
		${REINPLACE_FILES_3}

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/aclocal/guile.m4
	for p in guile guile-tools guile-config guile-snarf; do \
	  ${LN} -s $${p}-${GUILE_VER} ${STAGEDIR}${PREFIX}/bin/$${p}${GUILE_SFX}; \
	done
	${INSTALL_MAN} ${WRKSRC}/doc/guile${GUILE_SFX}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${MKDIR} ${STAGEDIR}${PREFIX}/${GUILE_INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/goops/goops.info ${STAGEDIR}${PREFIX}/${GUILE_INFO_PATH}/
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial/guile-tut.info ${STAGEDIR}${PREFIX}/${GUILE_INFO_PATH}/
	${INSTALL_DATA} ${WRKSRC}/doc/ref/guile.info ${STAGEDIR}${PREFIX}/${GUILE_INFO_PATH}/
	${INSTALL_DATA} ${WRKSRC}/doc/r5rs/r5rs.info ${STAGEDIR}${PREFIX}/${GUILE_INFO_PATH}/

.include <bsd.port.mk>
