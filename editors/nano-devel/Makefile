# $FreeBSD$

PORTNAME=	nano
PORTVERSION=	2.3.2
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

CONFLICTS=	nano-2*

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
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

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--enable-utf8

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
