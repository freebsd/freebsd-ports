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

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-csharp --disable-java --disable-openmp \
		--with-included-glib --with-included-libcroco \
		--with-included-libunistring --with-included-libxml \
		--without-emacs --without-git ac_cv_lib_rt_sched_yield=no
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		charsetfix cpe gettext-runtime iconv libtool tar:xz
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	gettext-tools

CPE_PRODUCT=	gettext
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO+=		gettext
.endif

.if ${OPSYS} == DragonFly || (${OPSYS} == FreeBSD && ${OSVERSION} < 900506)
CONFIGURE_ARGS+=--disable-threads
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} '/^SUBDIRS =/s/doc//' ${WRKSRC}/Makefile.in
.endif
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

regression-test: build
	@(cd ${WRKSRC} && ${MAKE_CMD} check)

.include <bsd.port.mk>
