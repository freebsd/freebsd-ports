# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	solfege
PORTVERSION=	3.9.0
CATEGORIES=	audio
MASTER_SITES=	SF
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
CONFIGURE_ARGS=	--disable-oss-sound \
		--enable-docbook-stylesheet=${STYLESHEET}
MAKE_ARGS=	skipmanual=yes
USE_DISPLAY=	yes

MAN1=		lessonfile_editor.1 solfege.1

STYLESHEET=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygnomeextras}!=""
USE_GNOME+=	pygnomeextras
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
