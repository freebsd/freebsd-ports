# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tpb
PORTVERSION=	0.6.4
PORTREVISION=	10
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	On-Screen-Display for hotkeys of IBM ThinkPads

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
USES=		bison iconv gmake pkgconfig

CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}

MAN1=		tpb.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/cfg.h \
		${WRKSRC}/man/tpb.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tpbrc ${PREFIX}/etc/tpbrc.default
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/callback_example.sh ${DOCSDIR}
.endif

.include <bsd.port.mk>
