# New ports collection makefile for:	spdbv
# Date created:				15 Jan 2002
# Whom:					chuynh@biolateral.com.au
#
# $FreeBSD$
#

PORTNAME=	spdbv
PORTVERSION=	37b2
CATEGORIES=	biology
MASTER_SITES=	http://au.expasy.org/spdbv/program/ \
				http://www.expasy.org/spdbv/program/ \
				http://tw.expasy.org/spdbv/program/ \
				http://cn.expasy.org/spdbv/program/ \
				http://ca.expasy.org/spdbv/program/ \
				http://kr.expasy.org/spdbv/program/ \
				http://inn-prot.weizmann.ac.il/spdbv/program/\
				http://www.usm.maine.edu/spdbv/program/ \
				http://www.genebee.msu.ru/spdbv/program/
DISTNAME=	${PORTNAME}${PORTVERSION}_IRIX_Linux

MAINTAINER=	chuynh@biolateral.com.au

RUN_DEPENDS=	${LINUXBASE}${X11BASE}/lib/libMesaGL.so.3:${PORTSDIR}/graphics/linux_mesa3

SPDBV=	SPDBV

WRKSRC=		${WRKDIR}/SPDBV_DISTRIBUTION

NO_BUILD=	yes
NO_CDROM=	"Must be downloaded direct from Expasy via www interface"

do-install:
	@cd ${WRKSRC}; ${SETENV} PREFIX=${PREFIX} ./install.sh

# PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
