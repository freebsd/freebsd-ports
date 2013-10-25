# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eina
PORTVERSION=	1.7.8
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment API for data types

LICENSE=	LGPL21

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix iconv
USE_EFL=	librt_hack libtool_hack
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-amalgamation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=--enable-install-examples
.else
CONFIGURE_ARGS+=--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

.include <bsd.port.mk>
