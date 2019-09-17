# $FreeBSD$

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.

PORTNAME=	gettext-runtime
PORTREVISION=	0

COMMENT=	GNU gettext runtime libraries and programs

LICENSE=	LGPL21+ GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21+ =	${WRKSRC}/intl/COPYING.LIB
LICENSE_FILE_GPLv3+ =	${WRKSRC}/../COPYING

.include "${.CURDIR}/../gettext/Makefile.common"

USES=		charsetfix cpe iconv libtool tar:xz
USE_LDCONFIG=	yes

CPE_PRODUCT=	gettext
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-csharp --disable-java --with-included-gettext \
		ac_cv_lib_rt_sched_yield=no
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
WRKSRC_SUBDIR=	gettext-runtime

DATADIR=	${PREFIX}/share/gettext
DOCSDIR=	${PREFIX}/share/doc/gettext
INFO=		autosprintf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == DragonFly
CONFIGURE_ARGS+=--disable-threads
.endif

.include <bsd.port.mk>
