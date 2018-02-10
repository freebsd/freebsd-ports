# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
COMMENT=	Japanese incremental search tool for Emacs
MASTERDIR=	${.CURDIR}/../../japanese/migemo
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist
PKGMESSAGE=	${MASTERDIR}/pkg-message

BUILD_DEPENDS=	apel${EMACS_PKGNAMESUFFIX}>=10.8:editors/apel@${EMACS_FLAVOR}
RUN_DEPENDS=	apel${EMACS_PKGNAMESUFFIX}>=10.8:editors/apel@${EMACS_FLAVOR} \
		migemo:japanese/migemo

USES=		emacs

CONFLICTS=	ja-migemo.el

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}
ALL_TARGET=	migemo.elc

PLIST_SUB=	MIGEMO="@comment " ELISP=""
SLAVE_PORT=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/site-lisp
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${STAGEDIR}${PREFIX}/${EMACS_LIBDIR}/site-lisp

.include "${MASTERDIR}/Makefile"
