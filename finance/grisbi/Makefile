# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	grisbi
PORTVERSION=	0.8.9
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20stable/${PORTVERSION:R}.x/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Personal accounting application

LICENSE=	GPLv2

LIB_DEPENDS=	ofx.5:${PORTSDIR}/finance/libofx

USE_BZIP2=	yes
USES=		gmake iconv pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 libxml2
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
INSTALLS_ICONS=	yes

MAN1=		grisbi.1

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"	\
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e "s|pixmaps help|pixmaps|" ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
