# New ports collection makefile for:	shujit
# Date created:		30 April 1999
# Whom:			jake@checker.org
#
# $FreeBSD$
#

PORTNAME=	shujit
PORTVERSION=	0.5.2
CATEGORIES=	java
MASTER_SITES=	http://www.shudo.net/jit/dist/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk

WRKSRC=		${WRKDIR}/shujit
ONLY_FOR_ARCHS=	i386

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
MAKE_FLAGS=
MAKEFILE=
MAKE_ARGS=
ALL_TARGET=

JAVADIR=	${LOCALBASE}/jdk1.1.8
JAVALIBDIR=	${JAVADIR}/lib/i386/green_threads
JAVABINDIR=	${JAVADIR}/bin/i386/green_threads
JAVAOBJFORMAT=	`file ${JAVABINDIR}/java | ${AWK} '{print $$2}'`
CONFIGURE_ARGS+=	--with-jdk="${JAVADIR}"

pre-build:
	@( if [ ${JAVAOBJFORMAT} != ELF ]; then	\
		${CAT} ${PKGDIR}/MESSAGE;	\
		exit 1;				\
	fi; )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libshujit.so ${JAVALIBDIR}

post-install:
	@${MKDIR} ${JAVADIR}/shujit
	@${INSTALL_MAN} ${WRKSRC}/README ${JAVADIR}/shujit
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${JAVADIR}/shujit/README for usage instructions."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
