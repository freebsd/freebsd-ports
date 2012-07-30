# New ports collection makefile for:	rakudo
# Date created:    15 March 2009
# Whom:            Aliaksandr Zahatski <zahatski@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rakudo
PORTVERSION=	2012.07
PORTEPOCH=	3
CATEGORIES=	lang
MASTER_SITES=	http://cloud.github.com/downloads/rakudo/star/
DISTNAME=	${PORTNAME}-star-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Rakudo Perl 6 Compiler targets the Parrot Virtual Machine

LICENSE=	ART20

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/pcre-config:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu \
		gmp.10:${PORTSDIR}/math/gmp

CONFLICTS=	parrot-[0-9]*

PARROT_VERSION=4.6.0
INSTALL_TARGET=	install
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_PARROT_ARGS=	--cc=${CC} --cxx=${CXX} --ld=${CC} --ccflags="${CFLAGS}" \
		--ldflags="${LDFLAGS} -L/usr/lib -L${LOCALBASE}/lib" \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--optimize --parrot_is_shared --inline \
		--lex=${LOCALBASE}/bin/flex \
		--yacc=${LOCALBASE}/bin/bison \
		--verbose \
		--prefix=${PREFIX}
CONFIGURE_ARGS=	--with-parrot=${PREFIX}/bin/parrot \
		--with-nqp=${PREFIX}/bin/nqp

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

USE_BISON=	build
USE_PERL5_BUILD=	5.8.0+
USE_GMAKE=	yes

MAN1=		perl6.1 rakudo.1
MANCOMPRESSED=	no

PLIST_SUB+=	PARROT_VERSION=${PARROT_VERSION}

EXTRA_DOCS=	UsingPerl6-draft.pdf cheatsheet.txt

PORTDOCS=	${EXTRA_DOCS}

do-configure:
	cd ${WRKSRC}/parrot-${PARROT_VERSION} \
	&& ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_PARROT_ARGS} \
	&& ${MAKE} installable PREFIX=${PREFIX}

do-build:

do-install:
	cd ${WRKSRC}/parrot-${PARROT_VERSION} \
	&& ${MAKE} install-dev PREFIX=${PREFIX} \
	&& cd ${WRKSRC}/nqp-2012.07 \
	&& ${PERL} ${CONFIGURE_SCRIPT} --with-parrot=${PREFIX}/bin/parrot \
					--prefix=${PREFIX} \
	&& ${MAKE} install PREFIX=${PREFIX} \
	&& cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}\
	&& ${MAKE} PREFIX=${PREFIX} && ${MAKE} ${INSTALL_TARGET} PREFIX=${PREFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/perl6.1 ${MAN1PREFIX}/man/man1/perl6.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${EXTRA_DOCS:S!^!${WRKSRC}/docs/!} ${DOCSDIR}/
.endif

test: build
	${MAKE} -C ${WRKSRC} test

regression-test: test

x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
	's,.*share/nls/.+$$,,g \
	;s,${PARROT_VERSION}(/.+)?$$,%%PARROT_VERSION%%\1,g \
	' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.post.mk>
