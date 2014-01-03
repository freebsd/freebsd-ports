# Created by: Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
# $FreeBSD$

PORTNAME=	uudeview
PORTVERSION=	0.5.20
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program for uu/xx/Base64/BinHex/yEnc de-/encoding

LICENSE=	GPLv2

LIB_DEPENDS=	libuu.so:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tcl

LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		uudeview.1 uuenview.1
PORTDOCS=	HISTORY porting.notes
PLIST_FILES=	bin/uudeview bin/uuenview

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Try and catch some of the different places that inn and cnews put inews
.if exists(${PREFIX}/bin/inews)
# cnews
CONFIGURE_ARGS+=	--enable-inews=${PREFIX}/bin/inews
.else
# inn by default
CONFIGURE_ARGS+=	--enable-inews=${PREFIX}/news/lib/inews
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/uudeview
	@${STRIP_CMD} ${PREFIX}/bin/uuenview
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>  Installing documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/HISTORY ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/porting.notes ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
