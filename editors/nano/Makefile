# Created by: Philippe Lefebvre <nemesis@balistik.net>
# $FreeBSD$

PORTNAME=	nano
PORTVERSION=	2.2.6
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v2.2/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

LICENSE=	GPLv3

CONFLICTS=	nano-devel-2*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS NLS 

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	install_htmlmanDATA=install-htmlmanDATA
.else
MAKE_ARGS+=	install_htmlmanDATA=""
.endif

INFO=		nano

PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--enable-utf8

post-build:
	cd ${WRKSRC}/doc/man; ${REINPLACE_CMD} \
		-e 's:SYSCONFDIR:${PREFIX}/etc:g' \
		-e 's:EXAMPLESDIR:${EXAMPLESDIR}:g' \
		nano.1 rnano.1 nanorc.5 ${WRKSRC}/doc/texinfo/${INFO:=.info}
	${REINPLACE_CMD} -e 's/\\</[[:<:]]/g' -e 's/\\>/[[:>:]]/g' \
		${WRKSRC}/doc/syntax/*.nanorc

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/nanorc.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
