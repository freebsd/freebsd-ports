# $FreeBSD$

PORTNAME=	chirp
PORTVERSION=	0.3.0
CATEGORIES=	comms hamradio
MASTER_SITES=	http://chirp.danplanet.com/download/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Chirp is a free, open-source tool for programming your amateur radio

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/serial:${PORTSDIR}/comms/py-serial \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	YES
USE_PYDISTUTILS=	YES
MAN1=		chirpw.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/chirpui/mainapp.py

post-install:
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}  ${WRKSRC}/COPYING ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
