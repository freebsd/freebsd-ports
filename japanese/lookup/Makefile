# New ports collection makefile for:	lookup for Mule 2.3
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lookup
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/lookup/dist/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search interface on ${EMACS_PORT_NAME} for CD-ROM books, etc

USE_EMACS=	yes

INFO?=		lookup lookup-guide

.include <bsd.port.pre.mk>

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
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${ELISPDIR}

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

.include <bsd.port.post.mk>
