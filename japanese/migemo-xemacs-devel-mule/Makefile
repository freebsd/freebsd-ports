# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
COMMENT=	Japanese incremental search tool for xemacs-devel-mule
MASTERDIR=	${.CURDIR}/../../japanese/migemo
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist
PKGMESSAGE=	${MASTERDIR}/pkg-message

USE_EMACS=	yes
EMACS_PORT_NAME=	xemacs-devel-mule

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}
ALL_TARGET=	migemo.elc

PLIST_SUB=	MIGEMO="@comment " ELISP=""
SLAVE_PORT=	yes

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/migemo.el ${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/migemo.elc ${PREFIX}/${EMACS_SITE_LISPDIR}

.include "${MASTERDIR}/Makefile"
