# Created by: Daniel O'Connor <darius@dons.net.au.
# $FreeBSD$

PORTNAME=       PocketMine
PORTVERSION=    1.5dev
CATEGORIES=     games

MAINTAINER=     darius@dons.net.au
COMMENT=        Minecraft PE server

LICENSE=        GPLv3
LICENSE_FILE=   ${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/include/php/ext/pthreads/config.h:${PORTSDIR}/devel/pecl-pthreads \
		${LOCALBASE}/include/php/ext/yaml/config.h:${PORTSDIR}/textproc/pecl-yaml \
		${LOCALBASE}/include/php/ext/weakref/config.h:${PORTSDIR}/devel/pecl-weakref \
		tmux:${PORTSDIR}/sysutils/tmux

USE_RC_SUBR=	pocketmine

USE_GITHUB=     yes
GH_ACCOUNT=     PocketMine \
		PocketMine:gui \
		PocketMine:lang \
		PocketMine:raklib \
		PocketMine:spl
GH_PROJECT=     PocketMine-MP \
		PocketMine-MP-GUI:gui \
		PocketMine-Language:lang \
		RakLib:raklib \
		PocketMine-SPL:spl
GH_TAGNAME=     0380e9009ac97ce79dcee3a832b4540016032bf5 \
		b551c3d58ec2fd9fa0f3c92d36fcbaa5c70467f7:gui \
		5a8cc27b7ee6f8f1d16a4fe45e57676ee9b57c5a:lang \
		ab3ff4420f6dea3371bfc410bbb783159cd0560b:raklib \
		d59c0f673455f02b2620853f3fa6290d63ffd960:spl

USE_PHP=        bcmath curl json phar sockets sqlite3 zlib

USERS=		pocketmine
GROUPS=		${USERS}

NO_BUILD=	yes

SUB_FILES=	pkg-message pocketmine
SUB_LIST=	USERS=${USERS}

post-extract:
	# Move submodule trees into the correct place
	@${RMDIR} ${WRKSRC}/src/pocketmine/gui
	@${MV} ${WRKDIR}/PocketMine-MP-GUI-b551c3d58ec2fd9fa0f3c92d36fcbaa5c70467f7 ${WRKSRC}/src/pocketmine/gui
	@${RMDIR} ${WRKSRC}/src/pocketmine/lang/locale
	@${MV} ${WRKDIR}/PocketMine-Language-5a8cc27b7ee6f8f1d16a4fe45e57676ee9b57c5a ${WRKSRC}/src/pocketmine/lang/locale
	@${RMDIR} ${WRKSRC}/src/raklib
	@${MV} ${WRKDIR}/RakLib-ab3ff4420f6dea3371bfc410bbb783159cd0560b ${WRKSRC}/src/raklib
	@${RMDIR} ${WRKSRC}/src/spl
	@${MV} ${WRKDIR}/PocketMine-SPL-d59c0f673455f02b2620853f3fa6290d63ffd960 ${WRKSRC}/src/spl

do-install:
	@${MKDIR} ${WRKDIR}/share
	@${LN} -s ${WRKSRC} ${WRKDIR}/share/PocketMine-MP
	@${GREP} -v \^\@ ${PLIST} | ${TAR} -cf - -T - -C ${WRKDIR} | ${TAR} -xf - -C ${STAGEDIR}/${LOCALBASE}/
	# Make sure plugin directory exists or it will fail to create it on startup
	@${MKDIR} ${STAGEDIR}/${LOCALBASE}/share/PocketMine-MP/plugins

.include <bsd.port.mk>
