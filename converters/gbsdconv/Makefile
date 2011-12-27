# New ports collection makefile for:	gbsdconv
# Date created:		22 Dec, 2011
# Whom:			buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	gbsdconv
PORTVERSION=	0.2
CATEGORIES=	converters python
MASTER_SITES=	https://github.com/buganini/${PORTNAME}/tarball/${PORTVERSION}/
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	GUI for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	tag_c.0:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsdconv>=7.1:${PORTSDIR}/converters/py-bsdconv \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

GITVERSION=	6de84a5
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-${PORTNAME}-${GITVERSION}
NO_BUILD=	yes

USE_GNOME+=	gtk30
USE_PYTHON=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/gbsdconv

do-install:
	${MKDIR} ${PREFIX}/share/gbsdconv
	${INSTALL_DATA} ${WRKSRC}/gbsdconv.xml ${PREFIX}/share/gbsdconv/
	${INSTALL_DATA} ${WRKSRC}/gbsdconv.png ${PREFIX}/share/gbsdconv/
	${INSTALL_SCRIPT} ${WRKSRC}/gbsdconv ${PREFIX}/bin

.include <bsd.port.mk>
