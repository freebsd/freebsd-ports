# Created by: Matthew Ranostay <mranostay@saberlogic.com>
# $FreeBSD$

PORTNAME=	sabernetdcs
PORTVERSION=	2.0.3
PORTREVISION=	9
CATEGORIES=	finance www
MASTER_SITES=	SF/${PORTNAME}/SaberNet%20DCS/${PORTVERSION}
PKGNAMESUFFIX=	-client
DISTNAME=	sndcs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SaberNet DCS - A labor data collection system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyro>=0:${PORTSDIR}/devel/py-pyro

USE_GNOME=	pygtk2
USE_PYTHON=	distutils
USES=		python tar:bzip2
DOCSDIR=	${PREFIX}/share/doc/sndcs
DATADIR=	${PREFIX}/share/sndcs
SUB_FILES=	pkg-message

PYDISTUTILS_PKGNAME=	sndcs

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-setup.py
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

do-configure:
	cd ${WRKSRC} && ${CP} "${FILESDIR}/sndcs2.conf" "sndcs/config/sndcs2.conf"

post-install:

.include <bsd.port.mk>
