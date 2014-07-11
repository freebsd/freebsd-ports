# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	calcurse
PORTVERSION=	3.2.1
CATEGORIES=	deskutils
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Text-based calendar and scheduling application

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS NLS

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-asciidoc

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|^docdir = .*|docdir = ${DOCSDIR}|' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
