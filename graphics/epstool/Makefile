# New ports collection makefile for:	epstool
# Date created:		23 October 1999
# Whom:			Yuzo FURUKAWA <hurukawa@kuee.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	epstool
PORTVERSION=	3.08
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/ghostgum/ \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/ghostgum/old/
MASTER_SITE_SUBDIR=	nonfree/support/ghostscript/ghostgum

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create or extract preview bitmaps in EPS files

USE_GHOSTSCRIPT_RUN=	yes

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	MAKE="${GMAKE}" GSCDEBUG="" CC="${CC}" CCAUX="${CC}" \
		CLINK="${CC} ${LDFLAGS}" LINK="${CC} ${LDFLAGS}" EPSLIB="" \
		GTKCFLAGS="" GTKLIBS="" LIBPNGCFLAGS="" LIBPNGLIBS=""
ALL_TARGET=	${PORTNAME}

MAN1=		epstool.1
PLIST_FILES=	bin/epstool

.if !defined(NOPORTDOCS)
PORTDOCS=	epstool.htm gsview.css
.endif

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/epstool ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/epstool.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/epstool.htm ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gsview.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
