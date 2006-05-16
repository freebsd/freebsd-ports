# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	solfege
PORTVERSION=	3.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-nosound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free eartraining software

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		swig:${PORTSDIR}/devel/swig13 \
		${STYLESHEET}:${PORTSDIR}/textproc/docbook-xsl
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix pygnomeextras
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--disable-oss-sound \
		--enable-docbook-stylesheet=${STYLESHEET}

MAN1=		lessonfile_editor.1 solfege.1

STYLESHEET=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl

post-patch:
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/bin/python|${SETENV} python|g'
.for file in lessonfile_editor.py.in run-solfege.py.in
	@${REINPLACE_CMD} -e 's|share", "solfege|share", "gnome", "solfege|g' \
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
