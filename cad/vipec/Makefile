# ex:ts=8
# New ports collection makefile for:	vipec
# Date created:			April 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vipec
PORTVERSION=	3.1.2b3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ViPEC-${PORTVERSION}

MAINTAINER=	ports@freebsd.org
COMMENT=	Analyze high frequency, linear electrical networks

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_REINPLACE=	yes
USE_QT_VER=	2
USE_GMAKE=	yes
MAKE_ENV+=	TMAKEPATH="${LOCALBASE}/share/tmake/freebsd-g++" \
		QTDIR="${X11BASE}" MOC="${X11BASE}/bin/moc2" \
		SUBLIBS=${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e "s,/opt,,g" ${WRKSRC}/Makefile

pre-install:
	@${RM} -rf ${WRKSRC}/help/models/CVS
	@${RM} -rf ${WRKSRC}/help/CVS
	@${RM} -rf ${WRKSRC}/ckt/CVS
	@${RM} -rf ${WRKSRC}/messages/CVS

.include <bsd.port.mk>
