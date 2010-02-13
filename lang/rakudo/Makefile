# New ports collection makefile for:	rakudo
# Date created:    15 March 2009
# Whom:            Aliaksandr Zahatski <zahatski@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rakudo
PORTVERSION=	201001
CATEGORIES=	lang
MASTER_SITES=	http://cloud.github.com/downloads/rakudo/rakudo/
DISTNAME=	rakudo-2010-01

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Rakudo Perl 6 Compiler targets the Parrot Virtual Machine

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		bison:${PORTSDIR}/devel/bison \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		parrot_config:${PORTSDIR}/lang/parrot
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		icudata:${PORTSDIR}/devel/icu

#           				    amd64       i386	sparc
#				9-current       pass        gcc
#				8-stable       	gcc	        pass
#				7-stable        pass        pass
#				6-stable        icu         icu

.include <bsd.port.pre.mk>

.if ${ARCH} == 'i386' && ${OSVERSION} >= 900000
BROKEN=	internal gcc bugs 
.endif

.if ${OSVERSION} >= 800000 && ${OSVERSION} <= 900000
BROKEN=	internal gcc bugs 
.endif

.if ${OSVERSION} < 700000
BROKEN=	dependency devel/icu is broken on 6.x
.endif

USE_BISON=	build
USE_PERL5=	5.8.0+
USE_GMAKE=	yes

USE_LDCONFIG=	yes
INSTALL_TARGET=	install

CONFLICTS=	rakudo-devel-[0-9]

MAN1=		perl6.1
MANCOMPRESSED=	no

PARROTCONFIG?=${PREFIX}/bin/parrot_config
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=	--parrot-config=${PARROTCONFIG}
PLIST_SUB+=	PARROT_VERSION=${PARROT_VERSION}

do-configure:
	cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-install:
	${INSTALL_MAN} ${WRKSRC}/perl6.1 ${PREFIX}/man/man1/perl6.1

x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
	's,.*share/nls/.+$$,,g \
	;s,${PARROT_VERSION}(/.+)?$$,%%PARROT_VERSION%%\1,g \
	' | ${TR} -s '\n') > temp-pkg-plist

.include "${.CURDIR}/../parrot/Makefile.common"

.include <bsd.port.post.mk>
