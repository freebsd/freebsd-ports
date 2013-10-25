# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	main
PORTVERSION=	1.7.8
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	ecore-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (main library)

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig iconv
USE_EFL=	eina libtool_hack
USE_LDCONFIG=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/ecore

.include "Makefile.inc"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=--enable-install-examples
.else
CONFIGURE_ARGS+=--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

.include <bsd.port.mk>
