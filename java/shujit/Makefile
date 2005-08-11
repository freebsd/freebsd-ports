# New ports collection makefile for:	shujit
# Date created:		30 April 1999
# Whom:			jake@checker.org
#
# $FreeBSD$
#

PORTNAME=	shujit
PORTVERSION=	0.8.0
CATEGORIES=	java
MASTER_SITES=	http://www.shudo.net/jit/dist/

MAINTAINER=	java@FreeBSD.org
COMMENT=	A Just In Time java bytecode compiler

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm

WRKSRC=		${WRKDIR}/${PORTNAME}
ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.1 1.2 1.3
CONFIGURE_ARGS=	--with-jdk="${JAVA_HOME}"
MAKE_ENV=	JAVADIR="${JAVA_HOME}"

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libshujit.so ${PREFIX}/lib

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
