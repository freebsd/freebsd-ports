# New ports collection makefile for:	kanji18
# Version required:	1.0
# Date created:		23 November 1999
# Whom:			Yoshiro MIHIRA <sanpei@sanpei.org>
#
# $FreeBSD$
#

DISTNAME?=	kanji18
PKGNAME=	ja-${DISTNAME}-1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=   ${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	${DISTNAME}
DISTFILES?=	573.z 574.z 575.z 576.z 577.z 578.z 579.z 580.z 581.z

MAINTAINER=     sanpei@sanpei.org

BUILD_DEPENDS=	gunshar:${PORTSDIR}/archivers/gshar+gunshar \
		bdftopcf:${PORTSDIR}/x11/XFree86

DIST_SUBDIR=	${DISTNAME}
FONTSDIR=	lib/X11/fonts/local
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| gunshar -d $(WRKDIR)
PKGINSTALL=	${WRKSRC}/INSTALL
PKGDEINSTALL=	${WRKSRC}/DEINSTALL
PLIST_SUB=	FONTSDIR=${FONTSDIR}
README_FILE?=	573.z
RESIZESED_FILE?=	18to16.sed
RESIZED_ALIAS_FILE?=	kanji16.alias

post-extract:
	@(cd $(WRKSRC); ${CAT} ${DISTNAME}.?? | uudecode)

post-patch:
	@(cd $(WRKSRC); zcat ${DISTNAME}.bdf.Z \
		| bdftopcf -i | ${GZIP_CMD} > ${DISTNAME}.pcf.gz )
	@(${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${README_FILE} \
		| ${AWK} '/^#! \/bin\/sh/{i=1} i==0{print}' \
		> ${WRKSRC}/README.${DISTNAME})

do-build:
	@for file in INSTALL DEINSTALL; do \
		${SED} -e 's,%%FONTSDIR%%,${FONTSDIR},g' \
			< ${FILESDIR}/$${file}.tmpl > ${WRKSRC}/$${file}; \
	done

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.pcf.gz ${PREFIX}/lib/X11/fonts/local/
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}
	@${INSTALL_DATA} ${WRKSRC}/${RESIZESED_FILE} ${PREFIX}/share/doc/${DISTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/README.${DISTNAME} ${PREFIX}/share/doc/${DISTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/${RESIZED_ALIAS_FILE} ${PREFIX}/share/doc/${DISTNAME}/
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.alias ${PREFIX}/share/doc/${DISTNAME}/
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
