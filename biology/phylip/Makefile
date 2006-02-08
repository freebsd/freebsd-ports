# New ports collection makefile for:	phylip
# Date created:				4 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	phylip
PORTVERSION=	3.65
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/phylip/ \
		http://bioinformatics.weizmann.ac.il/software/linkage_and_mapping/phylip/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	dbader@ece.unm.edu
COMMENT=	A Phylogeny Inference Package

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}
USE_XLIB=	yes
BUILD_WRKSRC=	${WRKSRC}/src

MAKE_ARGS=	CC="${CC} ${CFLAGS}" \
		DC="${CC} -DX -I${X11BASE}/include ${CFLAGS}" \
		GLIBS="-L${X11BASE}/lib -lX11 -lm"

PORTDOCS=	*

do-install:
	@cd ${BUILD_WRKSRC} && ${MAKE} install

	@cd ${WRKSRC}/exe && \
		${FIND} . -not -type d -not -name 'font*' -exec ${INSTALL_PROGRAM} "{}" "${PREFIX}/bin/{}" \;

	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/exe && \
		${FIND} . -not -type d -name 'font*' -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
