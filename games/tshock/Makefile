PORTNAME=		tshock
DISTVERSIONPREFIX=	v
DISTVERSION=		6.1.0
CATEGORIES=		games

MAINTAINER=		juanpapolo123@gmail.com
COMMENT=		Plugin-based Terraria dedicated server framework
WWW=			https://github.com/Pryaxis/TShock

LICENSE=		GPLv3
LICENSE_FILE=		${WRKSRC}/COPYING

USES=			gettext

BUILD_DEPENDS=		dotnet>=9.0:lang/dotnet \
			msgfmt:devel/gettext-tools \
			libsqlite3.so:databases/sqlite3
RUN_DEPENDS=		dotnet:lang/dotnet-host

USE_GITHUB=		yes
GH_ACCOUNT=		Pryaxis
GH_PROJECT=		TShock
GH_TUPLE=		NyxStudios:TerrariaAPI-Server:9861e568:terrariaapi

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		RUN
OPTIONS_SINGLE_RUN=	DAEMON STANDALONE
OPTIONS_DEFAULT=	STANDALONE
OPTIONS_SUB=		yes

DAEMON_DESC=		Run as an rc.d background service
STANDALONE_DESC=	Run manually from the terminal
STANDALONE_VARS=	SUB_FILES+=tshock.sh
DAEMON_VARS=		USE_RC_SUBR=tshock

USERS=			tshock
GROUPS=			tshock

DOTNET_ARCH=		${ARCH:S/amd64/x64/:S/aarch64/arm64/}
DOTNET_CMD=		${SETENV} HOME=${WRKDIR} ${LOCALBASE}/bin/dotnet

.include "Makefile.nuget"
.include "../../shells/powershell/nuget.mk"

post-extract:
	${RM} -r ${WRKSRC}/TerrariaServerAPI
	${MV} ${WRKDIR}/TSAPI-9861e568 ${WRKSRC}/TerrariaServerAPI

do-build:
	cd ${WRKSRC} && \
	${DOTNET_CMD} nuget add source ${DISTDIR}/nuget && \
	${DOTNET_CMD} nuget disable source nuget.org && \
	${DOTNET_CMD} restore TShockLauncher \
	-s ${DISTDIR}/nuget --packages ${WRKDIR}/packages && \
	${DOTNET_CMD} publish TShockLauncher \
	-r freebsd.${_OSVERSION_MAJOR}-${DOTNET_ARCH} \
	-f net9.0 -c Release --no-self-contained \
	-o ${WRKDIR}/bin/publish

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} \
	${STAGEDIR}${ETCDIR} \
	${STAGEDIR}/var/db/tshock \
	${STAGEDIR}/var/log/tshock
	cd ${WRKDIR}/bin/publish && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "! -name TShock.Server"
	${INSTALL_PROGRAM} ${WRKDIR}/bin/publish/TShock.Server \
	${STAGEDIR}${DATADIR}
	${LN} -sf ${LOCALBASE}/lib/libsqlite3.so \
	${STAGEDIR}${DATADIR}/bin/e_sqlite3.so

post-install-STANDALONE-on:
	${INSTALL_SCRIPT} ${WRKDIR}/tshock.sh ${STAGEDIR}${PREFIX}/bin/tshock

.include <bsd.port.mk>
