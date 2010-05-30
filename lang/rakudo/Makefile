# New ports collection makefile for:	rakudo
# Date created:    15 March 2009
# Whom:            Aliaksandr Zahatski <zahatski@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rakudo
PORTVERSION=	2010.04
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://cloud.github.com/downloads/rakudo/rakudo/

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Rakudo Perl 6 Compiler targets the Parrot Virtual Machine

BUILD_DEPENDS=	parrot>=${PARROT_VERSION}:${PORTSDIR}/lang/parrot
LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu
RUN_DEPENDS=	parrot>=${PARROT_VERSION}:${PORTSDIR}/lang/parrot

BROKEN=		does not build

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=	dependency devel/icu is broken on 6.x
.endif

USE_BISON=	build
USE_PERL5_BUILD=	5.8.0+
USE_GMAKE=	yes

INSTALL_TARGET=	install

MAN1=		perl6.1
MANCOMPRESSED=	no

PARROTCONFIG?=	${LOCALBASE}/bin/parrot_config
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=	--parrot-config=${PARROTCONFIG}
PLIST_SUB+=	PARROT_VERSION=${PARROT_VERSION}

do-configure:
	cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-install:
	${INSTALL_MAN} ${WRKSRC}/perl6.1 ${MAN1PREFIX}/man/man1/perl6.1

test: build
	${MAKE} -C ${WRKSRC} test

regression-test: test

x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
	's,.*share/nls/.+$$,,g \
	;s,${PARROT_VERSION}(/.+)?$$,%%PARROT_VERSION%%\1,g \
	' | ${TR} -s '\n') > temp-pkg-plist

.include "${.CURDIR}/../parrot/Makefile.common"

.include <bsd.port.post.mk>
