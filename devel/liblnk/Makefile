# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	liblnk
PORTVERSION=	20121121
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tools to access the Windows Shortcut File (LNK) Format

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		lnkinfo.1
MAN3=		liblnk.3

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS ChangeLog

post-patch:
	@${REINPLACE_CMD} -e 's,$$(libdir)/pkgconfig,@prefix@/libdata/pkgconfig,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
