# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	slirc
PORTVERSION=	0.12
PORTREVISION=	4
# Assign with += for slave ports
CATEGORIES+=	irc
MASTER_SITES=	http://members.core.com/~stabro/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLang-based IRC client

BROKEN=		unfetchable

LIB_DEPENDS=	${LIB_DEPENDS_LIBSLANG}

USES=		gmake tar:tgz
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLANG_INCDIR?=	${LOCALBASE}/include
SLANG_LIBDIR?=	${LOCALBASE}/lib
LIB_DEPENDS_LIBSLANG?=	libslang.so.2:devel/libslang2

MAKE_ARGS=	SLANG_INCDIR="${SLANG_INCDIR}" \
		SLANG_LIBDIR="${SLANG_LIBDIR}" \
		${MAKE_ARGS_JA}
PLIST_SUB=	JA=${PLIST_JA}
PLIST_JA?=	"@comment "

# Assign with += for slave ports
DOCS+=		BUGS \
		CHANGES \
		COPYING \
		FAQ \
		LACK-OF-WARRANTY \
		README \
		README.dropin \
		README.gutsbonesbloodtoilsweat \
		TODO \
		scripts/slirc.hlp \
		sldocs/VFile.txt \
		sldocs/utilsfun.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
