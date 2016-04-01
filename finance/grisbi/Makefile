# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	grisbi
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION:C|0$|x|}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal accounting application

LICENSE=	GPLv2

LIB_DEPENDS=	libofx.so:finance/libofx

USES=		tar:bzip2 desktop-file-utils gmake iconv pkgconfig shared-mime-info
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 intltool libxml2
USE_OPENSSL=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e "s|pixmaps help|pixmaps|" ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
