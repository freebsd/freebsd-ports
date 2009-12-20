# New ports collection makefile for:   psvn
# Date created:                18 May 2004
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	psvn
PORTVERSION=	38969
PORTREVISION=	1
CATEGORIES=	devel elisp
MASTER_SITES=	http://svn.collab.net/viewvc/svn/trunk/contrib/client-side/emacs/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	psvn.el\?revision=${PORTVERSION}
EXTRACT_SUFX=	# empty

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Subversion interface for Emacs

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

USE_EMACS=	yes

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}/psvn.el

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}/psvn.el \
		${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}/psvn.elc
PLIST_DIRS=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

ELISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-build:
	cd ${WRKSRC}; ${EMACS_CMD} -batch -q -f batch-byte-compile psvn.el

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/psvn.* ${ELISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
