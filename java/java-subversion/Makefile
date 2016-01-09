# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	java-
CATEGORIES=	java

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Java bindings for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 18
MASTERDIR=	${.CURDIR}/../../devel/subversion18
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USES+=		compiler

USE_JAVA=	yes
JAVA_VERSION=	1.7+
JAVA_OS=	native
JAVA_BUILD=	yes
JAVA_RUN=	yes

SVN_BUILD_BINDINGS=	yes
SVN_BUILD_ADDONS=	yes

.include "${MASTERDIR}/Makefile.common"

CONFIGURE_ARGS+=	--enable-javahl \
			--with-jdk=${JAVA_HOME} \
			--with-jikes=no \
			--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	javahl
INSTALL_TARGET=	install-javahl

post-configure:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} "s#^LT_CXX_LIBADD = .*#LT_CXX_LIBADD =#" ${WRKSRC}/Makefile
.else
	@${DO_NADA}
.endif

pre-build:
	@${MKDIR} ${WRKSRC}/subversion/bindings/java/javahl/classes

.include <bsd.port.post.mk>
