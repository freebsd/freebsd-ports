# $FreeBSD$

PORTNAME=	listserialc
PORTVERSION=	1.1.0
CATEGORIES=	devel java

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Simple multiplatform program to list serial ports with vid/pid/iserial

LICENSE=	LGPL3+

LIB_DEPENDS=	libserialport.so:devel/libserialport

USE_GITHUB=	yes
GH_ACCOUNT=	arduino
GH_PROJECT=	listSerialPortsC

USE_JAVA=	yes
USE_LDCONFIG=	yes
MAKE_ARGS+=	JAVA_HOME=${JAVA_HOME}

CFLAGS+=	-I${LOCALBASE}/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd
LDFLAGS+=	-L${LOCALBASE}/lib -lusb -lserialport

PLIST_FILES=	bin/listSerialC lib/jni/liblistSerialsj.so

do-build:
	@(cd ${WRKSRC} && \
		${CC} ${CFLAGS} main.c ${LDFLAGS} -o listSerialC && \
		${CC} ${CFLAGS} jnilib.c ${LDFLAGS} -shared -fPIC -o liblistSerialsj.so)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/jni
	${INSTALL_PROGRAM} ${WRKSRC}/listSerialC ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/liblistSerialsj.so ${STAGEDIR}${PREFIX}/lib/jni

.include <bsd.port.mk>
