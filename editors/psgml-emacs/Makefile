# New ports collection makefile for:	psgml for emacs
# Version required:	1.1.6
# Date created:		23 January 1999
# Whom:			shige
#
# $Id$
#

DISTNAME=	psgml-1.1.6
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/sgml/ALPHA/

MAINTAINER?=	shige@kuis.kyoto-u.ac.jp

# distfile version
PSGML_VER=	1.1.6
PSGML_SETUPEL=  psgml-setup.el
CATALOG=	${PREFIX}/share/sgml/catalog
INFILES=	${PSGML_SETUPEL}

# This is a master port.
PORTCLASS?=	master

.if (${PORTCLASS} == "master")
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}
REQUIRE_SETUPEL=  YES
.endif

# if RUN_DEPENDS emacs port name has the suffix `-common'
.if !defined(HAVE_COMMON_PORT)
HAVE_COMMON_PORT=	NO
.endif
# if RUN_DEPENDS emacs needs setup elisp
.if !defined(REQUIRE_SETUPEL)
REQUIRE_SETUPEL=	NO
.endif

#
# emacs ports setup
#
.if defined(EMACS_PORT)
PKGNAME=	psgml-${EMACS_PORT}-${PSGML_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
CONFIGURE_ENV=	EMACS=${EMACS_CMD}
MAKE_FLAGS=	EMACS=${EMACS_CMD}
SCRIPTS_ENV=	INFILES=${INFILES} \
		EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR."
	@${FALSE}
.endif

#
# main configurations
#
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs="${EMACS_CMD}"
RUN_DEPENDS+=	${CATALOG}:${PORTSDIR}/textproc/dtd-catalogs

pre-configure:
	(cd ${WRKSRC} ; \
	  for i in psgml.el psgml.texi ; do \
	      ${RM} -f $${i}.in ; \
	      ${MV} $${i} $${i}.in ; \
	  done)
.if (${REQUIRE_SETUPEL} == "YES")
	${CP} ${FILESDIR}/${PSGML_SETUPEL}.in ${WRKDIR}
.endif

pre-build:
	@${RM} -f ${WRKSRC}/psgml.info ${WRKSRC}/psgml-api.info

post-install:
.if (${REQUIRE_SETUPEL} == "YES")
	@${INSTALL_DATA} ${WRKDIR}/${PSGML_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif

.include <bsd.port.mk>
