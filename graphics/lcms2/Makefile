# New ports collection makefile for:	lcms2
# Date created:		12/04/2010
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	lcms2
PORTVERSION=	2.2
CATEGORIES=	graphics
MASTER_SITES=	SF/lcms/lcms/${PORTVERSION} \
		http://www.littlecms.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light Color Management System -- a color management library

USE_GNOME=	gnomehack lthack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes
WITH_FBSD10_FIX=	yes

OPTIONS=	TIFFICC "Build color profile applier for TIFF" off \
		JPEGICC "Build color profile applier for JPEG" off

UTILS=		transicc psicc linkicc
MAN1=		transicc.1 psicc.1 linkicc.1

.include <bsd.port.pre.mk>

.if defined(WITH_TIFFICC)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFFICC=""
MAN1+=		tificc.1
UTILS+=		tificc
.else
CONFIGURE_ARGS=	--without-tiff
PLIST_SUB+=	TIFFICC="@comment "
.endif

.if defined(WITH_JPEGICC)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEGICC=""
MAN1+=		jpgicc.1
UTILS+=		jpgicc
.else
CONFIGURE_ARGS=	--without-jpeg
PLIST_SUB+=	JPEGICC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^SUBDIRS =.*$$|SUBDIRS = src include|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O3||g' ${WRKSRC}/src/Makefile.in

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	    '/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

post-build:
.for DIR in ${UTILS}
	@(cd ${WRKSRC}/utils/${DIR} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} Makefile all)
.endfor

post-install:
.for DIR in ${UTILS}
	@(cd ${WRKSRC}/utils/${DIR} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} Makefile install)
.endfor
	${INSTALL_MAN}  ${WRKSRC}/utils/linkicc/linkicc.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_MAN}  ${WRKSRC}/utils/psicc/psicc.1 ${MAN1PREFIX}/man/man1/
	${INSTALL_MAN}  ${WRKSRC}/utils/transicc/transicc.1 ${MAN1PREFIX}/man/man1/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
.endif

test:
	cd ${WRKSRC}/testbed && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
