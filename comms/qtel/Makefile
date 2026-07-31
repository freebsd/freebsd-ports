PORTNAME=	qtel

COMMENT=	Qtel Echolink client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libecholib.so:comms/svxlink \
		libgsm.so:audio/gsm

MASTERDIR=	${.CURDIR}/../svxlink
USES=		qt:6
USE_QT=		base 5compat tools
USE_GL=		gl opengl
PKGDIR=		${.CURDIR}
CMAKE_ARGS+=	-DUSE_QT:BOOL=YES \
		-DQT_ONLY:BOOL=YES

.include "${MASTERDIR}/Makefile"
