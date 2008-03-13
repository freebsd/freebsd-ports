# New ports collection makefile for:   tuxguitar
# Date created:        26 April 2007
# Whom:                Pietro Cerutti (gahr@gahr.ch)
#
# $FreeBSD$
#

PORTNAME=	tuxguitar
DISTVERSION=	1.0-rc2
CATEGORIES=	audio java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Multitrack tablature editor and player

BUILD_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt \
		${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext \
		ant:${PORTSDIR}/devel/apache-ant
RUN_DEPENDS=	${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt \
		${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext

MAKE_ENV=	"JAVALIBDIR=${JAVALIBDIR}" "PREFIX=${PREFIX}"

USE_JAVA=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
JAVA_VERSION=	1.4+

.if !defined(WITHOUT_MAN)
MAN1=		tuxguitar.1
.endif

USE_GECKO=	mozilla firefox seamonkey

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

PLUGINS=	TuxGuitar TuxGuitar-compat TuxGuitar-ascii TuxGuitar-gtp \
		TuxGuitar-musicxml TuxGuitar-ptb TuxGuitar-tef TuxGuitar-pdf \
		TuxGuitar-midi TuxGuitar-tray TuxGuitar-lilypond TuxGuitar-jsa \
		TuxGuitar-oss

SUB_FILES=	tuxguitar
SUB_LIST=	DATADIR=${DATADIR} \
		PREFIX=${PREFIX} \
		JAVALIBDIR=${JAVALIBDIR} \
		GECKO=${GECKO}

post-patch:
	${REINPLACE_CMD} -e 's|executable="make"|executable="${GMAKE}"|g' \
	    ${WRKSRC}/TuxGuitar-oss/build.xml \
	    ${WRKSRC}/TuxGuitar-CoreAudio/build.xml

do-install:
	${MKDIR} ${DATADIR}
	# Main program and plugins
	${INSTALL_SCRIPT} ${WRKDIR}/tuxguitar ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar/tuxguitar.jar ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/misc/*.tg ${DATADIR}
	${MKDIR} ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/TuxGuitar-oss/libtuxguitar-oss-jni.so ${PREFIX}/lib
.for p in ${PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/${p}/*.jar ${DATADIR}/plugins
.endfor
	# Inline documentation
	cd ${WRKSRC}/TuxGuitar/share/help &&   ${COPYTREE_SHARE} \* ${DATADIR}/help
	cd ${WRKSRC}/TuxGuitar/share/lang &&   ${COPYTREE_SHARE} \* ${DATADIR}/lang
	cd ${WRKSRC}/TuxGuitar/share/scales && ${COPYTREE_SHARE} \* ${DATADIR}/scales
	cd ${WRKSRC}/TuxGuitar/share/skins &&  ${COPYTREE_SHARE} \* ${DATADIR}/skins

	# XPM icon
	${INSTALL_DATA} ${WRKSRC}/misc/tuxguitar.xpm ${PREFIX}/share/pixmaps

	# MAN page
.if !defined(WITHOUT_MAN)
	${INSTALL_MAN} ${WRKSRC}/misc/tuxguitar.1 ${MANPREFIX}/man/man1
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/TuxGuitar/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
