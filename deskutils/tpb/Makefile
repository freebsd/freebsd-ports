# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tpb
PORTVERSION=	0.6.4
PORTREVISION=	11
CATEGORIES=	deskutils
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	On-Screen-Display for hotkeys of IBM ThinkPads

LICENSE=	GPLv2

LIB_DEPENDS=	libxosd.so:misc/xosd

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

ONLY_FOR_ARCHS=	i386 amd64

USES=		bison gmake iconv pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALABASE}/lib

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
.for i in man/tpb.1 src/cfg.h
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e \
		's|void test()||' ${WRKSRC}/configure

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} tpbrc \
		${STAGEDIR}${PREFIX}/etc/tpbrc.default)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} callback_example.sh \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
