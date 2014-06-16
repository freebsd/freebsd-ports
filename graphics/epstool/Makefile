# Created by: Yuzo FURUKAWA <hurukawa@kuee.kyoto-u.ac.jp>
# $FreeBSD$

PORTNAME=	epstool
PORTVERSION=	3.08
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Create or extract preview bitmaps in EPS files

LICENSE=	GPLv2

USE_GHOSTSCRIPT_RUN=	yes

USES=		gmake
MAKEFILE=	makefile
MAKE_ARGS=	MAKE="${GMAKE}" GSCDEBUG="" CC="${CC}" CCAUX="${CC}" \
		CLINK="${CC} ${LDFLAGS}" LINK="${CC} ${LDFLAGS}" EPSLIB="" \
		GTKCFLAGS="" GTKLIBS="" LIBPNGCFLAGS="" LIBPNGLIBS=""
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/epstool man/man1/epstool.1.gz

.if !defined(NOPORTDOCS)
PORTDOCS=	epstool.htm gsview.css
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/epstool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/epstool.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/epstool.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gsview.css ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
