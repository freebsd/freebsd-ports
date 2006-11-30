# New ports collection makefile for:	planeshift
# Date created:		2006-03-17
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	planeshift
PORTVERSION=	0.3.017
CATEGORIES=	games
MASTER_SITES=	http://alex.foxybanana.com/freebsd/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	First 3D MMORPG to be free for players

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam \
		cs-config:${PORTSDIR}/graphics/crystalspace-devel \
		cel-config:${PORTSDIR}/graphics/crystalentitylayer-devel \
		${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd
LIB_DEPENDS=	cal3d.12:${PORTSDIR}/graphics/cal3d \
		curl.3:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:259:env

CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_LIBS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CRYSTAL=	${LOCALBASE}
CEL=		${LOCALBASE}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-cpu-specific-optimizations=no
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" CRYSTAL="${CRYSTAL}" CEL="${CEL}"
SUB_FILES=	pkg-message planeshift pssetup updater psserver
PLANEDIR=	lib/${PORTNAME}
PLIST_SUB=	PLANEDIR=${PLANEDIR}
INSTALL_PSDATA=	${INSTALL} ${COPY} ${_SHROWNGRP} -m 0644

JAM_CMD=	jam
JAM_ARGS=	-qa

OPTIONS=	MYSQL	"MySQL support for server mode "	off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysqlclient
USE_MYSQL=	yes
LIB_DEPENDS+=	WN.2:${PORTSDIR}/textproc/wordnet
PLIST_SUB+=	MYSQL="" \
		EXAMPLE=""
MYSQL_FLAG=	true
.else
CONFIGURE_ARGS+=	--with-mysqlclient=no
PLIST_SUB+=	MYSQL="@comment " \
		EXAMPLE="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%AUTOHEADER%%|${AUTOHEADER}|g' -e 's|%%AUTOCONF%%|${AUTOCONF}|g' \
		${WRKSRC}/autogen.sh
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -name "*.c" -exec \
			${REINPLACE_CMD} -i "" -e 's|malloc.h|stdlib.h|g' "{}" \;
	@cd ${WRKSRC} && \
		${FIND} * -type f -name ".cvsignore" -print0 | \
			${XARGS} -0 ${RM} -R

pre-configure:
	@cd ${WRKSRC} && ${SH} autogen.sh

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${JAM_CMD} ${JAM_ARGS}

post-build:
	@${REINPLACE_CMD} -e 's|<mirror id="1" name="local" url="http://192.168.2.19/updater/" />| \
		<mirror id="1" name="mir1" url="http://psmirror.pfdev.net/psupdater/" \
			repository="repository.zip" files="" /> \n \
		<mirror id="2" name="mir2" url="http://planeshift.mirror.thumbnail.cz/psupdater/" \
			repository="repository.zip" files="" /> \n \
		<mirror id="3" name="mir3" url="http://www.psmirror.org/psupdater/" \
			repository="repository.zip" files="" /> \n \
		<mirror id="4" name="mir4" url="http://psmirror.u24.solone.net/psupdater/" \
			repository="repository.zip" files="" /> \n \
		<mirror id="5" name="backp" url="http://laanx.fragnetics.com/updater_hidden/" \
			repository="repository.zip" files="" />|g' ${WRKSRC}/updaterconfig.xml

	@${REINPLACE_CMD} -e 's|<module>docs</module>|<!-- <module>docs</module> -->|g' -e \
		's|<module>root</module>|<!-- <module>root</module> -->|g' ${WRKSRC}/updaterconfig.xml
do-install:
	@${MKDIR} ${PREFIX}/${PLANEDIR}
.for FILE in ase_2_spr eedit paws_generic pawseditor psclient psnpcclient psserver pssetup texparse updater
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/${PLANEDIR}
.endfor

.for FILE in *.cfg *.xml
	${INSTALL_PSDATA} ${WRKSRC}/${FILE} ${PREFIX}/${PLANEDIR}
.endfor

.for DIRE in art data
	@${MKDIR} ${PREFIX}/${PLANEDIR}/${DIRE}
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${PLANEDIR}/${DIRE}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_PSDATA} "{}" "${PREFIX}/${PLANEDIR}/${DIRE}/{}" \;
.endfor

.if defined(MYSQL_FLAG)
	${INSTALL_SCRIPT} ${WRKDIR}/psserver ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dbmysql.so ${PREFIX}/${PLANEDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/src/server/database/mysql && \
		${FIND} * -name "*.sql" -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
.endif

	@${INSTALL_SCRIPT} ${WRKDIR}/planeshift ${WRKDIR}/updater ${WRKDIR}/pssetup ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
