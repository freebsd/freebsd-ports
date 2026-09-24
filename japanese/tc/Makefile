PORTNAME=	tc
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.3.1-148
DISTVERSIONSUFFIX=	-g5d84e84
CATEGORIES=	japanese elisp
MASTER_SITES=	https://github.com/naota/tc/raw/master/doc/
DISTFILES=	manual.pdf tc.info
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Japanese direct input method environment for emacs
WWW=		https://github.com/kanchoku/tc

USE_GITHUB=	yes
GH_ACCOUNT=	kanchoku

NO_ARCH=	yes
NO_BUILD=	yes

ELISPDIR=	share/emacs/site-lisp/${PORTNAME}
PLIST_SUB=	ELISPDIR=${ELISPDIR}

OPTIONS_DEFINE=	DOCS

post-extract:
	cd ${DISTDIR}/${PORTNAME} && \
		${INSTALL_DATA} manual.pdf tc.info ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.el tcode" \
		${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/tc.info ${STAGEDIR}${PREFIX}/share/info

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
