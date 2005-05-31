# New ports collection makefile for:	YACL
# Date created:		6 March 1998
# Whom:			Jeroen Hogeveen <albast@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=		yacl
PORTVERSION=		1.7b
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.sc.edu/pub/yacl/
DISTNAME=		yacl-0170-beta

DEPRECATED=		"master site disappeared, no trace under sc.edu"
EXPIRATION_DATE=	2005-07-31

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Portable programming library for C++

NO_WRKSUBDIR=		yes
USE_ZIP=		yes
MAKE_ENV=		YACLPATH=${WRKDIR}

MAKEFILE=		gnuc.mak
ALL_TARGET=		yacl

USE_MOTIF=		true

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile (bad C++ code)"
.endif

post-build:
	@(cd ${WRKSRC}/apps/bmpview; ${MAKE} ${MAKE_ENV} -f gnuc.mak)
	@(cd ${WRKSRC}/apps/dlged; ${MAKE} ${MAKE_ENV} -f gnuc.mak)

do-install:
# don't split up base directory; keep compilation semantics.
	@${MKDIR} ${PREFIX}/lib/yacl ${PREFIX}/share/yacl \
	${PREFIX}/share/yacl/apps ${PREFIX}/share/yacl/base \
	${PREFIX}/include/yacl ${PREFIX}/include/yacl/io \
	${PREFIX}/include/yacl/ui
	@${CP} -R ${WRKSRC}/lib/* ${PREFIX}/lib/yacl
	@${CP} -R ${WRKSRC}/basedemo ${WRKSRC}/contrib ${WRKSRC}/doc \
	${WRKSRC}/control ${WRKSRC}/readme.txt ${WRKSRC}/uidemo \
	${PREFIX}/share/yacl
	@${CP} ${WRKSRC}/base/*.h ${WRKSRC}/base/*.cxx ${PREFIX}/share/yacl/base
	@${CP} ${WRKSRC}/io/*.h ${PREFIX}/include/yacl/io
	@${CP} ${WRKSRC}/ui/*.h ${PREFIX}/include/yacl/ui
	@${CP} ${WRKSRC}/apps/bmpview/bmpview ${WRKSRC}/apps/dlged/dlged \
	${PREFIX}/share/yacl/apps
	@( cd ${PREFIX}/share/yacl; ${LN} -s ${PREFIX}/lib/yacl lib; \
	${LN} -s ${PREFIX}/include/yacl/io; ${LN} -s ${PREFIX}/include/yacl/ui )
	@${ECHO_MSG} "Done. Don't forget to set your YACLPATH environment "
	@${ECHO_MSG} "variable to ${PREFIX}/share/yacl!"

post-install:
	@${STRIP_CMD} ${PREFIX}/share/yacl/apps/bmpview
	@${STRIP_CMD} ${PREFIX}/share/yacl/apps/dlged

.include <bsd.port.post.mk>
