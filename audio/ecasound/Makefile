# New ports collection makefile for:	ecasound
# Date created:		22 dec 2000
# Whom:			The Anarcat <anarcat@tao.ca>
#
# $FreeBSD$
#

PORTNAME=	ecasound
PORTVERSION=	1.8.5d15
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecawave

MAINTAINER=	anarcat@tao.ca

.if defined(WITH_MPG123)
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
.endif

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_MIKMOD)
RUN_DEPENDS+=	mikmod:${PORTSDIR}/audio/mikmod
.endif

.if defined(WITH_AUDIOFILE)
LIB_DEPENDS+=  audiofile.0:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+= --disable-audiofile
.endif

.if defined(WITH_PYECASOUND)
USE_PYTHON=    yes
PLIST?=                ${PKGDIR}/pkg-plist.py
.else
CONFIGURE_ARGS+= --disable-pyecasound
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN1=		ecasound-iam.1 ecasound.1 ecatools.1
MAN5=		ecasoundrc.5

#post-install:
#	strip ${PREFIX}/bin/ecaconvert ${PREFIX}/bin/ecafixdc \
#${PREFIX}/bin/ecanormalize ${PREFIX}/bin/ecaplay ${PREFIX}/bin/ecasignalview \
#${PREFIX}/bin/ecasound ${PREFIX}/bin/ecasound-config ${PREFIX}/bin/ecasoundc-config

.include <bsd.port.mk>
