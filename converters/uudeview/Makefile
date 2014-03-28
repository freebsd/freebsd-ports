# Created by: Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
# $FreeBSD$

PORTNAME=	uudeview
PORTVERSION=	0.5.20
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for uu/xx/Base64/BinHex/yEnc de-/encoding

LICENSE=	GPLv2

LIB_DEPENDS=	libuu.so:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tcl

LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	HISTORY porting.notes
PLIST_FILES=	bin/uudeview bin/uuenview man/man1/uudeview.1.gz \
		man/man1/uuenview.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# Try and catch some of the different places that inn and cnews put inews
.if exists(${PREFIX}/bin/inews)
# cnews
CONFIGURE_ARGS+=	--enable-inews=${PREFIX}/bin/inews
.else
# inn by default
CONFIGURE_ARGS+=	--enable-inews=${PREFIX}/news/lib/inews
.endif

post-configure:
	@${REINPLACE_CMD} -E '/INSTALL_/ s,(BIN|MAN)DIR,DESTDIR\)$$\(&,g' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/uudeview
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/uuenview
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/porting.notes ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
