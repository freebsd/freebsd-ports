# $FreeBSD$

PORTNAME=	lha
PORTVERSION=	1.14i
PORTREVISION=	10
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP} \
		http://osdn.dl.sourceforge.jp/%SUBDIR%/
MASTER_SITE_SUBDIR=	lha/22231
PKGNAMESUFFIX=	-ac${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-${PORTVERSION}-ac20050924p1

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Archive files using LZSS and Huffman compression (.lzh files)

RESTRICTED=	no permission to redistribute

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/lha-ac
MANLANG=	ja
MAN1_JA=	lha-ac.1
PLIST_FILES+=	${__MANPAGES}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-multibyte-filename
.else
CONFIGURE_ARGS+=	--enable-multibyte-filename=auto
.endif

do-install:
	-${MKDIR} ${STAGEDIR}${PREFIX}/man/ja/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${STAGEDIR}${PREFIX}/bin/lha-ac
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${STAGEDIR}${PREFIX}/man/ja/man1/lha-ac.1

.include <bsd.port.mk>
