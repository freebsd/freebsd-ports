# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	slirc
PORTVERSION=	0.12
PORTREVISION=	4
# Assign with += for slave ports
CATEGORIES+=	irc
MASTER_SITES=	http://members.core.com/~stabro/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A SLang-based IRC client

LIB_DEPENDS=	${LIB_DEPENDS_LIBSLANG}

USES=		gmake
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SLANG_INCDIR?=	${LOCALBASE}/include
SLANG_LIBDIR?=	${LOCALBASE}/lib
LIB_DEPENDS_LIBSLANG?=	slang.2:${PORTSDIR}/devel/libslang2

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

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s,/usr/local,${LOCALBASE}," ${WRKSRC}/Makefile ${WRKSRC}/scripts/init.sl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>
post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${PREFIX}/share/doc/slirc
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/slirc/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
