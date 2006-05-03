# New ports collection makefile for:   shftool
# Date created:		2003-10-28
# Whom:			Joachim Strombergson <watchman@ludd.ltu.se>
#
# $FreeBSD$
#

PORTNAME=	shftool
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.df.lth.se/~triad/krad/shftool/

MAINTAINER=	watchman@ludd.ltu.se
COMMENT=	Converter for the Standard Hex Format (SHF)

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e 's,^LIBLOC_LIST=.*,LIBLOC_LIST=${LOCALBASE},' \
		${WRKSRC}/configure

.include <bsd.port.mk>
