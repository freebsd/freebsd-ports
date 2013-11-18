# Created by: MITA Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkscanfax
PORTVERSION=	1.1.8
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	comms tk
MASTER_SITES=	http://shino.pos.to/linux/tkscanfax/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk frontend for fax scan/receive/send program (command is tkfax)

WRKSRC=		${WRKDIR}/${PORTNAME}1

NO_BUILD=	yes
USES+=		tk:wrapper

PLIST_SUB=	TKSCANFAXDIR="${TKSCANFAXDIR:S,^${PREFIX}/,,}"

TKSCANFAXDIR=	${PREFIX}/lib/tkscanfax1

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -i '' -e \
		's|/usr/local/lib|${PREFIX}/lib|g'

do-install:
	@${MKDIR} ${STAGEDIR}${TKSCANFAXDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${TKSCANFAXDIR})
.for file in tkfax tkscan
	${CHMOD} ${BINMODE} ${STAGEDIR}${TKSCANFAXDIR}/${file}
	${CHOWN} ${BINOWN}:${BINGRP} ${STAGEDIR}${TKSCANFAXDIR}/${file}
	${LN} -sf ${TKSCANFAXDIR}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
