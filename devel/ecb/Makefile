# New ports collection makefile for:   ecb
# Date created:                25 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	ecb
PORTVERSION=	1.60
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecb
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	fuyuki@mj.0038.net

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/semantic/semantic.el:${PORTSDIR}/devel/semantic${PORTNAMESUFFIX} \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/eieio/eieio.el:${PORTSDIR}/devel/eieio${PORTNAMESUFFIX}
RUN_DEPENDS=	${BUILD_DEPENDS}

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

USE_GMAKE=	yes

# Purge the stray source file from Makefile
pre-build:
	${PERL} -pi -e 's/ecb-speedbar.el//' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in HISTORY README RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
