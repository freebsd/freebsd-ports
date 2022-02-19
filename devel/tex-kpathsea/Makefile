PORTNAME=	kpathsea
PORTVERSION=	6.3.3
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Path searching library for TeX

LICENSE=	LGPL21+

USES=		libtool pathfix tar:xz
USE_LDCONFIG=	yes
USE_TEX=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux texk/kpathsea texk/texlive/tl_support \
		texk/texlive/linked_scripts/texlive-extra \
		texk/texlive/linked_scripts/texlive

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea

INFO=		kpathsea

post-install:
	(cd ${WRKDIR}/${DISTNAME}/texk/texlive/linked_scripts/texlive-extra && \
	    for f in kpsetool kpsewhere; do \
		${INSTALL_SCRIPT} $${f}.sh ${STAGEDIR}${PREFIX}/bin/$$f; \
		${INSTALL_MAN} ../../tl_support/$${f}.1 \
		    ${STAGEDIR}${MANPREFIX}/man/man1/$${f}.1; \
	    done; \
	    for l in kpsexpand kpsepath; do \
		${LN} -sf kpsetool ${STAGEDIR}${PREFIX}/bin/$$l; \
		${LN} -sf kpsetool.1 ${STAGEDIR}${MANPREFIX}/man/man1/$${l}.1; \
	    done)

.include <bsd.port.mk>
