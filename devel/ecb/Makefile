# New ports collection makefile for:   ecb
# Date created:                25 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	ecb
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecb
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Emacs Code Browser

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/semantic/semantic.el:${PORTSDIR}/devel/semantic${PORTNAMESUFFIX} 
RUN_DEPENDS=	${BUILD_DEPENDS}

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	ecb
PLIST_SUB=	INFOSECTION="${INFOSECTION}"
INFOSECTION=	The Emacs editor and associated tools

post-patch:
	${REINPLACE_CMD} "s|\./info-help|${PREFIX}/info|" ${WRKSRC}/ecb-help.el

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/info-help/* ${PREFIX}/info
	install-info --section="${INFOSECTION}" ${PREFIX}/info/ecb.info \
		${PREFIX}/info/dir

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in NEWS README RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
