# Ports collection makefile for:	ace+tao-doc
# Date created:				9 January 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	ace+tao-doc
PORTVERSION=	5.4.0
CATEGORIES=	devel
MASTER_SITES=	http://deuce.doc.wustl.edu/old_distribution/ \
		http://www.navicon.dk/mirrors/ace/deuce.doc.wustl.edu/old_distribution/
DISTNAME=	ACE-${PORTVERSION:C/\.0$//}-html

MAINTAINER=	sem@FreeBSD.org
COMMENT=	The ACE+TAO HTML documentation

WRKSRC=		${WRKDIR}/html
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist
DIRLIST=	${WRKDIR}/dir-list
INSTALL_DIR=	share/doc/${PORTNAME}

pre-install:
	@${ECHO_MSG} "--> Generating a directories list"; \
	cd ${WRKSRC}; \
	${RM} -f ${PLIST}; ${ECHO_CMD} "@dirrm ${INSTALL_DIR}" > ${DIRLIST}; \
	for d in `${FIND} . -type d`; do \
		n=`${ECHO_CMD} $${d}|${SED} -e 's#^./##'`; \
		if [ "$${n}" != "." ]; then \
			${ECHO_CMD} "@dirrm ${INSTALL_DIR}/$$n" >> ${DIRLIST}; \
		fi; \
	done; \
	${ECHO_MSG} "--> Generating a files list"; \
	for f in `${FIND} -s . -type f`; do \
		n=`${ECHO_CMD} $${f}|${SED} -e 's#^./##'`; \
		${ECHO_CMD} ${INSTALL_DIR}/$${n} >> ${PLIST}; \
	done; \
	${SORT} -r ${DIRLIST} >> ${PLIST}

do-install:
	@${ECHO_MSG} "--> Installing files:"; \
	${MKDIR} ${DOCSDIR}; cd ${WRKSRC}; \
	for d in `${FIND} . -type d`; do \
		n=`${ECHO_CMD} $${d}|${SED} -e 's#^./##'`; \
		if [ "$${n}" != "." ]; then \
			${MKDIR} ${DOCSDIR}/$${n}; \
		fi; \
	done; \
	for f in `${FIND} -s . -type f`; do \
		n=`${ECHO_CMD} $${f}|${SED} -e 's#^./##'`; \
		${ECHO_MSG} $${n}; \
		${INSTALL_DATA} $${n} ${DOCSDIR}/$${n}; \
	done

.include <bsd.port.mk>
