# New ports collection makefile for:	shujit
# Date created:		30 April 1999
# Whom:			jake@checker.org
#
# $FreeBSD$
#

PORTNAME=	shujit
PORTVERSION=	0.7.10
CATEGORIES=	java
MASTER_SITES=	http://www.shudo.net/jit/dist/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${JAVADIR}/bin/javac:${PORTSDIR}/java/jdk
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

WRKSRC=		${WRKDIR}/${PORTNAME}
ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
MAKEFILE=	GNUmakefile

USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes

JAVADIR?=	${LOCALBASE}/jdk1.1.8
JAVALIBDIR=	${PREFIX}/lib/${PORTNAME}
CONFIGURE_ARGS+=	--with-jdk="${JAVADIR}"
MAKE_ENV=	JAVADIR="${JAVADIR}"

post-configure:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/README

do-install:
	@${MKDIR} ${JAVALIBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/libshujit.so ${JAVALIBDIR}

post-install:
	@${MKDIR} ${PREFIX}/share/shujit
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/shujit
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${PREFIX}/share/shujit/README for usage instructions."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
