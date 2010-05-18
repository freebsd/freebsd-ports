# New ports collection makefile for:   subversion-java
# Date Created:                30 June 2008
# Whom:                        Lev Serebryako <lev@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-java
PORTREVISION=	2
CATEGORIES=	java

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Java bindings for Version control system

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}

USE_JAVA=	yes
JAVA_VERSION=	1.2+
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
