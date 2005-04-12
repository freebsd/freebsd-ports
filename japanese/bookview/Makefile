# New ports collection makefile for:	bookview
# Date created:			2 Oct 1997
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	bookview
PORTVERSION=	3.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/bookview/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/net/ndtp/bookview/

MAINTAINER=	takamune2004@yahoo.co.jp
COMMENT=	NDTP client written in Tcl/Tk

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	WISH=${LOCALBASE}/bin/wish8.4

.include <bsd.port.mk>
