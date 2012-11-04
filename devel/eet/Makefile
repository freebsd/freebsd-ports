# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eet
DISTVERSION=	1.5.0
PORTEPOCH=	2
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment Data Handling Library

LICENSE=	BSD

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina librt_hack libtool_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" OPENSSL_LIBS="-lssl"
CONFIGURE_ARGS=	--disable-gnutls --enable-amalgamation

.if !defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=	--enable-install-examples
.else
CONFIGURE_ARGS+=	--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

post-install:
	@${REINPLACE_CMD} -i '' -e 's/ openssl//' ${PREFIX}/libdata/pkgconfig/eet.pc
.if defined(NOPORTEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
