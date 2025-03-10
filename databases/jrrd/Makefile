PORTNAME=	jrrd
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	SF/opennms/JRRD/stable-1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java native interface (JNI) to RRDtool
WWW=		https://www.opennms.org/index.php/Jrrd

LIB_DEPENDS=	librrd.so:databases/rrdtool

USES=		java libtool
JAVA_VENDOR=	openjdk
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}

INSTALL_TARGET=	install-strip

PLIST_FILES=	%%JAVAJARDIR%%/jrrd.jar \
		lib/libjrrd.so

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"Installation settings:"
	@${ECHO_MSG}	"   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG}	"   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG}	""

.include <bsd.port.mk>
