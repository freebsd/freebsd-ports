# $FreeBSD$

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.

PORTNAME=	gettext-runtime
PORTREVISION=	0

COMMENT=	GNU gettext runtime libraries and programs

LICENSE=	LGPL21 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/intl/COPYING.LIB
LICENSE_FILE_GPLv3=	${WRKSRC}/../COPYING

.include "${.CURDIR}/../gettext/Makefile.common"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-csharp --disable-java --with-included-gettext \
		ac_cv_lib_rt_sched_yield=no
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USES=		charsetfix cpe iconv libtool tar:xz
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	gettext-runtime

INFO=		autosprintf
CPE_PRODUCT=	gettext
CPE_VENDOR=	gnu

.include <bsd.port.options.mk>

.if ${OPSYS} == DragonFly
CONFIGURE_ARGS+=--disable-threads
.endif

post-patch:
# Do not install csharp and java documentation.
	@${REINPLACE_CMD} -E '/^SUBDIRS =/s/(intl-csharp|intl-java)//g' \
		${WRKSRC}/Makefile.in
# Do not install html copies of manpages.
	@${REINPLACE_CMD} \
		-e '/^all-local:/s/html-local//' \
		-e '/^install-data-local:/s/install-html//' \
		-e '/^installdirs-local:/s/installdirs-html//' \
		${WRKSRC}/libasprintf/Makefile.in ${WRKSRC}/man/Makefile.in

post-install:
	${LN} -s libintl.so.8 ${STAGEDIR}${PREFIX}/lib/libintl.so.9

.include <bsd.port.mk>
