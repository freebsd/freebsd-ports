# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	arj
PORTVERSION=	3.10.22
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.78_3.10%20build%2022

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open-source ARJ

OPTIONS_DEFINE=	DOCS

USES=		gmake
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/gnu
CFLAGS+=	-fPIC
MAKEFILE=	GNUmakefile
STRIP=
LANGUAGE?=	en
MAKE_ENV+=	"LOCALE=${LANGUAGE}"

PORTSCOUT=	skipv:3.10g

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's!/etc!${LOCALBASE}/etc!' \
		 ${WRKSRC}/arj.c ${WRKSRC}/file_reg.c ${WRKSRC}/rearj.c
	@${REINPLACE_CMD} -e 's!-O2!!' ${WRKSRC}/gnu/configure.in
	@${REINPLACE_CMD} -e 's!^static !!' ${WRKSRC}/integr.c
	@${REINPLACE_CMD} -e 's!strnlen!_strnlen!g' ${WRKSRC}/fardata.c

pre-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} prepare)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} COPYING debug.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/resource/en && \
		${INSTALL_DATA} arjl.txt arjs.txt history.txt readme.txt unix.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
