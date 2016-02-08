# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	calcurse
PORTVERSION=	4.0.0
CATEGORIES=	deskutils
MASTER_SITES=	http://calcurse.org/files/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Text-based calendar and scheduling application

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

USES=		gmake ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-asciidoc

DOCS_CONFIGURE_ENABLE=	docs
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|^docdir = .*|docdir = ${DOCSDIR}|' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|-R$$found_dir||' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
