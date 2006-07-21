# New ports collection makefile for:	optimfrog
# Date created:		22 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	optimfrog
DISTVERSION=	4.520b1
CATEGORIES=	audio linux
MASTER_SITES=	http://bsd1.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/
DISTNAME=	OptimFROG_All_Linux_x86_${DISTVERSION:S/.//}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Lossless audio codec

ONLY_FOR_ARCHS=	amd64 i386

NO_CDROM=	No commercial use
NO_PACKAGE=	No distribution of a modified package
NO_BUILD=	yes
USE_LINUX=	yes
USE_ZIP=	yes
PLIST_FILES=	bin/off bin/ofr bin/ofs

do-install:
	@${BRANDELF} -t Linux ${WRKSRC}/off ${WRKSRC}/ofr ${WRKSRC}/ofs
	@${INSTALL_PROGRAM} ${WRKSRC}/off ${WRKSRC}/ofr ${WRKSRC}/ofs ${PREFIX}/bin/

.include <bsd.port.mk>
