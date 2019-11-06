# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	EZWGL
PORTVERSION=	1.50
PORTREVISION=	9
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTFILES=	${DISTNAME}-demo.tgz ${DISTNAME}-doc.tgz ${DISTNAME}-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EZ Widget and Graphics Library

BROKEN=		unfetchable

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	does not compile on sparc64

USES=		localbase xorg
USE_XORG=	x11 xext
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

NOPRECIOUSMAKEVARS=	yes # Otherwise 'make readmes' is broken

OPTIONS_DEFINE=	DOCS EXAMPLES

.include "Makefile.manlinks"

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -r

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/EZ.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libEZ.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libEZ.so.1 ${STAGEDIR}${PREFIX}/lib
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libEZ.so.1 libEZ.so)
	${INSTALL_MAN} ${WRKSRC}/doc/man3/*.3 ${STAGEDIR}${MANPREFIX}/man/man3

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR} "! -name Makefile.in")
	(cd ${WRKSRC} && ${COPYTREE_SHARE} demos \
		${STAGEDIR}${EXAMPLESDIR} "! -name Makefile.in")

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ps
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR} "! -empty")
	${INSTALL_DATA} ${WRKSRC}/doc/ps/*.ps ${STAGEDIR}${DOCSDIR}/ps

post-install: install-manlinks

.include <bsd.port.mk>
