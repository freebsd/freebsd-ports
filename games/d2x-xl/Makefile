# New ports collection makefile for:	d2x-xl
# Date created:		25 Feb 2009
# Whom:			Aragon Gouveia
#
# $FreeBSD$
#

PORTNAME=	d2x-xl
PORTVERSION=	1.13.127
CATEGORIES=	games
MASTER_SITES=	http://www.descent2.de/downloads/
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.rar

MAINTAINER=	aragon@phat.za.net
COMMENT=	Community Unix port of Descent 2 Game

EXTRACT_DEPENDS=unrar:${PORTSDIR}/archivers/unrar

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --enable-release=yes --with-sharepath=${PREFIX}/share/d2x-xl
USE_SDL=	sdl mixer
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:110 \
		autoheader:262 \
		automake:110 \
		autoconf:262
AUTOMAKE_ARGS=	--add-missing --copy

USE_DOS2UNIX=	missing depcomp

SUB_FILES=	pkg-message
PLIST_FILES=	bin/d2x-xl

OPTIONS=	OPENGL "Use OpenGL for 3D graphics" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if !defined(WITHOUT_OPENGL)
USE_GL=		gl glu glut
CONFIGURE_ARGS+=--with-opengl
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		unrar x ${DISTDIR}/${DISTFILES} >/dev/null && \
		unrar x ${PORTNAME}-makefiles.rar >/dev/null && \
		${CHMOD} +x configure

post-patch:
	@${REINPLACE_CMD} -e '/FLAGS/ s|-O3||; /FLAGS/ s|-g||' \
		${WRKSRC}/configure.ac
	@cd ${WRKSRC} && \
		${FIND} . -name "*.cpp" -o -name "*.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/d2x-xl ${PREFIX}/bin/d2x-xl
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
