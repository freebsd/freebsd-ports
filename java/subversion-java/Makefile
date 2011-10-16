# New ports collection makefile for:   subversion-java
# Date Created:                30 June 2008
# Whom:                        Lev Serebryako <lev@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-java
CATEGORIES=	java

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Java bindings for Version control system

.if defined(USE_SUBVERSION) && ${USE_SUBVERSION} == 16
MASTERDIR=	${.CURDIR}/../../devel/subversion16
.else
MASTERDIR=	${.CURDIR}/../../devel/subversion
.endif
PKGDIR=		${.CURDIR}

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
JAVA_BUILD=	yes
JAVA_RUN=	yes

SVN_BUILD_BINDINGS=yes

.include "${MASTERDIR}/Makefile.common"

CONFIGURE_ARGS+=	--enable-javahl --with-jdk=${JAVA_HOME}

do-build:
	@${MKDIR} ${WRKSRC}/subversion/bindings/java/javahl/classes
	cd ${WRKSRC} ; \
	  ${MAKE} javahl

do-install:
	cd ${WRKSRC} ; \
	  ${MAKE} install-javahl

.include <bsd.port.post.mk>
