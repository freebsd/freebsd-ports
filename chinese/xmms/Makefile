# New ports collection makefile for:	xmms
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../audio/xmms

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	sobomax

MAINTAINER=	clive@CirX.ORG

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf

pre-patch:
	@( cd ${WRKSRC}; \
		${PATCH} -sp1 < ${.CURDIR}/files/extra-patch-xmms-1.2.x-xfont ; )

.include "${MASTERDIR}/Makefile"
