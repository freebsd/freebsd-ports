# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-tiny

COMMENT=	Improved version of the vi editor (vim binary only)

CONFLICTS_INSTALL=	vim vim-console

TINY=		yes
MASTERDIR=	${.CURDIR}/../vim

PORTDATA=	# Not for -tiny
PLIST=		${.CURDIR}/pkg-plist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vim ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/runtime/doc/vim.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
