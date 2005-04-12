# New ports collection makefile for:	emacs20-dl-canna
# Date created:		10 October 1998
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	emacs20-dl-canna
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/dynamic-loading/emacs-canna/ \
		${MASTER_SITE_PORTS_JP} 
DISTNAME=	emacs-canna-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic loading module input method `Canna' on Emacs

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna
# Building this port requires emacs-dl source tree: ${EMACSDL_DIR}:configure
BUILD_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		${NONEXISTENT}:${EMACSDL_DIR}:configure \
		${APEL_DEPENDS}:${PORTSDIR}/editors/apel-emacs20
RUN_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		${APEL_DEPENDS}:${PORTSDIR}/editors/apel-emacs20

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-canna-includes=${PREFIX}/include \
		--with-canna-libraries=${PREFIX}/lib \
		--with-emacs-srcdir=${EMACSDL_SRCDIR}
CONFIGURE_ENV=	EMACS="emacs-dl-${EMACS_VER}"
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${MACHINE_ARCH}--freebsd \
		DLCANNA_VER=${DLCANNA_VER} LISPDIR=${LISPDIR} DOCDIR=${DOCDIR}

# ports variables
EMACS_VER=	20.7
EMACSDL_DIR=	${.CURDIR}/../../editors/emacs20-dl
EMACSDL_SRCDIR=	${WRKDIRPREFIX}${EMACSDL_DIR}/work/emacs-${EMACS_VER}/src
APEL_DEPENDS=	${PREFIX}/share/emacs/${EMACS_VER}/site-lisp/emu/emu.el
LISPDIR=	share/emacs/site-lisp
DOCDIR=		share/doc/emacs20-dl-canna
DLCANNA_VER=	1.4
# hack to allow parallel build to work
.if defined(PACKAGE_BUILDING)
USE_GMAKE=	yes
WANT_AUTOCONF_VER=253
.endif

post-install:
.if !defined(NOPORTDOCS)
	@[ -d ${PREFIX}/${DOCDIR} ] || ${MKDIR} ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.mk>
