# New ports collection makefile for:	psgml for emacs
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	psgml-${EMACS_PORT}
PORTVERSION=	${PSGML_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/sgml/
DISTNAME=	psgml-${PSGML_VER}

MAINTAINER?=	shige@FreeBSD.org

# distfile version
PSGML_VER=		1.2.0
PSGML_STARTUPEL=	psgml-startup.el
CATALOG=		${PREFIX}/share/sgml/catalog

# This is a master port.
PORTCLASS?=	master

.if (${PORTCLASS} == "master")
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}
.endif

# if RUN_DEPENDS emacs port name has the suffix `-common'
.if !defined(HAS_COMMON_PORT)
HAS_COMMON_PORT=	NO
.endif

#
# emacs ports setup
#
.if defined(EMACS_PORT)
EMACS_CMD?=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAS_COMMON_PORT) && (${HAS_COMMON_PORT} == "YES")
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--lispdir=${PREFIX}/${EMACS_LIBDIR}/site-lisp/psgml \
		--infodir=${PREFIX}/info
CONFIGURE_ENV=	EMACS=${EMACS_CMD}
MAKE_FLAGS=	EMACS=${EMACS_CMD}
SCRIPTS_ENV=	TARGETS="${PSGML_STARTUPEL}" \
		EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		PSGML_STARTUPEL=${PSGML_STARTUPEL}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR."
	@${FALSE}
.endif

#
# DTD catalogs
#
RUN_DEPENDS+=	${CATALOG}:${PORTSDIR}/textproc/dtd-catalogs

pre-configure:
	(cd ${WRKSRC} ; \
	  for i in psgml.el psgml.texi ; do \
	      ${RM} -f $${i}.in ; \
	      ${MV} $${i} $${i}.in ; \
	      ${CAT} $${i}.in | ${SED} -e "s;@prefix@;${PREFIX};g" > $${i} ; \
	  done)
	${CP} ${FILESDIR}/${PSGML_STARTUPEL}.in ${WRKDIR}

post-install:
	@(cd ${WRKSRC} ; \
		${MAKE} install-info ; \
	)
	@${INSTALL_DATA} ${WRKDIR}/${PSGML_STARTUPEL} \
			${PREFIX}/${EMACS_LIBDIR}/site-lisp

.include <bsd.port.mk>
