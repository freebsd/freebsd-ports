# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	solfege
PORTVERSION=	2.2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-nosound
DISTNAME=	${PORTNAME}-easybuild-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free eartraining software

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix pygnomeextras
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--disable-oss-sound
PLIST_SUB=	VERSION=${PORTVERSION}

MAN1=		lessonfile_editor.1 solfege.1

post-patch:
	@${GREP} -lR "/usr/bin/python2.2" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/bin/python2.2|${SETENV} python|g'
	@${REINPLACE_CMD} -e 's|type=sequencer-device|type=fake-synth| g; \
		 s|/usr/bin|${LOCALBASE}/bin|g' ${WRKSRC}/default.config
	@${REINPLACE_CMD} -e 's|share/solfege|share/gnome/solfege|g' \
		${WRKSRC}/run-solfege.py.in
	@${REINPLACE_CMD} -e 's|(datadir)/locale|(prefix)/share/locale|g' \
		${WRKSRC}/po/Makefile
	@${REINPLACE_CMD} -e 's|share", "solfege|share", "gnome", "solfege|g' \
		${WRKSRC}/src/configureoutput.py.in
	@${REINPLACE_CMD} -e 's|gnome.canvas|gnomecanvas|g' \
		${WRKSRC}/src/inputwidgets.py

.include <bsd.port.mk>
