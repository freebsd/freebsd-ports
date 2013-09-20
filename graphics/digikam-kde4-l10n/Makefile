# $FreeBSD$

PORTNAME=	digikam-l10n
PORTVERSION=	${DIGIKAM_VER}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	l10n for digiKam, showFoto, and Kipi-plugins

LATEST_LINK=	digikam-kde4-l10n
CONFLICTS_INSTALL=	digikam-2.* kipi-plugins-2.* libkgeomap-2.*

USES=		gettext:build
WRKSRC=		${WRKDIR}/${DISTNAME}/po

NO_STAGE=	yes
pre-configure:
# avoid conflicts with kde4-l10n ports:
	${RM} ${WRKSRC}/*/libkipi.po

.include "${.CURDIR}/../digikam-kde4/Makefile.common"
.include <bsd.port.mk>
