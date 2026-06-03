PORTNAME=	xcircuit
DISTVERSION=	3.10.44
PORTEPOCH=	1
CATEGORIES=	cad

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	X11 circuit schematics drawing program
WWW=		http://opencircuitdesign.com/xcircuit/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		ghostscript:x11,run gmake gnome pkgconfig tk:tea xorg
USE_GITHUB=	yes
GH_ACCOUNT=	RTimothyEdwards
GH_PROJECT=	XCircuit

USE_GNOME=	cairo
USE_XORG=	ice sm x11 xpm xscrnsaver xt

GNU_CONFIGURE=	yes

MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

DESKTOP_ENTRIES="Xcircuit" "${COMMENT}" "${DATADIR}/pixmaps/${PORTNAME}.gif" \
		"${PORTNAME}" "" false
# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/test/s| == | = |g ; \
		 s|TCL_LIB_NAME=.*$$|TCL_LIB_NAME="tcl${TCL_VER:S/.//}"|g ; \
		 s|TK_LIB_NAME=.*$$|TK_LIB_NAME="tk${TK_VER:S/.//}"|g ; \
		 s|wish |${WISH:T} |g ; \
		 s|-fpic|-fPIC|g' ${WRKSRC}/configure

post-install:
	cd ${STAGEDIR}${DATADIR} && ${STRIP_CMD} xcircdnull xcircexec xcircuit.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} \
		*.lgf *.lps *.ps *.sim .xcircuitrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
