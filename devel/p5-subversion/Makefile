# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PKGNAMEPREFIX=	p5-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Perl bindings for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 17
MASTERDIR=	${.CURDIR}/../../devel/subversion17
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
MASTERDIR=	${.CURDIR}/../../devel/subversion18
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USES=		perl5
USE_PERL5=	build run

SVN_BUILD_BINDINGS=	yes
SVN_BUILD_ADDONS=	yes

MAKE_JOBS_UNSAFE=	yes

.include "${MASTERDIR}/Makefile.common"

CATEGORIES+=	perl5

CONFIGURE_ARGS+=	--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-pl-lib swig-pl
INSTALL_TARGET=	install-swig-pl

pre-install:
	${REINPLACE_CMD} '/SWIG_PL_DIR/s, install$$, all pure_install,g' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
