PORTNAME=	bitchx
CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zh-tw cursor movement friendly, wrapping clean BitchX

MASTERDIR=	${.CURDIR}/../../irc/bitchx
EXTRA_PATCHES=	${.CURDIR}/files/patch-source__input.c \
		${.CURDIR}/files/patch-include__config.h \
		${.CURDIR}/files/patch-source__screen.c

CONFLICTS_INSTALL=	bitchx

OPTIONS_SLAVE=	LATIN

.include "${MASTERDIR}/Makefile"
