# New ports collection makefile for:   preferences.app
# Date created:         04 Feb 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	preferences.app
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	prefsapp
DISTNAME=	Preferences-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep workspace manager

USE_BZIP2=	yes
PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

MODIFY=		GNUmakefile.preamble PrefsModule/GNUmakefile.preamble \
		Modules/Keyboard/GNUmakefile.preamble \
		Modules/PrefsApp/GNUmakefile.preamble

post-patch:
.for i in ${MODIFY}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s= -Werror==" ${WRKSRC}/${i}.sed > ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
