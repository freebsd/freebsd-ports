# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PKGNAMEPREFIX=	ja-uim-

COMMENT=	Mozc engine for uim

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
FILESDIR=	${.CURDIR}/files
DATADIR=	${PREFIX}/share/uim
SUB_FILES=	pkg-message

BUILD_MOZC_LIST=uim_mozc

.include "${MASTERDIR}/Makefile"
