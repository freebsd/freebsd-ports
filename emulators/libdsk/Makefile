# New ports collection makefile for:   libdsk
# Date created:        31 January 2008
# Whom:                pixel
#
# $FreeBSD$
#

PORTNAME=	libdsk
PORTVERSION=	1.2.1
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.info/Unix/LibDsk/ \
		http://www.hugbox.org/software/ports/

MAINTAINER=	pixel@hugbox.org
COMMENT=	Enables access to disks and disk images; also via serial line

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

MAN1=	apriboot.1 dskdump.1 dskform.1 dskid.1 dskscan.1 dsktrans.1\
	dskutil.1 md3serial.1
MAN5=	libdskrc.5

NO_MANCOMPRESSED=yes

.include <bsd.port.mk>
