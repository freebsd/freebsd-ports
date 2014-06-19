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

.if !defined(NOPORTDOCS)
INSTALLS_OMF=	yes
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|tests$$||g' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/doc/$$(PACKAGE_NAME)-$$(PACKAGE_VERSION)|${DOCSDIR}|g'
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|data doc|data|g' \
			  -e '/^install-data-local:/,/^$$/d' \
			  -e 's|install-data-local||' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
