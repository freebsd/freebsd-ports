# $FreeBSD$

PORTNAME=	chirp
PORTVERSION=	0.3.1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://chirp.danplanet.com/download/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Chirp is a free, open-source tool for programming your amateur radio

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/serial:${PORTSDIR}/comms/py-serial \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	YES
USE_PYDISTUTILS=	YES

.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/chirpui/mainapp.py

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA}  ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
