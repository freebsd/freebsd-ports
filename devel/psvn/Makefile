# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	psvn
PORTVERSION=	20150720.214200
CATEGORIES=	devel elisp
MASTER_SITES=	http://www.xsteve.at/prg/emacs/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	psvn.el
EXTRACT_SUFX=	# empty

MAINTAINER=	yasu@utahime.org
COMMENT=	Subversion interface for Emacs

LICENSE=	GPLv2+

RUN_DEPENDS=	svn:devel/subversion

USES=		emacs

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}/psvn.el

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}/psvn.el \
		${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}/psvn.elc

ELISPDIR=	${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-build:
	(cd ${WRKSRC} && ${EMACS_CMD} -batch -q -f batch-byte-compile psvn.el)

do-install:
	@${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/psvn.* ${ELISPDIR}

.include <bsd.port.mk>
