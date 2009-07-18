# New ports collection makefile for:	xfig
# Date created:		4 January 1995
# Whom:			roberto
#
# $FreeBSD$
#

PORTNAME=	xfig
PORTVERSION=	3.2.5
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://files.xfig.org/
DISTNAME=	${PORTNAME}.${PORTVERSION}.full

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drawing program for X11

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xaw3d.8:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

CONFLICTS=	xfig-[12].* xfig-3.1* xfig-3.2.[1234]*

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xi xmu xpm xt
MAN1=		xfig.1
MANCOMPRESSED=	yes

MAKE_ENV+=	DOCSDIR=${DOCSDIR} CHMOD=${CHMOD} TAR=${TAR}
MAKE_ARGS+=	INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} ${_BINOWNGRP} -m ${BINMODE}" \
		INSTDATFLAGS="${_SHROWNGRP} -m ${SHAREMODE}" \
		INSTMANFLAGS="${_MANOWNGRP} -m ${MANMODE}"

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install.libs install.html
.endif

OPTIONS=	GHOSTSCRIPT "Ghostscript support" on \
		I18N "I18N support and Japanese docs" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_I18N) || defined(NOPORTDOCS)
PLIST_SUB+=	JPORTDOCS="@comment "
.else
PLIST_SUB=	JPORTDOCS=""
.endif

post-extract:
	@cd ${WRKSRC}/Doc && ${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} a-x
	@${CHMOD} -R +rX ${WRKSRC}/Libraries/Fasteners
	@cd ${WRKSRC}/Libraries && ${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} a-x
	@${CP} ${WRKSRC}/Doc/xfig.man ${WRKSRC}

post-patch:
.if defined(WITHOUT_GHOSTSCRIPT)
.if defined(WITHOUT_I18N)
	@${REINPLACE_CMD} -e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.else
	@${REINPLACE_CMD} -e '/^XCOMM #define I18N/s|XCOMM ||' \
		-e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.endif
.elif !defined(WITHOUT_I18N)
	@${REINPLACE_CMD} -e '/^XCOMM #define I18N/s|XCOMM ||' ${WRKSRC}/Imakefile
.endif

.include <bsd.port.post.mk>
