# New ports collection makefile for:   jde
# Date created:                8 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jde
PORTVERSION=	2.2.8
CATEGORIES=	java elisp
MASTER_SITES=	http://jdee.sunsite.dk/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-latest

MAINTAINER=	fuyuki@mj.0038.net

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/semantic/semantic.el:${PORTSDIR}/devel/semantic${PORTNAMESUFFIX} \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/elib/avltree.el:${PORTSDIR}/devel/elib${PORTNAMESUFFIX}
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/lisp
MAKEFILE=	makefile

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/jde
JAVADIR=	${PREFIX}/share/java/jde

post-patch:
# An ugly patch for a troublesome varname change in the browse-url.
.if ${EMACS_PORT_NAME} == "emacs21"
	${PERL} -pi -e 's/browse-url-new-window-p/browse-url-new-window-flag/' \
		${BUILD_WRKSRC}/*.el
.endif

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${BUILD_WRKSRC}/${i} ${LISPDIR}
.endfor
	${MKDIR} ${JAVADIR}
.for i in bsh-commands lib src
	${CP} -pR ${WRKSRC}/java/${i} ${JAVADIR}
.endfor
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/jtags ${PREFIX}/bin

post-install:
	${LN} -sf ${JAVADIR} ${LISPDIR}/java
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ReleaseNotes.txt ChangeLog
	${CP} ${BUILD_WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in html tli_rbl
	${CP} -pR ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	${LN} -sf ${DOCSDIR} ${LISPDIR}/doc
.endif

.include <bsd.port.mk>
