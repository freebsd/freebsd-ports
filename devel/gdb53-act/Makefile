# Ports collection makefile for:	GDB 5.3-act
# Date created:				8 August 2003
# Whom:					John R. Shannon <john@johnrshannon.com>
#
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=    5.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-act

MAINTAINER=	john@johnrshannon.com
COMMENT=	GDB 5.3 modified by ACT for Ada programming language

PLIST_FILES=	bin/gdbada
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=ada
CONFIGURE_ARGS+=	--disable-nls

SNAPDATE=	2003-09-03
CVS_DATE=	${SNAPDATE} 12:44:04 GMT
.if defined(CVS_DATE)
NO_CHECKSUM=	yes
DIST_SUBDIR=	${PKGNAME}
CVS_CMD?=	cvs -z3 -qR
CVSROOT=	:pserver:anoncvs@libre.act-europe.fr:/anoncvs
STAMPFILE=	${DISTDIR}/${DIST_SUBDIR}/.timestamp
do-fetch:
	@if [ ! -e ${WRKDIR}/.extract_done ] ; then \
		if [ ! -e ${STAMPFILE} ] ; then \
			${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
			cd ${DISTDIR}/${DIST_SUBDIR} ; \
			unset CVS_RSH CVS_SERVER || ${TRUE} ; \
			${ECHO_MSG} ">> Attempting to CVS checkout from ${CVSROOT}." ;\
			if ${CVS_CMD} -d ${CVSROOT} co -P gdb-5.3 ; \
			then \
				( ${ECHO} -n "${CVS_DATE}" > ${STAMPFILE} ) ; \
				exit ; \
			fi ; \
			${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}." ; \
			${ECHO_MSG} ">> Please try again later."; \
			exit 1; \
		else \
			if [ "X${CVS_DATE}" != "X$$(${CAT} ${STAMPFILE})" ]; then \
			cd ${DISTDIR}/${DIST_SUBDIR} ; \
			unset CVS_RSH CVS_SERVER || ${TRUE} ; \
			${ECHO_MSG} ">> Attempting to CVS update from ${CVSROOT}." ;\
			if ${CVS_CMD} -d ${CVSROOT} up -Pd gdb-5.3 ; \
			then \
				( ${ECHO} -n "${CVS_DATE}" > ${STAMPFILE} ) ; \
				exit ; \
			fi ; \
			${ECHO_MSG} ">> Couldn't CVS checkout ${PKGNAME}." ; \
			${ECHO_MSG} ">> Please try again later."; \
			exit 1; \
			fi; \
		fi; \
	fi;

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR}/gdb-5.3 ; ${PAX} -pe -rwt . ${WRKSRC}
.endif	# CVS_DATE

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/gdbada

.include <bsd.port.mk>
