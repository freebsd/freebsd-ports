# New ports collection makefile for:	YACL
# Version required:     1.7-beta
# Date created:		6 March 1998
# Whom:			Jeroen Hogeveen <albast@xs4all.nl>
#
# $Id$
#

DISTNAME=		yacl-0170-beta
PKGNAME=		yacl-1.7b
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.sc.edu/pub/yacl/
EXTRACT_SUFX=		.zip

MAINTAINER=		albast@xs4all.nl

BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-qq -La
WRKSRC=			${WRKDIR}
MAKE_ENV=		YACLPATH=${WRKDIR}

MAKEFILE=		gnuc.mak
ALL_TARGET=		yacl

REQUIRES_MOTIF=		true

post-build:
	@(cd ${WRKSRC}/apps/bmpview; YACLPATH=${WRKDIR} $(MAKE) -f gnuc.mak)
	@(cd ${WRKSRC}/apps/dlged; YACLPATH=${WRKDIR} $(MAKE) -f gnuc.mak)

do-install:
# don't split up base directory; keep compilation semantics.
	@mkdir -p ${PREFIX}/lib/yacl ${PREFIX}/share/yacl \
	${PREFIX}/share/yacl/apps ${PREFIX}/share/yacl/base \
	${PREFIX}/include/yacl ${PREFIX}/include/yacl/io \
	${PREFIX}/include/yacl/ui
	@cp -R ${WRKSRC}/lib/* ${PREFIX}/lib/yacl
	@cp -R ${WRKSRC}/basedemo ${WRKSRC}/contrib ${WRKSRC}/doc \
	${WRKSRC}/control ${WRKSRC}/readme.txt ${WRKSRC}/uidemo \
	${PREFIX}/share/yacl
	@cp ${WRKSRC}/base/*.h ${WRKSRC}/base/*.cxx ${PREFIX}/share/yacl/base
	@cp ${WRKSRC}/io/*.h ${PREFIX}/include/yacl/io
	@cp ${WRKSRC}/ui/*.h ${PREFIX}/include/yacl/ui
	@cp ${WRKSRC}/apps/bmpview/bmpview ${WRKSRC}/apps/dlged/dlged \
	${PREFIX}/share/yacl/apps
	@( cd ${PREFIX}/share/yacl; ln -s ${PREFIX}/lib/yacl lib; \
	ln -s ${PREFIX}/include/yacl/io; ln -s ${PREFIX}/include/yacl/ui )
	@${ECHO} "Done. Don't forget to set your YACLPATH environment "
	@${ECHO} -n "variable to "; ${ECHO} -n ${PREFIX}; ${ECHO} "/share/yacl!"

post-install:
	@strip ${PREFIX}/share/yacl/apps/bmpview
	@strip ${PREFIX}/share/yacl/apps/dlged

.include <bsd.port.mk>
