# New ports collection makefile for:	BitchX ircII client patched for korean
# Date created:		3 Jun 1999
# Whom:			JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTVERSION=	1.0c16
PORTREVISION=	6
CATEGORIES=	korean irc
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/

PATCH_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/
PATCHFILES=	bx-korean-aa.patch\
		bx-korean-ab.patch\
		bx-korean-ac.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alternative ircII color client support patched for korean

WRKSRC=		${WRKDIR}/BitchX

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--without-plugins \
		--exec-prefix="${PREFIX}/share"	\
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L{LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64 (needs -fPIC)
.endif

CONFIGURE_ARGS+=--without-gtk

post-patch:
	${TOUCH} ${WRKSRC}/configure

post-install:
	@(${LN} -sf ${PREFIX}/bin/BitchX ${PREFIX}/bin/bx)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${MKDIR} ${PREFIX}/share/doc/bitchx
	${CP} -r ${WRKSRC}/bitchx-docs/* ${PREFIX}/share/bx/help
	${INSTALL_DATA} ${WRKSRC}/doc/bxfaq.html ${PREFIX}/share/doc/bitchx
	${RMDIR} ${PREFIX}/share/bx/help/4_Misc/fset
	${RMDIR} ${PREFIX}/share/bx/help/4_Misc/wset
.endif

.include <bsd.port.post.mk>
