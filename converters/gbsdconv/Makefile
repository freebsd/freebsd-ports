# New ports collection makefile for:	gbsdconv
# Date created:		22 Dec, 2011
# Whom:			buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	gbsdconv
PORTVERSION=	0.3
CATEGORIES=	converters python
MASTER_SITES=	https://github.com/buganini/${PORTNAME}/tarball/${PORTVERSION}/
DISTNAME=	buganini-${PORTNAME}-${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	GUI for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	tag_c.0:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsdconv>=7.2:${PORTSDIR}/converters/py-bsdconv \
		${LOCALBASE}/bin/g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

GITVERSION=	eab9940
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/buganini-${PORTNAME}-${GITVERSION}

NO_BUILD=	yes
USE_GNOME=	gtk30
USE_PYTHON=	yes

PLIST_FILES=	bin/gbsdconv \
		%%DATADIR%%/gbsdconv.png \
		%%DATADIR%%/gbsdconv.xml \
		%%DATADIR%%/gbsdconv2.png
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/gbsdconv

do-install:
	${MKDIR} ${DATADIR}/
	cd ${WRKSRC}/ && \
		${INSTALL_SCRIPT} gbsdconv ${PREFIX}/bin/ && \
		${INSTALL_DATA} gbsdconv.png gbsdconv.xml gbsdconv2.png ${DATADIR}/

.include <bsd.port.mk>
