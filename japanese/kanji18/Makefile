# New ports collection makefile for:	kanji18
# Date created:		23 November 1999
# Whom:			Yoshiro MIHIRA <sanpei@sanpei.org>
#
# $FreeBSD$
#

PORTNAME=	kanji
PORTVERSION?=	1.0
PKGNAMESUFFIX?=	18
CATEGORIES=	japanese x11-fonts
MASTER_SITES=   ${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	${DISTNAME}
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}
DISTFILES?=	573.z 574.z 575.z 576.z 577.z 578.z 579.z 580.z 581.z

MAINTAINER=	sanpei@FreeBSD.org

BUILD_DEPENDS=	gunshar:${PORTSDIR}/archivers/gshar+gunshar

DIST_SUBDIR=	${DISTNAME}
FONTSDIR=	lib/X11/fonts/local
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

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
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

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

.include <bsd.port.post.mk>
