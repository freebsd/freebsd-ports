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

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	MAKE="${GMAKE}" GSCDEBUG="" CC="${CC}" CCAUX="${CC}" \
		CLINK="${CC} ${LDFLAGS}" LINK="${CC} ${LDFLAGS}" EPSLIB="" \
		GTKCFLAGS="" GTKLIBS="" LIBPNGCFLAGS="" LIBPNGLIBS=""
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_UNSAFE=	yes

MAN1=		epstool.1
PLIST_FILES=	bin/epstool

.if !defined(NOPORTDOCS)
PORTDOCS=	epstool.htm gsview.css
.endif

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/epstool ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/epstool.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/epstool.htm ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gsview.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
