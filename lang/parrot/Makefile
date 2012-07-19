# New ports collection makefile for:	parrot
# Date created:	   15 April 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

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
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		icudata:${PORTSDIR}/devel/icu

MAKE_JOBS_UNSAFE=	yes

USE_BZIP2=	yes
USE_BISON=	build
USE_PERL5=	yes
USE_GMAKE=	yes

USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=	--cc=${CC} --ld=${CC} --ccflags="${CFLAGS}" \
		--ldflags="${LDFLAGS} -L/usr/lib -L${LOCALBASE}/lib" \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--optimize --parrot_is_shared --inline --gc=gms \
		--lex=${LOCALBASE}/bin/flex \
		--yacc=${LOCALBASE}/bin/bison \
		--verbose \
		--prefix=${PREFIX}

INSTALL_TARGET=	install-dev
ALL_TARGET=	installable

.include "${.CURDIR}/Makefile.common"

PARROT_SHARE_DIR=	share/doc/${PORTNAME}/${PORTVERSION}
PARROT_DOCS=		${PARROT_SHARE_DIR}
PLIST_SUB+=	PARROT_VER="${PORTVERSION}" \
		PARROT_DOCS="${PARROT_DOCS}"

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

.include <bsd.port.pre.mk>

.if ${ARCH} == ia64
BROKEN=		Does not compile on ia64
.endif

.include <bsd.port.post.mk>
