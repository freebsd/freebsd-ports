# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PKGNAMEPREFIX=	p5-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Perl bindings for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 17
MASTERDIR=	${.CURDIR}/../../devel/subversion17
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USES=		perl5

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}
MAN3=		SVN::Base.3 \
		SVN::Client.3 \
		SVN::Core.3 \
		SVN::Delta.3 \
		SVN::Fs.3 \
		SVN::Ra.3 \
		SVN::Repos.3 \
		SVN::Wc.3

SVN_BUILD_BINDINGS=yes

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	perl5

do-build:
	cd ${WRKSRC} ; ${MAKE} swig-pl-lib ; ${MAKE} swig-pl

do-install:
	cd ${WRKSRC} ; \
	${REINPLACE_CMD} '/SWIG_PL_DIR/s, install$$, all pure_install,g' ${WRKSRC}/Makefile ; \
	${MAKE} install-swig-pl

.include <bsd.port.post.mk>
