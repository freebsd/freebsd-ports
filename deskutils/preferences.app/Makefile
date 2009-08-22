# New ports collection makefile for:   preferences
# Date created:         04 Feb 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	preferences
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	deskutils gnustep
MASTER_SITES=	SF/prefsapp/prefsapp/${PORTVERSION}
DISTNAME=	Preferences-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep workspace manager

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

DEAFULT_LIBVERSION=	1.1.1
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
MODIFY=		GNUmakefile.preamble PrefsModule/GNUmakefile.preamble \
		Modules/Keyboard/GNUmakefile.preamble \
		Modules/PrefsApp/GNUmakefile.preamble

post-patch:
.for i in ${MODIFY}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s= -Werror==" ${WRKSRC}/${i}.sed > ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
