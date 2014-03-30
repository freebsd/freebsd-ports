# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	uDrawGraph
PORTVERSION=	3.1.1
#PORTREVISION=	0
CATEGORIES=	graphics math
MASTER_SITES=	http://www.informatik.uni-bremen.de/uDrawGraph/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${PKGNUM}-${OPSYS:L}-${ARCH}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A graph drawing/visualization system

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

SUB_FILES=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\..$//}
PKGNUM=		0

FIND_DIRS=	\( -type d -not -empty \)
FIND_EXEC=	\( -type f -perm -a+x \)
FIND_DATA=	-type f \! \( -name "*.win32" -or -name "CHANGES.txt" -or -name "Changelog" -or -name "LICENSE.txt" \)
LICENSES=	LICENSE.txt LIZENZ.txt

LINK_OPTS=	-sf

RESTRICTED=	Binary under GNU LGPL without accompanying source

NO_STAGE=	yes
do-install:
# licenses required at startup
	@cd ${WRKSRC}; \
	${MKDIR} ${DATADIR}; \
	${INSTALL_DATA} ${LICENSES} ${DATADIR}/
# binaries
	@cd ${WRKSRC}/bin; \
	${MKDIR} ${DATADIR}/bin; \
	FILES=$$(${FIND} . ${FIND_EXEC}); \
	for FILE in $${FILES}; do \
		${INSTALL_PROGRAM} $${FILE} ${DATADIR}/bin/$${FILE}; \
	done; \
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME};
## links to executables
	@${LN} ${LINK_OPTS} ${DATADIR}/bin/uDrawGraph ${DATADIR}/bin/daVinci
	@${LN} ${LINK_OPTS} ${DATADIR}/bin/gml2udg ${DATADIR}/bin/gml2daVinci
# data
	@cd ${WRKSRC}; \
	DIRS=$$(${FIND} lib icons ${FIND_DIRS}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${DATADIR}/$${DIR}; \
	done; \
	FILES=$$(${FIND} lib icons ${FIND_DATA}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${DATADIR}/$${FILE}; \
	done;
# examples
	@cd ${WRKSRC}/samples; \
	DIRS=$$(${FIND} . ${FIND_DIRS}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${EXAMPLESDIR}/$${DIR}; \
	done; \
	FILES=$$(${FIND} . ${FIND_DATA}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${EXAMPLESDIR}/$${FILE}; \
	done;
# documentation
.if !defined (NOPORTDOCS)
	@cd ${WRKSRC}/docs; \
	${MKDIR} ${DOCSDIR}; \
	FILES=$$(${FIND} . ${FIND_DATA}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${DOCSDIR}/$${FILE}; \
	done;
# link to docs
	@${LN} ${LINK_OPTS} ${DOCSDIR} ${DATADIR}/docs
.endif

.include <bsd.port.mk>
