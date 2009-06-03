# New ports collection makefile for:    gorm
# Date created:         15 Mar 2002
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gorm
PORTVERSION=	1.2.10
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	dev-apps

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graphical Object Relationship Modeller

NO_PACKAGE=	GPL3
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

DEFAULT_LIBVERSION=	1.1.0
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

FIXME=	GormCore/GormCustomView.m \
	GormCore/GormDocument.m \
	GormCore/GormFilePrefsManager.m \
	GormCore/GormHelpInspector.m \
	GormCore/GormPrivate.m \
	Palettes/1Windows/WindowsPalette.m \
	Plugins/Nib/GormNibWrapperBuilder.m

FIXME2=	Palettes/1Windows/GormNSPanel.m \
	Palettes/1Windows/GormWindowSizeInspector.m \
	Plugins/Gorm/GormGormWrapperBuilder.m \
	Plugins/Nib/GormNibWrapperLoader.h \

post-patch:
.for i in ${FIXME}
	${REINPLACE_CMD} -e 's|GSNibTemplates|GSNibLoading|' \
		-e 's|GSNibCompatibility|GSNibLoading|' \
		${WRKSRC}/${i}
.endfor
.for i in ${FIXME2}
	${REINPLACE_CMD} -e 's|GSNibTemplates|GSGormLoading|' \
		-e 's|GSNibCompatibility|GSGormLoading|' \
		${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
