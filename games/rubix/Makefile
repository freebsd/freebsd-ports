# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	rubix
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://sed.free.fr/rubix/ \
		http://mirror.mcx2.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another Rubik's cube game with a rather interesting interface

USES=		compiler:nestedfct gmake tar:bzip2
USE_XORG=	x11
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DENGLISH" \
		XINC="-I${LOCALBASE}/include" XLIB="-L${LOCALBASE}/lib -lX11"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	AUTHORS BUGS INSTALL README TODO
PLIST_FILES=	bin/rubix

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if (${ARCH} == mips || ${ARCH} == mips64 || ${ARCH} == powerpc || ${ARCH} == powerpc64) && ${COMPILER_TYPE} == gcc
CFLAGS+=	-fnested-functions
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rubix ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
