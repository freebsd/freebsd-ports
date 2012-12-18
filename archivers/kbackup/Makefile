# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kbackup
PORTVERSION=	0.5.4
PORTREVISION=	6
CATEGORIES=	archivers kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTNAME=	44998-${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Program for backing up files and directories

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=3
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
