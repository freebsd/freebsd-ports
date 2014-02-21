# Created by: Lev Serebryako <lev@FreeBSD.org>
# $FreeBSD$

PKGNAMEPREFIX=	java-
CATEGORIES=	java

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Java bindings for Version control system

.if defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.elif defined(WITH_SUBVERSION_VER) && ${WITH_SUBVERSION_VER} == 17
MASTERDIR=	${.CURDIR}/../../devel/subversion17
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USE_GCC=	any
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_BUILD=	yes
JAVA_RUN=	yes

SVN_BUILD_BINDINGS=yes

.include "${MASTERDIR}/Makefile.common"

CONFIGURE_ARGS+=	--enable-javahl --with-jdk=${JAVA_HOME} --with-jikes=no

do-build:
	@${MKDIR} ${WRKSRC}/subversion/bindings/java/javahl/classes
	cd ${WRKSRC} ; \
	  ${MAKE} javahl ${MAKE_ARGS}

do-install:
	cd ${WRKSRC} ; \
	  ${MAKE} install-javahl ${MAKE_ARGS}

.include <bsd.port.post.mk>
