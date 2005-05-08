# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	solfege
PORTVERSION=	2.4.0
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

MAN1=		lessonfile_editor.1 solfege.1

post-patch:
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/bin/python|${SETENV} python|g'
.for file in lessonfile_editor.py.in run-solfege.py.in
	@${REINPLACE_CMD} -e 's|share", "solfege|share", "gnome", "solfege|g' \
		${WRKSRC}/${file}
.endfor
.for file in src/inputwidgets.py src/runtime.py
	@${REINPLACE_CMD} -e 's|gnome.canvas|gnomecanvas|g' \
		${WRKSRC}/${file}
.endfor
.for file in default.config
	@${REINPLACE_CMD} -e 's|type=sequencer-device|type=fake-synth|g ; \
		 s|/usr/bin|${LOCALBASE}/bin|g' ${WRKSRC}/${file}
.endfor
.for file in po/Makefile
	@${REINPLACE_CMD} -e 's|(datadir)/locale|(prefix)/share/locale|g' \
		${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
