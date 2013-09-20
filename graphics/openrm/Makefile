# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	openrm
PORTVERSION=	1.6.0.2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION:R} \
		SF/${PORTNAME}/${PORTNAME}-demo/${PORTVERSION:R}:demo
DISTNAME=	${PORTNAME}-devel-${PORTVERSION:R}-${PORTVERSION:E}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DEMO_DISTFILE:S/$/:demo/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Development environment used to build 2D/3D/stereo graphics

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/rm${PORTVERSION:R:S/.//g}

USES=		shebangfix perl5
SHEBANG_FILES=	doc/*.pl
USE_GL=		glu
USE_XORG=	xmu
USE_PERL5=	build
ALL_TARGET=	freebsd docs
MAKE_ARGS=	AR="${AR}" \
		CC="${CC}" \
		CP="${CP}" \
		ECHO_CMD="${ECHO_CMD}" \
		LN="${LN}" \
		RM="${RM}" \
		STRIP_CMD="${STRIP_CMD}" \
		X11BASE="${LOCALBASE}"
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-fPIC -DPIC

PORTDOCS=	*
PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
DEMO_DISTFILE=	${DISTNAME:S,-devel-,-demo-,}${EXTRACT_SUFX}
DEMO_WRKSRC=	${WRKDIR}/rmdemo
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
.if ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e \
		'/^RM/s|/usr|${PREFIX}| ; \
		 /^OPENGL/s|/usr|${LOCALBASE}| ; \
		 /^X11/s|/usr/X11R6|${LOCALBASE}| ; \
		 /^X11/s|-lpthread|${PTHREAD_LIBS}| ; \
		 /^OPT/s|-g|| ; \
		 /^ARCH/s|-m32|| ; \
		 /^JPEG/s|/usr|${LOCALBASE}|' ${DEMO_WRKSRC}/makeinclude
.endif

do-install:
# install includes
	@${MKDIR} ${PREFIX}/include/rm
	${INSTALL_DATA} ${WRKSRC}/include/rm/*.h ${PREFIX}/include/rm
# install libraries
.for f in librm librmaux librmi librmv
	${INSTALL_DATA} ${WRKSRC}/lib/${f}.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/${f}.so.1 ${PREFIX}/lib
	${LN} -fs ${f}.so.1 ${PREFIX}/lib/${f}.so
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FUTUREPLANS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASENOTES ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/HTML
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/*.html ${DOCSDIR}/HTML
	@${MKDIR} ${DOCSDIR}/HTML/images
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/images/* ${DOCSDIR}/HTML/images
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DEMO_WRKSRC}/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${DEMO_WRKSRC}/configure ${EXAMPLESDIR}
	${INSTALL_DATA} ${DEMO_WRKSRC}/makeinclude ${EXAMPLESDIR}
	${INSTALL_DATA} ${DEMO_WRKSRC}/Makefile.x11 ${EXAMPLESDIR}
	${INSTALL_DATA} ${DEMO_WRKSRC}/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${DEMO_WRKSRC}/*.h ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/data
	${INSTALL_DATA} ${DEMO_WRKSRC}/data/* ${EXAMPLESDIR}/data
.endif

.include <bsd.port.post.mk>
