# New ports collection makefile for:	lookup for Mule 2.3
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lookup
PORTVERSION=	1.4
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/lookup/dist/

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	Search interface on ${EMACS_PORT_NAME} for CD-ROM books, etc

RUN_DEPENDS+=	eblook:${PORTSDIR}/japanese/eblook

FILESDIR=	${.CURDIR}/../lookup/files
PKGDIR=		${.CURDIR}/../lookup
PLIST=		${.CURDIR}/pkg-plist
EMACS_PORT_NAME?=	emacs21

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
EMACSDIR=	${PREFIX}/lib/xemacs/site-packages
ELISPDIR=	${EMACSDIR}/lisp/lookup
PORTINFODIR=	${EMACSDIR}/info
MANIFEST=	MANIFEST.lookup
.else
ELISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/lookup
PORTINFODIR=	${PREFIX}/info
PLIST_SUB=	ELISPDIR=${EMACS_VERSION_SITE_LISPDIR}
.endif
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --with-emacs=${EMACS_CMD} \
		--with-lispdir=${ELISPDIR} \
		--infodir=${PORTINFODIR}

post-install:
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
	${RM} -f ${WRKDIR}/${MANIFEST}
	emacsdir=`${ECHO_CMD} ${EMACSDIR} | ${SED} -e "s;^${PREFIX}/;;"`; \
	${CAT} ${PLIST} | ${GREP} -e "^$${emacsdir}" | \
		${SED} -e "s;^$${emacsdir}/;;" > ${WRKDIR}/${MANIFEST}
	${MKDIR} ${EMACSDIR}/pkginfo
	${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${EMACSDIR}/pkginfo/
.endif

.include <bsd.port.mk>
