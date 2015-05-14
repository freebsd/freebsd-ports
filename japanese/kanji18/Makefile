# Created by: Yoshiro MIHIRA <sanpei@sanpei.org>
# $FreeBSD$

PORTNAME=	kanji
PORTVERSION?=	1.0
PORTREVISION?=	6
CATEGORIES=	japanese x11-fonts
MASTER_SITES=   PORTS_JP/${DISTNAME}
PKGNAMESUFFIX?=	18
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}
DISTFILES?=	573.z 574.z 575.z 576.z 577.z 578.z 579.z 580.z 581.z

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	X11 ${PKGNAMESUFFIX}-dot Kanji font

USES=		fonts
EXTRACT_DEPENDS=	gunshar:${PORTSDIR}/archivers/sharutils
BUILD_DEPENDS=	mkbold:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

DIST_SUBDIR=	${DISTNAME}
NO_WRKSUBDIR=	yes

EXTRACT_CMD=		${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${AWK} '/bin\/sh/{P=1} {if (P==1) print;}' | \
			${LOCALBASE}/bin/gunshar -d $(WRKDIR)
PKGINSTALL=	${WRKSRC}/INSTALL
PKGDEINSTALL=	${WRKSRC}/DEINSTALL
MAKE_ENV=	FONTSDIR=${FONTSDIR:S,${PREFIX},,}
README_FILE?=	573.z
RESIZESED_FILE?=	18to16.sed
RESIZED_ALIAS_FILE?=	kanji16.alias

OPTIONS_DEFINE=	DOCS

post-extract:
	@(cd $(WRKSRC); ${CAT} ${DISTNAME}.?? | uudecode)
	@${CP} -p ${FILESDIR}/Makefile.in ${WRKDIR}/Makefile
	@${GUNZIP_CMD} ${WRKDIR}/*.Z

post-patch:
	@(${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${README_FILE} \
		| ${AWK} '/^#! \/bin\/sh/{i=1} i==0{print}' \
		> ${WRKSRC}/README.${DISTNAME})

pre-install:
	@for file in INSTALL DEINSTALL; do \
		${SED} -e 's,%%FONTSDIR%%,${FONTSDIR},g' \
		       -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
			< ${FILESDIR}/$${file}.tmpl > ${WRKSRC}/$${file}; \
	done

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/${RESIZESED_FILE} ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/README.${DISTNAME} ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/${RESIZED_ALIAS_FILE} ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.alias ${STAGEDIR}${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
