# Created by: maho@FreeBSD.org
# $FreeBSD$

PORTNAME=	garlic
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.zucic.org/sources/garlic-${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Molecular viewer, editor, and visualization program

USES=		gmake
USE_XORG=	x11
ALL_TARGET=	# empty

OPTIONS_DEFINE=	DOCS EXAMPLES OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${DISTNAME}-doc${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${ARCH} == "i386")
CFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3
.endif # i386
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ;\
	s|%%CC%%|${CC}|g ; \
	s|%%CFLAGS%%|${CFLAGS}|g'  ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${DOCSDIR} ${WRKDIR}/doc
	${INSTALL_PROGRAM} ${WRKSRC}/garlic       ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/.garlicrc    ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/residues.pdb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/*.pdb        ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/*.script     ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKDIR}/doc ; \
		${TAR} -xzf ${DISTDIR}/${DISTNAME}-doc${EXTRACT_SUFX} )
	${TAR} -C ${WRKDIR}/doc/${DISTNAME} -cf - .  | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -

.include <bsd.port.mk>
