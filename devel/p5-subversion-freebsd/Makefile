# New ports collection makefile for:	p5-subversion-freebsd
# Date Created:				11 August 2011
# Whom:					Wesley Shields <wxs@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-freebsd

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Perl bindings for subversion control system with FreeBSD hacks

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}

USE_PERL5=		5.8.0+

MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=			SVN::Base.3 \
			SVN::Client.3 \
			SVN::Core.3 \
			SVN::Delta.3 \
			SVN::Fs.3 \
			SVN::Ra.3 \
			SVN::Repos.3 \
			SVN::Wc.3

SVN_BUILD_BINDINGS=	yes
WITH_FREEBSD_SUBVERSION=	yes # Force dependency on subversion-freebsd

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	perl5

do-build:
	cd ${WRKSRC} ; ${MAKE} swig-pl-lib ; ${MAKE} swig-pl

do-install:
	cd ${WRKSRC} ; \
	${REINPLACE_CMD} '/SWIG_PL_DIR/s, install$$, all pure_install,g' ${WRKSRC}/Makefile ; \
	${MAKE} install-swig-pl

.include <bsd.port.post.mk>
