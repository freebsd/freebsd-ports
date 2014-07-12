# $FreeBSD$

PORTNAME=	bless
PORTVERSION=	0.6.0
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/bless/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	High quality, full featured hex editor

USES=		gmake mono pathfix pkgconfig
USE_GNOME=	gnomeprefix gnomedocutils gtksharp20
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALLS_OMF=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|tests$$||g' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/$$(PACKAGE_NAME)-$$(PACKAGE_VERSION)|${DOCSDIR}|g'

.include <bsd.port.mk>
