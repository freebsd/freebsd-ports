# $FreeBSD$

PORTNAME=	chirp
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://chirp.danplanet.com/download/${PORTVERSION}/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Free, open-source tool for programming your amateur radio

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libxml2>0:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}serial>0:${PORTSDIR}/comms/py-serial
RUN_DEPENDS=	${BUILD_DEPENDS}

USES=		desktop-file-utils gettext python
USE_PYTHON=	distutils

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/chirpui/mainapp.py

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/share/chirp/images
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
