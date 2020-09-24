# Created by: Yuzo FURUKAWA <hurukawa@kuee.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	epstool
PORTVERSION=	3.09
CATEGORIES=	graphics
MASTER_SITES=	http://www.ghostgum.com.au/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create or extract preview bitmaps in EPS files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		ghostscript:run gmake
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" \
		CCAUX="${CC}" \
		CLINK="${CC} ${LDFLAGS}" \
		EPSLIB="" \
		GSCDEBUG="" \
		GTKCFLAGS="" \
		GTKLIBS="" \
		LIBPNGCFLAGS="" \
		LIBPNGLIBS="" \
		LINK="${CC} ${LDFLAGS}" \
		MAKE="${MAKE_CMD}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/epstool \
		share/man/man1/epstool.1.gz

PORTDOCS=	epstool.htm gsview.css

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/epstool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/epstool.1 ${STAGEDIR}${MANPREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/epstool.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gsview.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
