# Created by: roberto
# $FreeBSD$

PORTNAME=	xfig
PORTVERSION=	3.2.5c
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/mcj/mcj-source/
DISTNAME=	${PORTNAME}.${PORTVERSION}.full

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Drawing program for X11

LIB_DEPENDS=	libpng.so:graphics/png \
		libXaw3d.so:x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:print/transfig

CONFLICTS=	xfig-[12].* xfig-3.1* xfig-3.2.[1234]*

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

USES=		imake jpeg
USE_XORG=	ice sm x11 xaw xext xi xmu xpm xt
USE_CSTD=	gnu89
CFLAGS+=	-Wno-return-type
INSTALL_TARGET=	install install.libs

MAKE_ENV+=	DOCSDIR=${DOCSDIR} CHMOD=${CHMOD} TAR=${TAR}
MAKE_ARGS+=	INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} -m ${BINMODE}" \
		INSTDATFLAGS="-m ${SHAREMODE}" \
		INSTMANFLAGS="-m ${MANMODE}"

OPTIONS_DEFINE=	GHOSTSCRIPT I18N DOCS
OPTIONS_DEFAULT=	GHOSTSCRIPT I18N
I18N_DESC=	I18N support and Japanese docs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=	install.html
.endif

.if ! ${PORT_OPTIONS:MI18N} || ! ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	JPORTDOCS="@comment "
.else
PLIST_SUB=	JPORTDOCS=""
.endif

.if ${PORT_OPTIONS:MI18N}
USES+=	gettext
.endif

post-extract:
	@cd ${WRKSRC}/Doc && ${FIND} . -type f -name "*.orig" -delete
	@${RM} ${WRKSRC}/Doc/html/images/pspbrwse.jbf
	@${RM} ${WRKSRC}/Libraries/Examples/xfig.exe.stackdump
	@${RM} ${WRKSRC}/Libraries/Fasteners/Fasteners.tar
	@cd ${WRKSRC}/Doc && ${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} a-x+r
	@cd ${WRKSRC}/Libraries && ${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} a-x+r
	@${CP} ${WRKSRC}/Doc/xfig.man ${WRKSRC}

post-patch:
.if ! ${PORT_OPTIONS:MGHOSTSCRIPT}
.if ! ${PORT_OPTIONS:MI18N}
	@${REINPLACE_CMD} -e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.else
	@${REINPLACE_CMD} -e '/^XCOMM #define I18N/s|XCOMM ||' \
		-e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.endif
.elif ${PORT_OPTIONS:MI18N}
	@${REINPLACE_CMD} -e '/^XCOMM #define I18N/s|XCOMM ||' ${WRKSRC}/Imakefile
.endif

.include <bsd.port.mk>
