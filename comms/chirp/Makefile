# $FreeBSD$

PORTNAME=	chirp
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://chirp.danplanet.com/download/${PORTVERSION}/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Chirp is a free, open-source tool for programming your amateur radio

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/serial:${PORTSDIR}/comms/py-serial \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USES=		gettext python desktop-file-utils
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
