# New ports collection makefile for:	eina
# Date created:		Dec 10 2009
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	eina
DISTVERSION=	1.1.0
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Enlightenment API for data types

LICENSE=	LGPL21

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_EFL=	librt_hack libtool_hack
USE_ICONV=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=		--enable-amalgamation

.if !defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=	--enable-install-examples
.else
CONFIGURE_ARGS+=	--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

post-install:
.if defined(NOPORTEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
