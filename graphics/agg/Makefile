# ex:ts=8
# Ports collection makefile for:	agg
# Date created:			Aug 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	agg
PORTVERSION=	2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vector-agg
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A High Quality Rendering Engine for C++

WRKSRC=		${WRKDIR}/agg2
USE_GMAKE=	yes
MAKE_ENV=	C=${CC}

PLIST_FILES=	lib/libagg.a

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

post-extract:
	@${CP} -f ${FILESDIR}/Makefile.in.FreeBSD ${WRKSRC}
	@${SED} 's,%%X11BASE%%,${X11BASE},g' < ${FILESDIR}/Makefile.in.FreeBSD > ${WRKSRC}/Makefile.in.FreeBSD

do-build:
	@cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} all && ranlib libagg.a

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libagg.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/agg
	${CP} -R ${WRKSRC}/include/ ${PREFIX}/include/agg
	@${FIND} ${PREFIX}/include/agg ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/agg -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
