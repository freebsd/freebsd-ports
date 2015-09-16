# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	musicpm
PORTVERSION=	1.4.4
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	mpm_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music Player Minion

XPI_ID=		Music_Player_Minion@code.google.com
XPI_FILES=	chrome/minion.jar chrome.manifest install.js install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
