# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	jtag
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/openwince/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to work with JTAG-aware boards

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${OPENWINCE_INCLUDE_DEP}:devel/openwince-include

ONLY_FOR_ARCHS=	i386

USES=		readline tar:bzip2
GNU_CONFIGURE=	yes

PORTDOCS=	*

OPENWINCE_INCLUDE=${LOCALBASE}/include/openwince
OPENWINCE_INCLUDE_DEP=${OPENWINCE_INCLUDE}/common.h

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-extract:
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/include/openwince,${OPENWINCE_INCLUDE}," \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README TODO doc/internals.xml \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
