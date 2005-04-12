# New ports collection makefile for:   shftool
# Date created:		2003-10-28
# Whom:			Joachim Strombergson <watchman@ludd.luth.se>
#
# $FreeBSD$
#

PORTNAME=	shftool
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.df.lth.se/~triad/krad/shftool/

MAINTAINER=	watchman@ludd.luth.se
COMMENT=	Converter for the Standard Hex Format (SHF)

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e 's,^LIBLOC_LIST=.*,LIBLOC_LIST=${LOCALBASE},' \
		${WRKSRC}/configure

.include <bsd.port.mk>
