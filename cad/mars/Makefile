# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	mars
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/sdag/MaRS/
DISTNAME=	MaRS-${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Maryland Routing Simulator

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

DOCS_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} MaRS-2-doc${EXTRACT_SUFX}

MAKE_JOBS_UNSAFE=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USES+=		motif
MAKEFILE=	Makefile.XMotif
.else
MAKEFILE=	Makefile.NoX
.endif
ALL_TARGET=	depend mars
MAN1=		mars.1

post-configure:
	@${REINPLACE_CMD} -e 's/INFINITY/MARS_INFINITY/g' \
		${WRKSRC}/include/route.h \
		${WRKSRC}/comps/exBF.c \
		${WRKSRC}/comps/exBF_ack.c \
		${WRKSRC}/comps/route.c \
		${WRKSRC}/comps/segal.c \
		${WRKSRC}/comps/spf.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mars ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/mars.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/mars
	@${CHMOD} a+rx ${PREFIX}/share/doc/mars
	@(cd ${PREFIX}/share/doc ; \
		${TAR} xfpz /${DISTDIR}/MaRS-2-doc${EXTRACT_SUFX} ; \
		[ -d mars ] && ${RM} -rf mars; \
		${MV} doc mars )
.endif

.include <bsd.port.mk>
