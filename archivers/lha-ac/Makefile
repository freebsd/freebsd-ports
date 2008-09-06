# New ports collection makefile for:    lha-autoconf
# Date created:         24 Sep 2004
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	lha
PORTVERSION=	1.14i
PORTREVISION=	10
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP} \
		http://qgpop.dl.sourceforge.jp/%SUBDIR%/ \
		http://osdn.dl.sourceforge.jp/%SUBDIR%/
MASTER_SITE_SUBDIR=	lha/22231
PKGNAMESUFFIX=	-ac${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-${PORTVERSION}-ac20050924p1

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Archive files using LZSS and Huffman compression (.lzh files)

MAN1=		lha.1
MANLANG=	ja
PLIST_FILES=	bin/lha
#PLIST_DIRS=	man/ja/man1
GNU_CONFIGURE=	yes

RESTRICTED=	no permission to redistribute

.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-multibyte-filename
.else
CONFIGURE_ARGS+=	--enable-multibyte-filename=auto
.endif

do-install:
	-${MKDIR} ${MANPREFIX}/man/ja/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/lha
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${MANPREFIX}/man/ja/man1/lha.1

.include <bsd.port.mk>
