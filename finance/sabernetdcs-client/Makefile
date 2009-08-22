# New ports collection makefile for:   sabernetdcs
# Date created:        29 December 2006
# Whom:                Matthew Ranostay <mranostay@saberlogic.com>
#
# $FreeBSD$
#

PORTNAME=	sabernetdcs
PORTVERSION=	2.0.3
PORTREVISION=	3
CATEGORIES=	finance www
MASTER_SITES=	SF/${PORTNAME}/SaberNet%20DCS/${PORTVERSION}
PKGNAMESUFFIX=	-client
DISTNAME=	sndcs-${PORTVERSION}

MAINTAINER=	mranostay@saberlogic.com
COMMENT=	SaberNet DCS - A labor data collection system

RUN_DEPENDS=	pygtk-codegen-2.0:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHONPREFIX_SITELIBDIR}/gtk-2.0/gobject/__init__.py:${PORTSDIR}/devel/py-gobject \
		${PYTHONPREFIX_SITELIBDIR}/Pyro/__init__.py:${PORTSDIR}/devel/py-ro

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_BZIP2=	yes
DOCSDIR=	${PREFIX}/share/doc/sndcs
DATADIR=	${PREFIX}/share/sndcs

PYDISTUTILS_PKGNAME=	sndcs

.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-setup.py
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/setup.py

do-configure:
	cd ${WRKSRC} && ${CP} "${FILESDIR}/sndcs2.conf" "sndcs/config/sndcs2.conf"

post-install:
	@${ECHO} "	- - - - - - - - - - - - - - - - - - - - - - - - -"
	@${ECHO} "	SaberNet DCS Client is now installed.            "
	@${ECHO} "	Change the settings in ${PREFIX}/etc/sndcs/sndcs2.conf    "
	@${ECHO} "	to suit your needs.                              "
	@${ECHO} "	- - - - - - - - - - - - - - - - - - - - - - - - -"

.include <bsd.port.mk>
