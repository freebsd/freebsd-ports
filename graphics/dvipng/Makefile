# ex:ts=8
# Ports collection makefile for:	dvipng
# Date created:			Dec 9, 2003
# Whom:				o_sleep
#
# $FreeBSD$
#

PORTNAME=	dvipng
PORTVERSION=	1.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI to PNG Converter

BUILD_DEPENDS=	kpsepath:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	t1.5:${PORTSDIR}/devel/t1lib \
		gd.4:${PORTSDIR}/graphics/gd

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		dvipng.1
MLINKS=		dvipng.1 dvigif.1
INFO=		dvipng
PLIST_FILES=	bin/dvigif bin/dvipng

IGNORE=		is already included in the teTeX distribution

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvipng ${PREFIX}/bin
	${LN} -sf dvipng ${PREFIX}/bin/dvigif
	${INSTALL_MAN} ${WRKSRC}/dvipng.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/dvipng.info ${PREFIX}/info
	install-info ${PREFIX}/info/dvipng.info ${PREFIX}/info/dir

.include <bsd.port.mk>
