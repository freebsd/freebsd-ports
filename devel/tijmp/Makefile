# Created by: Ronald Klop <ronald@echteman.nl>
# $FreeBSD$

PORTNAME=	tijmp
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.khelekore.org/jmp/tijmp/ \
		http://www.klop.ws/distfiles/

MAINTAINER=	ronald-lists@klop.ws
COMMENT=	Tools Interface Java Memory Profiler

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
INSTALL_TARGET=	install-strip
USES=		gmake libtool
USE_JAVA=	yes
JAVA_OS=	native
JAVA_BUILD=	jdk
USE_LDCONFIG=	yes

PLIST_FILES=	lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 \
		lib/lib${PORTNAME}.so.0.0.1 %%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	ChangeLog README

OPTIMIZED_CFLAGS_CFLAGS=	-O3

post-patch:
	@${REINPLACE_CMD} '/^jardir =/s|=.*|= ${JAVAJARDIR}|' ${WRKSRC}/Makefile.in
	@${SED} -i "" -e 's|/../share/java|${JAVAJARDIR}|' ${WRKSRC}/src/tijmp.c

.include <bsd.port.mk>
