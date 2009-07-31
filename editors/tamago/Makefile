# New ports collection makefile for:	tamago
# Date created:		6 March 2000
# Whom:			tetsushi NAKAI <nakai@tsl.pe.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	tamago
PORTVERSION=	4.0.6.0.20041122.11
PORTREVISION=	5
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/e/egg
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	egg_4.0.6+0.20041122cvs.orig

PATCH_SITES=	${MASTER_SITE_DEBIAN:S,%SUBDIR%,pool/main/e/egg,} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,nork,}
PATCHFILES=	egg_4.0.6+0.20041122cvs-11.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	The Multilingual Input Method - Egg V4

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_EMACS=	yes
WRKSRC=		${WRKDIR}/egg-4.0.6+0.20041122cvs
ELISPDIR=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
PLIST_SUB=	ELISPDIR="${EMACS_LIBDIR_WITH_VER}/site-lisp"
PORTDOCS=	AUTHORS ChangeLog ChangeLog.1997-1998 \
		ChangeLog.2000-2001 PROBLEMS README.ja.txt TODO \
		README.Debian changelog.Debian

POSTPATCHES=	${FILESDIR}/post-patch-*

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} == emacs21 || ${EMACS_PORT_NAME} == emacs22
PLIST_SUB+=	HAS_JISX0213=""
.else
PLIST_SUB+=	HAS_JISX0213="@comment "
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|emacs/site-lisp|${EMACS_NAME}/${EMACS_VER}/site-lisp|g' \
	    ${WRKSRC}/configure

post-patch:
	cd ${PATCH_WRKSRC} && ${CAT} ${POSTPATCHES} | ${PATCH}

post-build:
	cd ${WRKSRC}/helper && ${MAKE} egg-helper
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${WRKSRC}/changelog.Debian
	${INSTALL_DATA} ${WRKSRC}/debian/README.Debian ${WRKSRC}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/helper/egg-helper ${PREFIX}/bin/egg-helper
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
