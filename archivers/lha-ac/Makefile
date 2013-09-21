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

CONFLICTS=	lha-1*
NO_STAGE=	yes

MAN1=		lha.1
MANLANG=	ja
PLIST_FILES=	bin/lha
#PLIST_DIRS=	man/ja/man1
GNU_CONFIGURE=	yes

RESTRICTED=	no permission to redistribute

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-multibyte-filename
.else
CONFIGURE_ARGS+=	--enable-multibyte-filename=auto
.endif

do-install:
	-${MKDIR} ${MANPREFIX}/man/ja/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/lha ${PREFIX}/bin/lha
	${INSTALL_MAN} ${WRKSRC}/man/lha.n ${MANPREFIX}/man/ja/man1/lha.1

.include <bsd.port.mk>
