# New ports collection makefile for:   subversion-perl
# Date Created:                6 February 2004
# Whom:                        Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	p5-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Perl bindings for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USE_PERL5=	5.8.0+

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		SVN::Base.3 \
		SVN::Client.3 \
		SVN::Core.3 \
		SVN::Delta.3 \
		SVN::Fs.3 \
		SVN::Ra.3 \
		SVN::Repos.3 \
		SVN::Wc.3

SVN_BUILD_BINDINGS=yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	perl5

do-build:
	cd ${WRKSRC} ; ${MAKE} swig-pl-lib ; ${MAKE} swig-pl

do-install:
	cd ${WRKSRC} ; \
	${REINPLACE_CMD} '/SWIG_PL_DIR/s, install$$, all pure_install,g' ${WRKSRC}/Makefile ; \
	${MAKE} install-swig-pl

.include <bsd.port.post.mk>
