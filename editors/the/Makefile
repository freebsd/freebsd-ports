# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	the
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/hessling-editor/hessling-editor/${PORTVERSION}
DISTNAME=	THE-${PORTVERSION}

PATCH_SITES=	http://users.comlab.ox.ac.uk/ian.collier/distribution/
PATCHFILES=	THE-3.1-rexximc.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"The Hessling Editor", an implementation of the xedit editor

DEPRECATED=	Unmaintained since 1999
EXPIRATION_DATE=	2014-04-10
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses \
		--with-rexxincdir=${LOCALBASE}/include \
		--with-rexxlibdir=${LOCALBASE}/lib
ALL_TARGET=	all html

MAN1=		the.1

OPTIONS_DEFINE=	XAW3D XCURSES REXX_REGINA DOCS
XAW3D_DESC=	Enable Xaw3D
XCURSES_DESC=	Build XCurses (X11) version
REXX_REGINA_DESC=	Enable Rexx interpreter

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

.if ${PORT_OPTIONS:MXAW3D}
CONFIGURE_ARGS+=--with-xaw3d
LIB_DEPENDS+=	Xaw3d.8:${PORTSDIR}/x11-toolkits/Xaw3d
.endif

.if ${PORT_OPTIONS:MXCURSES}
CONFIGURE_ARGS+=--with-xcurses \
		--with-cursesincdir=${LOCALBASE}/include \
		--with-curseslibdir=${LOCALBASE}/lib
BUILD_DEPENDS+=	pdcurses-the>=3.2:${PORTSDIR}/devel/pdcurses-the
LIB_DEPENDS+=	XCurses.2:${PORTSDIR}/devel/pdcurses-the
PLIST_SUB=	XCURSES="" NCURSES="@comment "
.else
PLIST_SUB=	XCURSES="@comment " NCURSES=""
.endif

.if ${PORT_OPTIONS:MREXX_REGINA}
BUILD_DEPENDS+=	regina:${PORTSDIR}/lang/rexx-regina
RUN_DEPENDS+=	regina:${PORTSDIR}/lang/rexx-regina
CONFIGURE_ARGS+=	--with-rexx=regina
.else
BUILD_DEPENDS+=	rexx:${PORTSDIR}/lang/rexx-imc
RUN_DEPENDS+=	rexx:${PORTSDIR}/lang/rexx-imc
CONFIGURE_ARGS+=	--with-rexx=rexximc
.endif

post-install:
.if ${PORT_OPTIONS:MXCURSES}
	@${LN} -sf xthe ${PREFIX}/bin/the
.else
	@${LN} -sf nthe ${PREFIX}/bin/the
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/THE
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/THE
.endif

.include <bsd.port.post.mk>
