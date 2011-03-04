# New ports collection makefile for:	nano-devel
# Date created:				13 November 2008
# Whom:				Eitan Adler <EitanAdlerList@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	nano
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v${PORTVERSION:R}/ \
		http://www.ewtoo.org/~astyanax/nano/dist/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-devel
#DISTNAME=	nano-${PORTVERSION}pre2

MAINTAINER=	ports@eitanadler.com
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

CONFLICTS=	nano-2*

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
MANLANG=	"" fr
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		nano
MAN1=		nano.1 rnano.1
MAN5=		nanorc.5

.include <bsd.port.pre.mk>

# requires wide character curses
.if (${OSVERSION} >= 700000 && ${OSVERSION} < 700033)
CONFIGURE_ARGS+=--disable-utf8
.else
CONFIGURE_ARGS+=--enable-utf8
.endif

post-build:
	cd ${WRKSRC}/doc/man; ${REINPLACE_CMD} \
		-e 's:SYSCONFDIR:${PREFIX}/etc:g' \
		-e 's:EXAMPLESDIR:${EXAMPLESDIR}:g' \
		${MAN1} ${MAN5} ${WRKSRC}/doc/texinfo/${INFO:=.info}
	${REINPLACE_CMD} -e 's/\\</[[:<:]]/g' -e 's/\\>/[[:>:]]/g' \
		${WRKSRC}/doc/syntax/*.nanorc

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/nanorc.sample ${EXAMPLESDIR}

.include <bsd.port.post.mk>
