# Created by: Craig Leres <leres@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arduino-bsd-mk
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	https://xse.com/leres/arduino/arduino-bsd-mk/ \
		LOCAL/leres/arduino-bsd-mk

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Build Arduino sketches from the command line on FreeBSD

LICENSE=	BSD2CLAUSE

USES=		python:3.5+,run shebangfix

SHEBANG_FILES=	arduino-boards.py

NO_BUILD=	yes
NO_MTREE=	yes

PORTEXAMPLES=	*

PLIST_FILES=	${ALL_FILES} ${ALL_SCRIPTS:R} man/man7/bsd.arduino.mk.7.gz

OPTIONS_DEFINE+=	EXAMPLES

ALL_FILES=	arduino-bsd-mk/bsd.arduino.mk

ALL_SCRIPTS=	arduino-bsd-mk/scripts/arduino-boards.py \
		arduino-bsd-mk/scripts/arduino-version.sh \
		arduino-bsd-mk/scripts/gcc-version.sh

pre-patch:
	# Honor PREFIX in the man page
	${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,' \
	    ${WRKSRC}/bsd.arduino.mk.7

post-install:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}$/${EXAMPLESDIR}

.include <bsd.port.mk>
