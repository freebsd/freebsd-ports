# Created by: Aragon Gouveia
# $FreeBSD$

PORTNAME=	d2x-xl
PORTVERSION=	1.14.121
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/d2x-xl/Linux/Archive:source \
		SF/d2x-xl/Linux:source \
		SF/d2x-xl/Data:data \
		http://www.descent2.de/downloads/:source,data
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.rar:source \
		${PORTNAME}-data-${DATAVERSION}.rar:data

MAINTAINER=	aragon@phat.za.net
COMMENT=	Community Unix port of Descent 2 Game

EXTRACT_DEPENDS=	unrar:archivers/unrar
RUN_DEPENDS=	unrar:archivers/unrar

DATAVERSION=	1.14.95

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --enable-release=yes \
		--with-sharepath=${PREFIX}/share/d2x-xl
USE_SDL=	sdl mixer image
USES=		dos2unix gmake motif
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing --copy

DOS2UNIX_FILES=	missing depcomp

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	OPENGL
OPTIONS_DEFAULT=	OPENGL

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		gl glu
CONFIGURE_ARGS+=--with-opengl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		unrar x -o+ ${DISTDIR}/${PORTNAME}-src-${PORTVERSION}.rar >/dev/null && \
		unrar x -o+ ${PORTNAME}-makefiles.rar >/dev/null && \
		${CHMOD} +x configure

post-patch:
	@${ECHO_CMD} 'CCLD = $$(CXX)' >> ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/FLAGS/ s|-O3||; /FLAGS/ s|-g||' \
		${WRKSRC}/configure.ac
	@cd ${WRKSRC} && \
		${FIND} . -name "*.cpp" -o -name "*.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${STAGEDIR}${DATADIR} && \
		unrar x -o+ ${DISTDIR}/${PORTNAME}-data-${DATAVERSION}.rar >/dev/null
	${INSTALL_PROGRAM} ${WRKSRC}/d2x-xl ${STAGEDIR}${PREFIX}/bin/d2x-xl

.include <bsd.port.mk>
