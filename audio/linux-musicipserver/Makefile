# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTNAME=		musicipserver
PORTVERSION=		1.8
CATEGORIES=		audio linux
MASTER_SITES=		http://www.amplifindmusicservices.com/downloads/:musicip \
			http://spicefly.com/images/stories/mip/:spicefly
PKGNAMEPREFIX=		linux-
DISTNAME=		MusicMixer_x86_${PORTVERSION}
DISTFILES=		${DISTNAME}.tgz:musicip
DIST_SUBDIR=		musicip
EXTRACT_ONLY=		${DISTNAME}.tgz

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Application for generating playlists based upon musical content

LICENSE=		EULA
LICENSE_NAME=		END-USER LICENSE AGREEMENT FOR MUSICIP MIXER
LICENSE_FILE=		${WRKSRC}/notes.txt
LICENSE_PERMS=		dist-mirror pkg-mirror auto-accept

RUN_DEPENDS=		empty:${PORTSDIR}/net/empty \
			flog:${PORTSDIR}/sysutils/flog \
			${LOCALBASE}/libexec/mipcore:${PORTSDIR}/audio/linux-genpuid

LICENSE_DISTFILES=	${DISTNAME}.tgz

OPTIONS_DEFINE=		SPICEFLY_SKIN
OPTIONS_DEFAULT=		SPICEFLY_SKIN
OPTIONS_DESC=		Install Spicefly skin

WRKSRC=			${WRKDIR}/MusicIP/MusicMagicMixer/

USE_RC_SUBR=		musicipserver
NO_STAGE=	yes
USE_LINUX=		yes
NO_BUILD=		yes
IA32_BINARY_PORT=	yes

MUSICIPSERVERDBDIR?=	/var/db/${PORTNAME}
MUSICIPSERVERLOGDIR?=	/var/log/${PORTNAME}
MUSICIPSERVERRUNDIR?=	/var/run/${PORTNAME}

MUSICIPSERVERUSER?=	mipserv
MUSICIPSERVERGROUP?=	${MUSICIPSERVERUSER}

SUB_FILES=		pkg-install pkg-deinstall
SUB_LIST=		PORTNAME=${PORTNAME} \
			MUSICIPSERVERDBDIR=${MUSICIPSERVERDBDIR} \
			MUSICIPSERVERLOGDIR=${MUSICIPSERVERLOGDIR} \
			MUSICIPSERVERRUNDIR=${MUSICIPSERVERRUNDIR} \
			MUSICIPSERVERUSER=${MUSICIPSERVERUSER} \
			MUSICIPSERVERGROUP=${MUSICIPSERVERGROUP}
PLIST_SUB=		MUSICIPSERVERDBDIR=${MUSICIPSERVERDBDIR} \
			MUSICIPSERVERLOGDIR=${MUSICIPSERVERLOGDIR} \
			MUSICIPSERVERRUNDIR=${MUSICIPSERVERRUNDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPICEFLY_SKIN}
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
DISTFILES+=		index-1.1.zip:spicefly
.endif

.if ${PORT_OPTIONS:MSPICEFLY_SKIN}
post-extract:
	@cd ${WRKDIR} && ${UNZIP_CMD} -qo ${_DISTDIR}/index-1.1.zip -d ${WRKDIR}/spicefly
.endif

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/MusicMagicServer ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${LN} -fhs ${LOCALBASE}/libexec/mipcore ${DATADIR}/mipcore
.if ${PORT_OPTIONS:MSPICEFLY_SKIN}
	@${MKDIR} ${DATADIR}/server
	@${INSTALL_DATA} ${WRKDIR}/spicefly/index.html ${DATADIR}/server
.else
	@cd ${WRKSRC} && ${COPYTREE_SHARE} server ${DATADIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/mmm.ini ${EXAMPLESDIR}/mmm.ini.sample
	@${INSTALL_DATA} ${FILESDIR}/recipes.xml.sample ${EXAMPLESDIR}/recipes.xml.sample

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
