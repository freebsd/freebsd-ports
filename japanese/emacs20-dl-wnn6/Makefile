# New ports collection makefile for:	emacs20-dl-wnn6
# Version required:	0.3.6
# Date created:		10 October 1998
# Whom:			shige
#
# $FreeBSD$
#

DISTNAME=	dl-wnn-0.3.6
PKGNAME=	ja-emacs20-dl-wnn6-0.3.6
CATEGORIES=	japanese editors
MASTER_SITES=	http://tt-www.cs.titech.ac.jp/~katsuya/emacs/

MAINTAINER=	shige@FreeBSD.org

LIB_DEPENDS=	wnn6.1:${.CURDIR}/../../japanese/Wnn6-lib
BUILD_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		/nonexistent:${EMACSDL_DIR}:configure
RUN_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wnn6 \
		--with-wnn-includes=${PREFIX}/include/wnn \
		--with-wnn-libraries=${PREFIX}/lib \
		--with-emacs-src=${WRKDIRPREFIX}${EMACSDL_DIR}/work/emacs-${EMACS_VER}
CONFIGURE_ENV=	EMACS=${PREFIX}/bin/emacs-dl-${EMACS_VER}
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${MACHINE_ARCH}--freebsd \
		DOCDIR=${DOCDIR}

DOCDIR=		share/doc/emacs20-dl-wnn6
EMACS_VER=	20.4
EMACSDL_DIR=	${.CURDIR}/../../editors/emacs20-dl
# hack to allow parallel build to work
.if defined(PARALLEL_PACKAGE_BUILD)
BUILD_DEPENDS+=	gmake:${PORTSDIR}/devel/gmake \
		autoconf:${PORTSDIR}/devel/autoconf
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
