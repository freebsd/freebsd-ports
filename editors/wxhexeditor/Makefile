# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wxhexeditor
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/wxHexEditor/v${PORTVERSION}%20Beta/
DISTNAME=	wxHexEditor-v${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical hex editor for big files with x86 disassembly support

LICENSE=	GPLv2

LIB_DEPENDS=	libudis86.so:devel/udis86 \
		libmhash.so:security/mhash

USES=		gettext-tools gmake tar:xz
USE_WX=		3.0+
MAKE_ARGS=	WXCONFIG="${WX_CONFIG}"

WRKSRC=		${WRKDIR}/wxHexEditor

# Follow the ${MTREE_FILE} which specifies simple, unsuffixed names
# for these particular locales
post-patch:
	@${MV} ${WRKSRC}/locale/hu_HU ${WRKSRC}/locale/hu
	@${MV} ${WRKSRC}/locale/ja_JP ${WRKSRC}/locale/ja
	@${MV} ${WRKSRC}/locale/nl_NL ${WRKSRC}/locale/nl

.include <bsd.port.mk>
