PORTNAME=	tijmp
PORTVERSION=	0.8
CATEGORIES=	devel java
MASTER_SITES=	https://www.khelekore.org/jmp/tijmp/ \
		https://www.klop.ws/distfiles/

MAINTAINER=	ronald@FreeBSD.org
COMMENT=	Tools Interface Java Memory Profiler
WWW=		https://www.khelekore.org/jmp/tijmp/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
USE_JAVA=	yes
JAVA_OS=	native
JAVA_BUILD=	jdk
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
INSTALL_TARGET=	install-strip

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar \
		lib/lib${PORTNAME}.so \
		lib/lib${PORTNAME}.so.0 \
		lib/lib${PORTNAME}.so.0.0.1
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-O3

post-patch:
	@${REINPLACE_CMD} '/^jardir =/s|=.*|= ${JAVAJARDIR}|' ${WRKSRC}/Makefile.in
	@${SED} -i "" -e 's|/../share/java|${JAVAJARDIR}|' ${WRKSRC}/src/tijmp.c

.include <bsd.port.mk>
