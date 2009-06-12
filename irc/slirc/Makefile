# New ports collection makefile for:	SLirc
# Date created:		6 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	slirc
PORTVERSION=	0.12
PORTREVISION=	2
# Assign with += for slave ports
CATEGORIES+=	irc
MASTER_SITES=	http://members.core.com/~stabro/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A SLang-based IRC client

LIB_DEPENDS=	${LIB_DEPENDS_LIBSLANG}

USE_GMAKE=	yes
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

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local,${LOCALBASE}," ${WRKSRC}/Makefile ${WRKSRC}/scripts/init.sl
	  
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/slirc
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/slirc/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
