# New ports collection makefile for:	psgml for emacs
# Date created:		23 January 1999
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	psgml
PORTVERSION=	${PSGML_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/sgml/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	psgml
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	shige@FreeBSD.org

# distfile version
PSGML_VER=		1.2.4
PSGML_STARTUPEL=	psgml-startup.el

SCRIPTS_ENV=		TARGETS="${PSGML_STARTUPEL}"
PLIST_SUB=		PSGML_STARTUPEL=${PSGML_STARTUPEL}

# This is a master port.
PORTCLASS?=	master

.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs21
.endif

.include <bsd.port.pre.mk>

#
# emacs ports setup
#
.if defined(EMACS_PORT_NAME)
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--lispdir=${LOCALBASE}/${EMACS_LIBDIR}/site-lisp/psgml \
		--infodir=${LOCALBASE}/info
CONFIGURE_ENV=	EMACS=${EMACS_CMD}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

pre-configure:
	(cd ${WRKSRC} ; \
	  for i in psgml.el psgml.texi ; do \
	      ${RM} -f $${i}.in; \
	      ${MV} $${i} $${i}.in; \
	      ${CAT} $${i}.in | ${SED} -e "s;@prefix@;${LOCALBASE};g" > $${i}; \
	  done)
	${CP} ${FILESDIR}/${PSGML_STARTUPEL}.in ${WRKDIR}

post-install:
	@(cd ${WRKSRC} ; \
		${MAKE} install-info ; \
	)
	@${INSTALL_DATA} ${WRKDIR}/${PSGML_STARTUPEL} \
			${LOCALBASE}/${EMACS_LIBDIR}/site-lisp

.include <bsd.port.post.mk>
