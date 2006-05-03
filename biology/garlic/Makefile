# New ports collection makefile for:    garlic
# Date created:         28 July 2003
# Whom:                 maho@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	garlic
PORTVERSION=	1.5
CATEGORIES=	biology
MASTER_SITES=	http://garlic.mefos.hr/sources/garlic-${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	${DISTNAME}-doc${EXTRACT_SUFX}
.endif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Molecular viewer, editor and visualization program

USE_XLIB=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${ARCH} == "i386")
CFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3
.endif # i386
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g ; \
	s|%%LOCALBASE%%|${LOCALBASE}|g ;\
	s|%%CC%%|${CC}|g ; \
	s|%%CFLAGS%%|${CFLAGS}|g'  ${WRKSRC}/Makefile
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/garlic       ${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/.garlicrc    ${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/residues.pdb ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA}    ${WRKSRC}/*.pdb        ${EXAMPLESDIR}
	@${INSTALL_DATA}    ${WRKSRC}/*.script     ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${WRKDIR}/doc
	@(cd ${WRKDIR}/doc ; ${TAR} xfz ${DISTDIR}/${DISTNAME}-doc${EXTRACT_SUFX} )
	@${TAR} -C ${WRKDIR}/doc/${DISTNAME} -cf - .  | \
		${TAR} -C ${DOCSDIR} -xf -
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>
