# $FreeBSD$

PORTNAME=	kpathsea
PORTVERSION=	6.2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150521-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Path searching library for TeX

USES=		libtool pathfix tar:xz
USE_LDCONFIG=	yes
USE_TEX=	yes
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		texk/kpathsea \
		texk/texlive/tl_scripts
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

INFO=		kpathsea

post-install:
	cd ${WRKDIR}/${DISTNAME}/texk/texlive/tl_scripts && \
	    for f in kpsetool kpsewhere; do \
		${INSTALL_SCRIPT} $${f}.sh ${STAGEDIR}${PREFIX}/bin/$$f; \
		${INSTALL_MAN} $${f}.1 \
		    ${STAGEDIR}${MANPREFIX}/man/man1/$${f}.1; \
	    done; \
	    for l in kpsexpand kpsepath; do \
		${LN} -sf kpsetool ${STAGEDIR}${PREFIX}/bin/$$l; \
		${LN} -sf kpsetool.1 ${STAGEDIR}${MANPREFIX}/man/man1/$${l}.1; \
	    done

.include <bsd.port.mk>
