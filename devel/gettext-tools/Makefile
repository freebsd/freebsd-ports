# $FreeBSD$

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.

PORTNAME=	gettext-tools
PORTREVISION=	0

COMMENT=	GNU gettext development and translation tools

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

.include "${.CURDIR}/../gettext/Makefile.common"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-csharp --disable-java --disable-openmp \
		--with-included-glib --with-included-libcroco \
		--with-included-libunistring --with-included-libxml \
		--without-emacs --without-git ac_cv_lib_rt_sched_yield=no
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
PLIST_SUB=	VERSION=${PORTVERSION:R}
TEST_TARGET=	check
USES=		charsetfix cpe gettext-runtime iconv libtool tar:xz
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	gettext-tools

CPE_PRODUCT=	gettext
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS THREADS
OPTIONS_DEFAULT=THREADS
OPTIONS_EXCLUDE_DragonFly=	THREADS

DOCS_INFO=	gettext

THREADS_CONFIGURE_ENABLE=	threads

post-patch-DOCS-off:
	@${REINPLACE_CMD} '/^SUBDIRS =/s/doc//' ${WRKSRC}/Makefile.in

post-patch:
# Exclude examples and gnulib-tests.
	@${REINPLACE_CMD} -E '/^SUBDIRS =/s/(examples|gnulib-tests)//g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		'/^install-data-am:/s/install-examplesbuildauxDATA//' \
		${WRKSRC}/Makefile.in ${WRKSRC}/m4/Makefile.in
# Do not install html copies of manpages.
	@${REINPLACE_CMD} \
		-e '/^all-local:/s/html-local//' \
		-e '/^install-data-local:/s/install-html//' \
		-e '/^installdirs-local:/s/installdirs-html//' \
		${WRKSRC}/man/Makefile.in
# Do not patch system float.h.
	@${REINPLACE_CMD} 's/FLOAT_H=float\.h//' \
		${WRKSRC}/configure
# Use libintl installed by gettext-runtime.
	@${REINPLACE_CMD} '/^LDADD_no =/s,\.\./intl/libgnuintl.la,,' \
		${WRKSRC}/tests/Makefile.in
# Use libasprintf installed by gettext-runtime.
	@${REINPLACE_CMD} 's,[^ ]*libasprintf.la,-lasprintf,' \
		${WRKSRC}/tests/lang-c++

.include <bsd.port.mk>
