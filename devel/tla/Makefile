# Ports collection makefile for:	tla
# Date Created:			August 17th, 2003
# Whom:				seanc
#
# $FreeBSD$
#

PORTNAME=	tla
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://regexps.srparish.net/src/${PORTNAME}/ \
		http://arch.quackerhead.com/~lord/releases/${PORTNAME}/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	The original arch source control management CLI written in C

RUN_DEPENDS=	gpatch:${PORTSDIR}/devel/patch \
		gdiff:${PORTSDIR}/textproc/diffutils
BUILD_DEPENDS=	gdiff:${PORTSDIR}/textproc/diffutils

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

ORIGWRKSRC=	${WRKDIR}/${DISTNAME}/src
WRKSRC=		${ORIGWRKSRC}/=build

pre-configure:
	${MKDIR} ${WRKSRC}

do-configure:
	cd ${WRKSRC} ; ../configure --prefix ${LOCALBASE} \
			--with-gnu-patch gpatch \
			--with-gnu-diff gdiff \
			--with-gnu-diff3 gdiff3

test:
	cd ${WRKSRC} ; ${GMAKE} test

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}; \
	for f in `${FIND} ${ORIGWRKSRC}/docs-tla/html -type f -name '*.html' \
		-exec ${BASENAME} {} \;`; do \
		${INSTALL_DATA} ${ORIGWRKSRC}/docs-tla/html/$$f ${DOCSDIR}/; \
		printf "share/doc/${PORTNAME}/%s\n" $$f >> ${TMPPLIST}; \
	done; \
	${ECHO} @dirrm share/doc/${PORTNAME} >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
