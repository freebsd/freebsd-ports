# Created by: maho@FreeBSD.org
# $FreeBSD$

PORTNAME=	garlic
PORTVERSION=	1.6
CATEGORIES=	biology
MASTER_SITES=	http://www.zucic.org/sources/garlic-${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}-doc${EXTRACT_SUFX}
.endif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Molecular viewer, editor, and visualization program

USES=		gmake
USE_XORG=	x11
ALL_TARGET=	# empty

OPTIONS_DEFINE=	DOCS EXAMPLES OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

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
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/garlic       ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/.garlicrc    ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/residues.pdb ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/*.pdb        ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}    ${WRKSRC}/*.script     ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${WRKDIR}/doc
	(cd ${WRKDIR}/doc ; ${TAR} xfz ${DISTDIR}/${DISTNAME}-doc${EXTRACT_SUFX} )
	${TAR} -C ${WRKDIR}/doc/${DISTNAME} -cf - .  | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -
	${FIND} ${STAGEDIR}${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${STAGEDIR}${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
