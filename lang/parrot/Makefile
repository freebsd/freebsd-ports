# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	parrot
PORTVERSION=	${PARROT_VERSION}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.parrot.org/pub/parrot/releases/stable/${PORTVERSION}/

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parrot - virtual machine for dynamic languages

LICENSE=	ART20

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/gm4:${PORTSDIR}/devel/m4 \
		${LOCALBASE}/bin/pcre-config:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libicudata.so:${PORTSDIR}/devel/icu

CONFLICTS=	rakudo-[0-9]*

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	installable
CONFIGURE_ARGS=	--cc=${CC} --ccflags="${CFLAGS}" --cxx=${CXX} --link=${CXX} \
		--ld=${CC} --ldflags="${LDFLAGS} -L${LIBDIR} -L${LOCALBASE}/lib" \
		--gc=gms --inline --optimize --parrot_is_shared --verbose \
		--prefix=${PREFIX} \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--lex=${LOCALBASE}/bin/flex \
		--yacc=${LOCALBASE}/bin/bison
CONFIGURE_SCRIPT=	Configure.pl
INSTALL_TARGET=	install-dev
MAKE_JOBS_UNSAFE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		bison gmake perl5

MAN1=		ops2c.1 \
		parrot.1 \
		parrot-nqp.1 \
		parrot-prove.1 \
		parrot_config.1 \
		parrot_nci_thunk_gen.1 \
		parrotbug.1 \
		pbc_to_exe.1 \
		plumage.1 \
		winxed.1

PARROT_SHARE_DIR=	share/doc/${PORTNAME}/${PORTVERSION}
PARROT_DOCS=		${PARROT_SHARE_DIR}
PLIST_SUB+=	PARROT_VER="${PORTVERSION}" \
		PARROT_DOCS="${PARROT_DOCS}"

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.common"
.include <bsd.port.pre.mk>

.if ${ARCH} == ia64
BROKEN=		Does not compile on ia64
.endif

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^installable: / s| docs | |' ${WRKSRC}/config/gen/makefiles/root.in
.endif

do-configure:
	cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

regression-test test: build
	cd ${WRKSRC} && ${MAKE} test

x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,${PARROT_DOCS}(/.+)?$$,%%PARROT_DOCS%%\1,g \
		;s,${PARROT_SHARE_DIR}(/.+)?$$,%%DOCSDIR%%\1,g \
		;s,${PORTVERSION}(/.+)?$$,%%PARROT_VER%%\1,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.post.mk>
