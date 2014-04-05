# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	giflib
PORTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-4.x
PKGNAMESUFFIX=	${NOX11SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	libungif-[0-9]*
PORTSCOUT=	limit:^4\.

USES=		tar:bzip2
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LMAN1=	gif2rgb.1 gifasm.1 gifbg.1 gifclip.1 gifclrmp.1 gifcolor.1 gifcomb.1 \
	gifcompose.1 giffiltr.1 giffix.1 gifflip.1 gifhisto.1 gifinter.1 \
	gifinto.1 gifovly.1 gifpos.1 gifrotat.1 gifrsize.1 gifspnge.1 \
	giftext.1 gifwedge.1 icon2gif.1 raw2gif.1 rgb2gif.1 text2gif.1

OPTIONS_DEFINE=	DOCBOOK X11
OPTIONS_SUB=	yes
DOCBOOK_DESC=	Generate API documentation (requires DOCS)

X11_CONFIGURE_ENABLE=	x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto \
	${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-xml
PLIST_SUB+=	WITH_DOCBOOK=''
.else
PLIST_SUB+=	WITH_DOCBOOK='@comment '
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 sm ice
CPPFLAGS+=	-I${LOCALBASE}/include
LMAN1+=		gif2x11.1
.else
NOX11SUFFIX=	-nox11
.endif

post-patch:
	${CP} ${FILESDIR}/quantize.c ${WRKSRC}/lib/
.if ! ${PORT_OPTIONS:MDOCBOOK} || ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} \
		-e 's|SUBDIRS = lib util doc pic|SUBDIRS = lib util pic|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.for i in ${LMAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${STAGEDIR}${PREFIX}/man/man1/
.endfor
.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
