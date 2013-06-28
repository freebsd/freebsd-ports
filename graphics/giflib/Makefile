# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	giflib
PORTVERSION=	4.2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-4.x
PKGNAMESUFFIX=	${NOX11SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	libungif-[0-9]*
PORTSCOUT=	limit:^4\.

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCBOOK X11
DOCBOOK_DESC=	Generate API documentation (requires DOCS)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto \
		${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-sk
PLIST_SUB+=	WITH_DOCBOOK=''
.else
PLIST_SUB+=	WITH_DOCBOOK='@comment '
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	sm x11
PLIST_SUB+=	X11=''
CPPFLAGS+=	-I${LOCALBASE}/include
.else
PLIST_SUB+=	X11='@comment '
CONFIGURE_ARGS+=	--with-x=no
NOX11SUFFIX=	-nox11
.endif

post-patch:
	${CP} ${FILESDIR}/quantize.c ${WRKSRC}/lib/
.if ! ${PORT_OPTIONS:MDOCBOOK} || ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|SUBDIRS = lib util doc pic|SUBDIRS = lib util pic|' \
		${WRKSRC}/Makefile.in
.endif

.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
