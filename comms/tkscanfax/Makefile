# New ports collection makefile for:	tkscanfax
# Date created:			11 Mai 2002
# Whom:				MITA Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkscanfax
PORTVERSION=	1.1.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	comms tk
MASTER_SITES=	http://shino.pos.to/linux/tkscanfax/

MAINTAINER=	mita@FreeBSD.org
COMMENT=	Tcl/Tk frontend for fax scan/receive/send program (command is tkfax)

USE_TK=		yes
WRKSRC=	${WRKDIR}/${PORTNAME}1
NO_BUILD=	yes

post-extract:
	${FIND} ${WRKSRC} -name '*~' -delete

do-install:
	(\
	cd ${WRKDIR}; \
	${TAR} '--exclude=*.orig' -cf - tkscanfax1 | \
	${TAR} -C ${PREFIX}/lib -xf - ; \
	${LN} -sf ${PREFIX}/lib/tkscanfax1/tkscan ${PREFIX}/bin ; \
	${LN} -sf ${PREFIX}/lib/tkscanfax1/tkfax ${PREFIX}/bin \
	)

.include <bsd.port.mk>
