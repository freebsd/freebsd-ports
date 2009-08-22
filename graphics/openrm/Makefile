# New ports collection makefile for:	openrm
# Date created:		8 July 2002
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=		openrm
PORTVERSION=		1.6.0
PORTREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION}
DISTNAME=		${PORTNAME}-devel-${PORTVERSION}-1
.ifdef (WITH_DEMOS)
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${PORTNAME}-demo-${PORTVERSION}-1${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Development environment used to build 2D/3D/stereo graphics

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/rm${PORTVERSION:S/.//g}
.ifdef (WITH_DEMOS)
WRKSRC2=	${WRKDIR}/rmdemo
EXTRA_PATCHES=	${PATCHDIR}/makeinclude.diff
.endif

USE_GL=		glu
USE_XORG=	xmu
USE_PERL5_BUILD=yes
ALL_TARGET=	freebsd docs
MAKE_ARGS=	AR=${AR} \
		CC=${CC} \
		CP=${CP} \
		ECHO_CMD=${ECHO_CMD} \
		LN=${LN} \
		RM=${RM} \
		STRIP_CMD=${STRIP_CMD}
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

.if !defined(WITH_DEMOS)
PLIST_SUB=	WITH_DEMOS="@comment "
.else
PLIST_SUB=	WITH_DEMOS=""
.endif

pre-everything::
.ifndef (WITH_DEMOS)
	@${ECHO_MSG} "You can define WITH_DEMOS=yes to fetch and install available demos"
.endif

.ifdef (WITH_DEMOS)
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; \
			      s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC2}/makeinclude
.endif

do-install:
# install libraries
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librm.so.1 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librmaux.so.1 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librmi.so.1 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/librmv.so.1 ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/librm.so.1 ${PREFIX}/lib/librm.so
	${LN} -fs ${PREFIX}/lib/librmaux.so.1 ${PREFIX}/lib/librmaux.so
	${LN} -fs ${PREFIX}/lib/librmi.so.1 ${PREFIX}/lib/librmi.so
	${LN} -fs ${PREFIX}/lib/librmv.so.1 ${PREFIX}/lib/librmv.so
	${INSTALL_DATA} ${WRKSRC}/lib/librm.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/librmaux.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/librmi.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/librmv.a ${PREFIX}/lib

# install includes
	@${MKDIR} ${PREFIX}/include/rm
	${INSTALL_DATA} ${WRKSRC}/include/rm/*.h ${PREFIX}/include/rm

.ifdef (WITH_DEMOS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC2}/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC2}/configure ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC2}/makeinclude ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC2}/Makefile.x11 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC2}/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC2}/*.h ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/data
	${INSTALL_DATA} ${WRKSRC2}/data/* ${EXAMPLESDIR}/data
.endif

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FUTUREPLANS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASENOTES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/*.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/images/* ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
