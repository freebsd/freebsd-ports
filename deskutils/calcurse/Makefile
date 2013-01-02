# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	calcurse
PORTVERSION=	3.1.2
CATEGORIES=	deskutils
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Text-based calendar and scheduling application

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS NLS

CONFIGURE_ARGS=	--without-asciidoc
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		calcurse.1

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
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
.if empty(PORT_OPTIONS:MDOCS)
	cd ${WRKSRC}/doc/ && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
