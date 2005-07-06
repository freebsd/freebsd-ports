# New ports collection makefile for:	parrot
# Date created:	   15 April 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	parrot
PORTVERSION=	0.2.2
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/L/LT/LTOETSCH

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Parrot - virtual machine for dynamic languages

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4 \
		icudata.32:${PORTSDIR}/devel/icu

USE_PERL5=	yes
USE_GMAKE=	yes
#USE_SDL=	yes

CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=	--cc=${CC} --ld=${LD} --ccflags="${CFLAGS}" \
		--ldflags="${LDFLAGS} -L/usr/lib -L${LOCALBASE}/lib" \
		--icu-config=${LOCALBASE}/bin/icu-config \
		--optimize --jitcapable --verbose \
		--prefix=${PREFIX}/parrot

do-configure:
	cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	@${PERL} -pi -e 's/(?<=nci_test\$$\(O\)) \$$\(C_LIBS\)//' \
		${WRKSRC}/Makefile

test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=	"Build is broken."
.endif

.if ${PERL_LEVEL} < 500800
IGNORE=	Perl 5.8 or newer required. Install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
