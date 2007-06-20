# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	solfege
PORTVERSION=	3.8.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-nosound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free eartraining software

BUILD_DEPENDS=	${STYLESHEET}:${PORTSDIR}/textproc/docbook-xsl

USE_GNOME=	gnomehack gnomeprefix libxslt pygtk2
WANT_GNOME=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_XML2PO=""
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man \
		--disable-oss-sound \
		--enable-docbook-stylesheet=${STYLESHEET}
MAKE_ARGS=	skipmanual=yes

MAN1=		lessonfile_editor.1 solfege.1

STYLESHEET=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygnomeextras}!=""
USE_GNOME+=	pygnomeextras
.endif

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.else
.if !defined(DISPLAY) || ${DISPLAY} == ""
IGNORE=		requires an active X session (and DISPLAY variable).  Please compile this while running X
.endif
.endif

post-patch:
	@${RM} ${WRKSRC}/lesson-files/bin/csound-play-harmonic-interval.sh.orig
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/bin/python|${SETENV} python|g'
.for file in lessonfile_editor.py.in run-solfege.py.in
	@${REINPLACE_CMD} -e 's|share", "solfege|share", "gnome", "solfege|g' \
		${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|type=sequencer-device|type=fake-synth|g ; \
		 s|/usr/bin|${LOCALBASE}/bin|g' ${WRKSRC}/default.config
	@${REINPLACE_CMD} -e 's|(datadir)/locale|(prefix)/share/locale|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.post.mk>
