# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	parrot
PORTVERSION=	7.9.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.parrot.org/pub/parrot/releases/supported/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parrot - virtual machine for dynamic languages

LICENSE=	ART20

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		gm4:${PORTSDIR}/devel/m4 \
		pcre-config:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libicudata.so:${PORTSDIR}/devel/icu

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	installable
CONFIGURE_ARGS=	--cc=${CC} --cxx=${CXX} --link=${CXX} \
		--ccflags="${CFLAGS} -I${LOCALBASE}/include" \
		--ld=${CC} --ldflags="${LDFLAGS} -L${LIBDIR} -L${LOCALBASE}/lib" \
		--gc=gms --inline --optimize --parrot_is_shared --verbose \
		--prefix=${PREFIX} \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--lex=${LOCALBASE}/bin/flex \
		--yacc=${LOCALBASE}/bin/bison
CONFIGURE_SCRIPT=	Configure.pl
INSTALL_TARGET=	install-dev
TEST_TARGET=	test
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		bison gmake perl5 shebangfix tar:bzip2
SHEBANG_FILES=	tools/dev/create_language.pl \
		tools/dev/gen_makefile.pl \
		tools/dev/pprof2cg.pl \
		tools/dev/reconfigure.pl
perl_OLD_CMD=	perl

DOCSDIR=	share/doc/${PORTNAME}/${PORTVERSION}
PLIST_SUB=	PARROT_VER="${PORTVERSION}"

BROKEN_ia64=	Does not compile on ia64

do-configure:
	(cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/libparrot.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib/parrot/${PORTVERSION}/dynext/*.so

.include <bsd.port.mk>
