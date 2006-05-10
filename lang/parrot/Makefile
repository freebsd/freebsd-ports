# New ports collection makefile for:	parrot
# Date created:	   15 April 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	parrot
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/L/LT/LTOETSCH

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Parrot - virtual machine for dynamic languages

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4 \
		icudata.34:${PORTSDIR}/devel/icu

BROKEN=		Incorrect pkg-plist

USE_GCC=	3.4+
USE_PERL5=	yes
USE_GMAKE=	yes
#USE_SDL=	yes

INSTALLS_SHLIB=	yes

CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=	--cc=${CC} --cxx=${CXX} --ld=${CC} --ccflags="${CFLAGS}" \
		--ldflags="${LDFLAGS} -L/usr/lib -L${LOCALBASE}/lib" \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--optimize --jitcapable --parrot_is_shared \
		--verbose \
		--prefix=${PREFIX}
#		--verbose

post-patch:
	${PERL} -pi -e "s=libdir}, 'pkgconfig=prefix}, 'libdata/pkgconfig=" \
		${WRKSRC}/tools/dev/install_files.pl

do-configure:
	cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	perl 5.8 or newer required. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
