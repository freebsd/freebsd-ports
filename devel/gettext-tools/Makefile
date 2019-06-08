# $FreeBSD$

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.

PORTNAME=	gettext-tools
PORTREVISION=	0

COMMENT=	GNU gettext development and translation tools

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/../COPYING

.include "${.CURDIR}/../gettext/Makefile.common"

BUILD_DEPENDS=	libtextstyle>=${PORTVERSION}:devel/libtextstyle
LIB_DEPENDS=	libtextstyle.so:devel/libtextstyle

USES=		charsetfix cpe gettext-runtime iconv libtool tar:xz
USE_LDCONFIG=	yes

CPE_PRODUCT=	gettext
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-csharp --disable-java --disable-openmp \
		--with-included-glib --with-included-libcroco \
		--with-included-libunistring --with-included-libxml \
		--without-emacs --without-git ac_cv_lib_rt_sched_yield=no
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
WRKSRC_SUBDIR=	gettext-tools

DATADIR=	${PREFIX}/share/gettext
DOCSDIR=	${PREFIX}/share/doc/gettext
PLIST_SUB=	PORTVERSION=${PORTVERSION} VERSION=${PORTVERSION:R}

INFO=		gettext

OPTIONS_DEFINE=	DOCS EXAMPLES THREADS
OPTIONS_DEFAULT=THREADS
OPTIONS_EXCLUDE_DragonFly=	THREADS

THREADS_CONFIGURE_ENABLE=	threads

post-patch:
# Do not patch system float.h.
	@${REINPLACE_CMD} 's/FLOAT_H=float\.h//' \
		${WRKSRC}/configure
# Use libintl installed by gettext-runtime.
	@${REINPLACE_CMD} '/^LDADD_no =/s,\.\./intl/libgnuintl.la,,' \
		${WRKSRC}/tests/Makefile.in
# Use libasprintf installed by gettext-runtime.
	@${REINPLACE_CMD} 's,[^ ]*libasprintf.la,-lasprintf,' \
		${WRKSRC}/tests/lang-c++
# Use system libtextstyle.
	@${REINPLACE_CMD} \
		-e '/:/!s,[[:<:]]textstyle[^[:space:]]*\.h,,g' \
		-e 's,\.\./\.\./libtextstyle/lib/libtextstyle\.la,-ltextstyle,' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
