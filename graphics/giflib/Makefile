# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	giflib
PORTVERSION=	5.0.6
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}
PKGNAMESUFFIX=	${NOX11SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	libungif-[0-9]*

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LMAN1=		gif2raw.1 gif2rgb.1 gifbuild.1 gifclrmp.1 gifecho.1 \
		giffix.1 gifinto.1 giflib.1 giftext.1 giftool.1

OPTIONS_DEFINE=	DOCBOOK DOCS
OPTIONS_SUB=	yes
DOCBOOK_DESC=	Generate API documentation (requires DOCS)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto \
	${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-xml
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCBOOK} || ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} \
		-e 's|SUBDIRS = lib util doc pic|SUBDIRS = lib util pic|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgif.so.6.0.1
.for i in ${LMAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${STAGEDIR}${PREFIX}/man/man1/
.endfor
.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}/
.else
.endif

.include <bsd.port.mk>
