# New ports collection makefile for:	tamago
# Date created:		6 March 2000
# Whom:			tetsushi NAKAI <nakai@tsl.pe.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	tamago
PORTVERSION=	${EGG_DEBIAN_VER}.${EGG_ANTHY_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_DEBIAN} \
		http://www.meadowy.org/~shirai/elips/:anthy
MASTER_SITE_SUBDIR=	pool/main/e/egg
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTFILES=	egg_4.0.6+0.20041122cvs.orig.tar.gz \
		egg-anthy.tar.gz:anthy

PATCH_SITES=	${MASTER_SITE_DEBIAN:S,%SUBDIR%,pool/main/e/egg,} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,nork,}
PATCHFILES=	egg_4.0.6+0.20041122cvs-9.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Multilingual Input Method - Egg V4

EGG_DEBIAN_VER=	4.0.6.0.20041122.9
EGG_ANTHY_VER=	20060606.2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

WRKSRC=		${WRKDIR}/egg-4.0.6+0.20041122cvs
WRKSRC_ANTHY=	${WRKDIR}/egg-anthy-20060606-2
ELISPDIR=	${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
PLIST_SUB=	ELISPDIR="${EMACS_LIBDIR_WITH_VER}/site-lisp"

.if ${EMACS_PORT_NAME} == emacs21 || ${EMACS_PORT_NAME} == emacs22
PLIST_SUB+=	HAS_JISX0213=""
.else
PLIST_SUB+=	HAS_JISX0213="@comment "
.endif

post-extract:
.for f in anthy.el anthyipc.el
	@${CP} ${WRKSRC_ANTHY}/${f} ${WRKSRC}/egg
.endfor

pre-configure:
	@${REINPLACE_CMD} -e 's|emacs/site-lisp|${EMACS_NAME}/${EMACS_VER}/site-lisp|g' \
	    ${WRKSRC}/configure

post-build:
	(cd ${WRKSRC}/helper && ${MAKE} egg-helper)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/helper/egg-helper ${PREFIX}/bin/egg-helper
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog ChangeLog.1997-1998 ChangeLog.2000-2001 PROBLEMS README.ja.txt TODO debian/README.Debian
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DOCSDIR}/changelog.Debian
	${INSTALL_DATA} ${WRKSRC_ANTHY}/egg-anthy.readme ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
