# Ports collection makefile for:	calcurse
# Date created:                         Nov 1, 2005
# Whom:                                 Herbert J. Skuhra <h.skuhra@gmail.com>
#
# $FreeBSD$

PORTNAME=	calcurse
PORTVERSION=	2.9.0
CATEGORIES=	deskutils
MASTER_SITES=	http://calcurse.org/files/ \
		ftp://ftp2.culot.org/culot/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	A text-based calendar and scheduling application

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		calcurse.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e \
		's|^docdir = .*|docdir = ${DOCSDIR}|' \
		${WRKSRC}/doc/Makefile.in
.else
	${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
