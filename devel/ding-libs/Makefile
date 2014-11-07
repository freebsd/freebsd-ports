# Created by: Andrew Elble <aweits@rit.edu>
# $FreeBSD$

PORTNAME=	ding-libs
DISTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/released/${PORTNAME}/

MAINTAINER=	aweits@rit.edu
COMMENT=	Collection of useful libraries for developers

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB} -lintl

USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f

USES=		iconv gettext libtool pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV+=	DOXYGEN=""

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
.else
CONFIGURE_ARGS=	--docdir=/dev/null
.endif

#fmemopen was commit r246120
.if ${OSVERSION} < 901502
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.am \
		${FILESDIR}/extra-patch-ini__libini_config.sym \
		${FILESDIR}/extra-patch-ini__ini_fileobj.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/collection/collection_tools.c \
		${WRKSRC}/refarray/ref_array.c
	@${REINPLACE_CMD} -e 's|git log -1 &>/dev/null|true|g' \
		${WRKSRC}/configure.ac
.if ${OSVERSION} < 901502
	@${CP} ${FILESDIR}/fmemopen.c ${WRKSRC}/ini/fmemopen.c
	@${CP} ${FILESDIR}/flags.c ${WRKSRC}/ini/flags.c
.endif

.include <bsd.port.mk>
