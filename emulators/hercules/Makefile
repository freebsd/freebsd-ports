# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	hercules
PORTVERSION=	3.10
CATEGORIES=	emulators
MASTER_SITES=	http://downloads.hercules-390.eu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System/370, ESA/390, and z/Architecture Emulator

USES=		iconv perl5 shebangfix
SHEBANG_FILES=	util/bldlvlck
USE_AUTOTOOLS=	libtool libltdl
CONFIGURE_ARGS=	--enable-optimization="no"
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

post-extract:
	@${RM} -f ${WRKSRC}/ltdl.h

post-patch:
	@${REINPLACE_CMD} -e \
		'/LIBS/s|-lpthread|-pthread|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|SOL_TCP|IPPROTO_TCP|g' ${WRKSRC}/hscutl.c
	@${REINPLACE_CMD} -e \
		'/^pkgdatadir/s|=.*|= $$(docdir)|' ${WRKSRC}/html/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^libherc_la_LIBADD/s|=|= -lltdl |g'

.include <bsd.port.mk>
