# New ports collection makefile for:   jde
# Date created:                8 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jde
PORTVERSION=	2.2.9
PORTREVISION=	1
CATEGORIES=	java elisp
MASTER_SITES=	http://jdee.sunsite.dk/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Development Environment for Emacs

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/semantic/semantic.el:${PORTSDIR}/devel/semantic${PORTNAMESUFFIX} \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/elib/avltree.el:${PORTSDIR}/devel/elib${PORTNAMESUFFIX}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/lisp
MAKEFILE=	makefile

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/jde
JAVADIR=	${PREFIX}/share/java/jde

post-patch:
	${REINPLACE_CMD} -e '/test -d/d' ${BUILD_WRKSRC}/${MAKEFILE}
	${REINPLACE_CMD} -e 's|^      dir|"${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/jde/"|' \
		${BUILD_WRKSRC}/jde.el

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc *.bnf
	${INSTALL_DATA} ${BUILD_WRKSRC}/${i} ${LISPDIR}
.endfor
	${MKDIR} ${JAVADIR}
.for i in bsh-commands lib src
	${CP} -R ${WRKSRC}/java/${i} ${JAVADIR}
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
	${CP} -R ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	${LN} -sf ${DOCSDIR} ${LISPDIR}/doc
.endif

.include <bsd.port.mk>
