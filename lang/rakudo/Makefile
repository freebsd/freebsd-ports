# Created by: Aliaksandr Zahatski <zahatski@gmail.com>
# $FreeBSD$

PORTNAME=	rakudo
PORTVERSION=	2013.10
PORTEPOCH=	4
CATEGORIES=	lang
MASTER_SITES=	http://rakudo.org/downloads/star/
DISTNAME=	${PORTNAME}-star-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Rakudo Perl 6 Compiler targets the Parrot Virtual Machine

LICENSE=	ART20

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/gm4:${PORTSDIR}/devel/m4 \
		${LOCALBASE}/bin/pcre-config:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libicudata.so:${PORTSDIR}/devel/icu

OPTIONS_DEFINE=	DOCS

CONFLICTS=	parrot-[0-9]*

CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_PARROT_ARGS=	--cc=${CC} --ccflags="${CFLAGS}" --cxx=${CXX} --link=${CXX} \
		--ld=${CC} --ldflags="${LDFLAGS} -L${LIBDIR} -L${LOCALBASE}/lib" \
		--gc=gms --inline --optimize --parrot_is_shared --verbose \
		--prefix=${PREFIX} \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--lex=${LOCALBASE}/bin/flex \
		--yacc=${LOCALBASE}/bin/bison
CONFIGURE_ARGS=	--with-parrot=${PREFIX}/bin/parrot \
		--with-nqp=${PREFIX}/bin/nqp
NO_BUILD=	yes
USES=		bison gmake perl5
USE_LDCONFIG=	yes
USE_PERL5=	build

EXTRA_DOCS=	UsingPerl6-draft.pdf cheatsheet.txt
MAN1=		ops2c.1 \
		parrot.1 \
		parrot-nqp.1 \
		parrot-prove.1 \
		parrot_config.1 \
		parrot_nci_thunk_gen.1 \
		parrotbug.1 \
		pbc_to_exe.1 \
		perl6.1 \
		plumage.1 \
		rakudo.1 \
		winxed.1
MANCOMPRESSED=	no
PLIST_SUB=	PARROT_VERSION=${PARROT_VERSION}
PORTDOCS=	*

PARROT_VERSION=	5.9.0

NOT_FOR_ARCHS=	ia64 powerpc sparc64
NOT_FOR_ARCHS_REASON=	does not compile

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-configure:
	cd ${WRKSRC}/parrot \
	&& ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_PARROT_ARGS} \
	&& ${MAKE} installable PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC}/parrot \
	&& ${MAKE} install-dev PREFIX=${PREFIX} \
	&& cd ${WRKSRC}/nqp \
	&& ${PERL} ${CONFIGURE_SCRIPT} --with-parrot=${PREFIX}/bin/parrot \
					--prefix=${PREFIX} \
	&& ${MAKE} ${INSTALL_TARGET} PREFIX=${PREFIX} \
	&& cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}\
	&& ${MAKE} PREFIX=${PREFIX} && ${MAKE} ${INSTALL_TARGET} PREFIX=${PREFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/perl6.1 ${MAN1PREFIX}/man/man1/perl6.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${EXTRA_DOCS} ${DOCSDIR}/
.endif

regression-test test: build
	${MAKE} -C ${WRKSRC} test

x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
	's,.*share/nls/.+$$,,g \
	;s,${PARROT_VERSION}(/.+)?$$,%%PARROT_VERSION%%\1,g \
	' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
