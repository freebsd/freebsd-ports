# New ports collection makefile for:	kxmleditor
# Date created:		15 July 2001
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kxmleditor
PORTVERSION=	1.0.0
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	XML editor for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

UIFILES=kxesearchdialogbase kxeprocinstrdialogbase kxespecprocinstrdialogbase \
	kxeelementdialogbase kxeattributedialogbase kxechardatadialogbase \
	kxeattachdialogbase kxechoosestringdialogbase kxetreeviewsettingspage \
	kxenewfilesettingspage kxeprintsettingspage kxearchiveextssettingspage \
	kxetextviewsettingspage kxetexteditordialogbase

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.for i in ${UIFILES}
	@${RM} ${WRKSRC}/part/$i.h ${WRKSRC}/part/$i.cpp
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
