# Created by: Chen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTREVISION=	3

MASTERDIR=	${.CURDIR}/../../japanese/kon2-16dot
CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org

DEPRECATED=	Depends on expiring chinese/cce
EXPIRATION_DATE=	2015-11-26

BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/chinese/kcfonts:patch \
		${NONEXISTENT}:${PORTSDIR}/chinese/cce:extract

KCFONTS_WRKSRC=	`cd ${PORTSDIR}/chinese/kcfonts; make -V WRKSRC`
CCE_WRKSRC=	`cd ${PORTSDIR}/chinese/cce; make -V WRKSRC`

PLIST_FILES=	share/fonts/bdf/kc15f.bdf.gz \
		share/fonts/bdf/gb16fs.bdf.gz \
		share/fonts/bdf/8x16.bdf.gz

post-patch: post-patch-zhkon2

post-patch-zhkon2:
	@${REINPLACE_CMD} -e 's,/dev/vga,/dev/ttyv0,g' ${WRKSRC}/src/term.c \
		${WRKSRC}/src/display/vga.c
	@cd ${WRKSRC} && ${PATCH} < ${.CURDIR}/files/patch-lib__coding.c
	@cd ${WRKSRC} && ${PATCH} < ${.CURDIR}/files/patch-kon.cfg.FreeBSD

post-build: post-build-zhkon2
post-build-zhkon2:
	@cd ${KCFONTS_WRKSRC} && ${MAKE} kc15f

post-install: post-install-zhkon2
post-install-zhkon2:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fonts/bdf
	cd ${KCFONTS_WRKSRC} && ./kc15f | ${GZIP_CMD} - > \
		${STAGEDIR}${PREFIX}/share/fonts/bdf/kc15f.bdf.gz
	cd ${CCE_WRKSRC} && ${CAT} fonts/gb16fs.bdf | ${GZIP_CMD} - > \
		${STAGEDIR}${PREFIX}/share/fonts/bdf/gb16fs.bdf.gz
	cd ${CCE_WRKSRC} && ${CAT} fonts/8x16.bdf | ${GZIP_CMD} - > \
		${STAGEDIR}${PREFIX}/share/fonts/bdf/8x16.bdf.gz

.include "${MASTERDIR}/Makefile"
