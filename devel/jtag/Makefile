# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	jtag
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/openwince/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to work with JTAG-aware boards

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	${OPENWINCE_INCLUDE_DEP}:${PORTSDIR}/devel/openwince-include
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	NLS DOCS

USES=		readline
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

ONLY_FOR_ARCHS=	i386
OPENWINCE_INCLUDE=${LOCALBASE}/include/openwince
OPENWINCE_INCLUDE_DEP=${OPENWINCE_INCLUDE}/common.h

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/include/openwince,${OPENWINCE_INCLUDE}," \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in README TODO doc/internals.xml
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
