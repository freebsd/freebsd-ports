# New ports collection makefile for:	lookup for Mule 2.3
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lookup
PORTVERSION=	1.3
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
CATEGORIES=	japanese elisp
MASTER_SITES=	http://download.sourceforge.net/lookup/

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS+=	eblook:${PORTSDIR}/japanese/eblook

FILESDIR=	${.CURDIR}/../lookup-mule/files
PKGDIR=		${.CURDIR}/../lookup-mule
PLIST=		${.CURDIR}/pkg-plist
EMACS_PORT_NAME?=	mule

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
EMACSDIR=	${PREFIX}/lib/xemacs/site-packages
ELISPDIR=	${EMACSDIR}/lisp/lookup
PORTINFODIR=	${EMACSDIR}/info
MANIFEST=	MANIFEST.lookup
.else
EMACSDIR=	${PREFIX}/share/${EMACS_NAME}/site-lisp
ELISPDIR=	${EMACSDIR}/lookup
PORTINFODIR=	${PREFIX}/info
.endif
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --with-emacs=${EMACS_CMD} \
		--with-lispdir=${ELISPDIR} \
		--infodir=${PORTINFODIR}

post-install:
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
	${RM} -f ${WRKDIR}/${MANIFEST}
	emacsdir=`${ECHO} ${EMACSDIR} | ${SED} -e "s;^${PREFIX}/;;"`; \
	${CAT} ${PLIST} | ${GREP} -e "^$${emacsdir}" | \
		${SED} -e "s;^$${emacsdir}/;;" > ${WRKDIR}/${MANIFEST}
	${MKDIR} ${EMACSDIR}/pkginfo
	${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${EMACSDIR}/pkginfo/
.endif

.include <bsd.port.mk>
