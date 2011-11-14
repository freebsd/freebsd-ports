# New ports collection makefile for:	Little CMS (v2)
# Date created:				12/04/2010
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lcms2
PORTVERSION=	2.2
CATEGORIES=	graphics
MASTER_SITES=	SF/lcms/lcms/${PORTVERSION} \
		http://www.littlecms.com/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Accurate, fast, and small-footprint color management engine

LICENSE=	MIT

USE_GNOME=	gnomehack lthack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS=	TIFFICC "Build color profile applier for TIFF" off \
		JPEGICC "Build color profile applier for JPEG" off

UTILS=		transicc psicc linkicc
MAN1=		transicc.1 psicc.1 linkicc.1

.include <bsd.port.pre.mk>

.if defined(WITH_TIFFICC)
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
UTILS+=		tificc
MAN1+=		tificc.1
PLIST_FILES+=	bin/tificc
.else
CONFIGURE_ARGS=	--without-tiff
.endif

.if defined(WITH_JPEGICC)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
UTILS+=		jpgicc
MAN1+=		jpgicc.1
PLIST_FILES+=	bin/jpgicc
.else
CONFIGURE_ARGS=	--without-jpeg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^SUBDIRS =.*$$|SUBDIRS = src include|' \
		${WRKSRC}/Makefile.in

post-configure:
# Get rid of .la and static library files
	@${REINPLACE_CMD} -E -e \
		'/Install the pseudo-library/,/staticlibs=/s,^,#,' \
			${WRKSRC}/libtool

post-build:
.for dir in ${UTILS}
	@cd ${WRKSRC}/utils/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} all
.endfor

post-install:
.for dir in ${UTILS}
	@cd ${WRKSRC}/utils/${dir} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} install
.endfor
	${INSTALL_MAN} ${WRKSRC}/utils/linkicc/linkicc.1 \
		${WRKSRC}/utils/psicc/psicc.1 \
		${WRKSRC}/utils/transicc/transicc.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
.endif

test:	build
	@cd ${WRKSRC}/testbed && ${SETENV} ${MAKE_ENV} ${MAKE} check

regression-test:	test

.include <bsd.port.post.mk>
