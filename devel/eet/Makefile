# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eet
PORTVERSION=	1.7.4
PORTEPOCH=	2
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment Data Handling Library

LICENSE=	BSD

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina librt_hack libtool_hack
USE_GNOME=	gnomehack pkgconfig
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" OPENSSL_LIBS="-lssl"
CONFIGURE_ARGS=	--disable-gnutls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=--enable-install-examples
.else
CONFIGURE_ARGS+=--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

post-install:
	@${REINPLACE_CMD} -i '' -e 's/ openssl//' ${PREFIX}/libdata/pkgconfig/eet.pc
.if empty(PORT_OPTIONS:MEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
