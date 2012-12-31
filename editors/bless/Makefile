# $FreeBSD$

PORTNAME=	bless
PORTVERSION=	0.6.0
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://download.gna.org/bless/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A high quality, full featured hex editor

USE_GNOME=	gnomehack gnomeprefix gnomedocutils gtksharp20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
INSTALLS_OMF=	yes
.endif

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

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
