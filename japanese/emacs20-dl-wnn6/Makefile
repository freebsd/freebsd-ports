# New ports collection makefile for:	emacs20-dl-wnn6
# Date created:		10 October 1998
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	emacs20-dl-wnn6
PORTVERSION=	0.3.6
PORTREVISION=	2
CATEGORIES=	japanese editors
MASTER_SITES=	http://tokuda-www.cs.titech.ac.jp/~katsuya/emacs/
DISTNAME=	dl-wnn-${PORTVERSION}

MAINTAINER=	shige@FreeBSD.org
COMMENT=	Dynamic loading module input method `Wnn' on Emacs

LIB_DEPENDS=	wnn6.2:${.CURDIR}/../../japanese/Wnn6-lib
BUILD_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		autoconf:${PORTSDIR}/devel/autoconf \
		${NONEXISTENT}:${EMACSDL_DIR}:configure
RUN_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wnn6 \
		--with-wnn-includes=${PREFIX}/include/wnn6/wnn \
		--with-wnn-libraries=${PREFIX}/lib \
		--with-emacs-src=${EMACSDL_SRCDIR}
CONFIGURE_ENV=	EMACS=${PREFIX}/bin/emacs-dl-${EMACS_VER}
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${MACHINE_ARCH}--freebsd \
		DOCDIR=${DOCDIR}

DOCDIR=		share/doc/emacs20-dl-wnn6
EMACS_VER=	20.7
EMACSDL_DIR=	${.CURDIR}/../../editors/emacs20-dl
EMACSDL_SRCDIR=	${WRKDIRPREFIX}${EMACSDL_DIR}/work/emacs-${EMACS_VER}
# hack to allow parallel build to work
.if defined(PARALLEL_PACKAGE_BUILD)
USE_GMAKE=	yes
BUILD_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf
.endif

post-install:
	@${LN} -sf ${PREFIX}/share/emacs/site-lisp/egg/eggrc-wnn \
		${PREFIX}/share/emacs/site-lisp/egg/.eggrc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.mk>
