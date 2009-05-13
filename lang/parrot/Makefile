# New ports collection makefile for:	parrot
# Date created:	   15 April 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	parrot
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/P/PA/PARTICLE

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Parrot - virtual machine for dynamic languages

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		bison:${PORTSDIR}/devel/bison \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		icudata:${PORTSDIR}/devel/icu

USE_BISON=	build
USE_PERL5=	5.8.0+
USE_GMAKE=	yes

USE_LDCONFIG=	yes
INSTALL_TARGET=	reallyinstall

CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=	--cc=${CC} --cxx=${CXX} --ld=${CC} --ccflags="${CFLAGS}" \
		--ldflags="${LDFLAGS} -L/usr/lib -L${LOCALBASE}/lib" \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--optimize --parrot_is_shared \
		--lex=${LOCALBASE}/bin/flex \
		--yacc=${LOCALBASE}/bin/bison \
		--verbose \
		--prefix=${PREFIX}

PARROT_SHARE_DIR=	share/doc/${PORTNAME}
PARROT_DOCS=		${PARROT_SHARE_DIR}/docs
PARROT_EXAMPLES=	${PARROT_SHARE_DIR}/examples
PLIST_SUB+=	SHLIB_VER="${PORTVERSION}" \
		PARROT_DOCS="${PARROT_DOCS}" \
		PARROT_EXAMPLES="${PARROT_EXAMPLES}"

post-patch:
	${PERL} -pi -e "s=libdir}, 'pkgconfig=prefix}, 'libdata/pkgconfig=" \
		${WRKSRC}/tools/dev/install_files.pl

do-configure:
	cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

test:
	cd ${WRKSRC} && ${MAKE} test

x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,${PARROT_DOCS}(/.+)?$$,%%PARROT_DOCS%%\1,g \
		;s,${PARROT_EXAMPLES}(/.+)?$$,%%PARROT_EXAMPLES%%\1,g \
		;s,${PARROT_SHARE_DIR}(/.+)?$$,%%DOCSDIR%%\1,g \
		;s,${PORTVERSION}(/.+)?$$,%%SHLIB_VER%%\1,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.pre.mk>

# JIT only works on x86
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--jitcapable
PLIST_SUB+=	JIT=""
.else
PLIST_SUB+=	JIT="@comment "
.endif

.if ${ARCH} == ia64
BROKEN=		Does not compile on ia64
.endif

.if defined(PACKAGE_BUILDING)
IGNORE=		needs to be build under non-root user, pointyhat cannot do that
.endif

pre-configure:
	@if [ `${ID} -u` -eq 0 ]; then \
		${ECHO_MSG} "==> Please do not build ${PORTNAME} as 'root' (because of 'perldoc' issue)."; exit 1; fi

.include <bsd.port.post.mk>
