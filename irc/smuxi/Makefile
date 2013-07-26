# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	smuxi
PORTVERSION=	0.8
CATEGORIES=	irc
MASTER_SITES=	http://www.smuxi.org/jaws/data/files/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Smart MUltipleXed Irc

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

BROKEN=		Does not build

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/smartirc4net.pc:${PORTSDIR}/irc/smartirc4net \
		${LOCALBASE}/libdata/pkgconfig/nini-1.1.pc:${PORTSDIR}/devel/nini \
		${LOCALBASE}/libdata/pkgconfig/log4net.pc:${PORTSDIR}/devel/log4net
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool gnomehack gnomesharp20

post-patch:
	@${FIND} ${WRKSRC} -name "${GNOME_MAKEFILEIN}*" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|g ; \
		s|@libdir@/locale|@prefix@/share/locale|g'

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
