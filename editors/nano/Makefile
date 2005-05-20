# New ports collection makefile for:	nano
# Date created:				12 June 2000
# Whom:				Philippe Lefebvre <nemesis@balistik.net>
#
# $FreeBSD$
#

PORTNAME=	nano
PORTVERSION=	1.2.5
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v1.2/ \
		http://www.ewtoo.org/~astyanax/nano/dist/v1.2/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-all
USE_REINPLACE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		nano
MAN1=		nano.1
MAN5=		nanorc.5

post-build:
	${REINPLACE_CMD} 's:\$$SYSCONFDIR:${PREFIX}/etc:g' \
		${WRKSRC}/${MAN1} ${WRKSRC}/${MAN5} ${WRKSRC}/${INFO:=.info}

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/nanorc.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
