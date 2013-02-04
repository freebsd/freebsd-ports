# Created by: asami
# $FreeBSD$

PORTNAME=	nkf
PORTVERSION=	2.1.2
PORTEPOCH=	1
CATEGORIES?=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/53171
PKGNAMEPREFIX?=	ja-

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Network Kanji code conversion Filter

LICENSE?=	ZLIB
LICENSE_FILE?=	${WRKSRC}/nkf.c

.if ${PKGNAMEPREFIX} != "ja-p5-"
MAN1=		nkf.1
MANLANG=	"" ja
PLIST_FILES=	bin/nkf
ALL_TARGET=	nkf
.endif

.include <bsd.port.mk>
