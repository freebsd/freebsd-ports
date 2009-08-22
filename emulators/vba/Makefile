# New ports collection makefile for:	vba
# Date Created:				02 September 2003
# Whom:					<arundel@gmx.net>
#
# $FreeBSD$

PORTNAME=	vba
PORTVERSION=	1.7.2
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/VisualBoyAdvance/${PORTVERSION}
DISTNAME=	VisualBoyAdvance-src-${PORTVERSION}

MAINTAINER=	arundel@h3c.de
COMMENT=	Open Source Gameboy Advance emulator

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WANT_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl
CONFIGURE_ARGS=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include" LIBS="-lintl"
WRKSRC=		${WRKDIR}/VisualBoyAdvance-${PORTVERSION}

PLIST_SUB=	INSTALL_GTK2="@comment "

DATA_FILES=	${WRKSRC}/src/VisualBoyAdvance.cfg
PROG_FILES=	${WRKSRC}/src/sdl/VisualBoyAdvance
DOC_FILES=	COPYING AUTHORS NEWS README ChangeLog INSTALL

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Runaway cc1plus process
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Fails to compile: internal gcc error
.endif

.ifdef(WITH_GTK2)
PLIST_SUB=	INSTALL_GTK2=""
CONFIGURE_ARGS+=	--enable-gtk=2.4
USE_GNOME=	gnomelibs gtk20
LIB_DEPENDS+=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glademm-2.4:${PORTSDIR}/devel/libglademm24
PROG_FILES+=	${WRKSRC}/src/gtk/gvba
GTK2_DATA_FILES=	${WRKSRC}/src/gtk/vba.glade
.endif

.ifndef(PROFILING)
CONFIGURE_ARGS+=	--disable-profiling
.endif

pre-everything::
.ifndef(PROFILING)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can enable profiling by defining PROFILING."
.endif
.ifndef(WITH_GTK2)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can install the GTK2 based X version by defining WITH_GTK2."
.endif
	@${ECHO_MSG} ""

do-install:
	${INSTALL_PROGRAM} ${PROG_FILES} ${PREFIX}/bin
.ifdef(WITH_GTK2)
	${INSTALL} -d ${PREFIX}/share/VisualBoyAdvance
	${INSTALL_DATA} ${GTK2_DATA_FILES} ${PREFIX}/share/VisualBoyAdvance
.endif
	${SED} -e 's|filter=0|filter=1|' ${DATA_FILES} > ${DATA_FILES}-default
	${INSTALL_DATA} ${DATA_FILES}-default ${PREFIX}/bin

post-install:
.ifndef(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
.for filename in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${filename} ${DOCSDIR}
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
