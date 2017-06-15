# Created by: Yen-Shuo Su <yssu@CCCA.NCTU.edu.tw>
# $FreeBSD$

CATEGORIES=	chinese

MAINTAINER=	ports@FreeBSD.org

EXTRA_PATCHES=	${.CURDIR}/files/patch-attrib.c \
		${.CURDIR}/files/patch-cook.c \
		${.CURDIR}/files/patch-mail.c \
		${.CURDIR}/files/patch-init.c

MASTERDIR=	${.CURDIR}/../../news/tin

post-patch: post-patch-zh
post-patch-zh:
	${REINPLACE_CMD} -e 's,iso-8859-1,Big5,g' ${WRKSRC}/doc/tin.defaults

.include "${MASTERDIR}/Makefile"
