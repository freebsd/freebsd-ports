# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lookup
PORTVERSION=	1.4.1
PORTREVISION=	16
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/lookup/dist/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	Search interface on ${EMACS_PORT_NAME} for CD-ROM books, etc

LICENSE=	GPLv2

USE_EMACS=	yes

INFO?=		lookup lookup-guide

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
EMACSDIR=	${PREFIX}/lib/xemacs/site-packages
ELISPDIR=	${EMACSDIR}/lisp/lookup
MANIFEST=	MANIFEST.lookup
.else
ELISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/lookup
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
