# $FreeBSD$

PORTNAME=	cppi
PORTVERSION=	1.18
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Tool to indent the C preprocessor directives

USE_XZ=		yes
USES=		charsetfix gmake	# gmake is needed for -jX builds
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's:(libdir)/lib:(libdir):' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
