# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#   $MCom: ports/audio/solfege/Makefile,v 1.7 2007/09/09 23:47:50 mezz Exp $
#

PORTNAME=	solfege
PORTVERSION=	3.20.4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}
PKGNAMESUFFIX=	-nosound

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Free eartraining software

BUILD_DEPENDS=	${STYLESHEET}:${PORTSDIR}/textproc/docbook-xsl \
		txt2man:${PORTSDIR}/textproc/txt2man

USE_GNOME=	gnomehack pygtk2
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

MAN1=		solfege.1

STYLESHEET=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygnomeextras}!=""
USE_GNOME+=	pygnomeextras
.endif

post-patch:
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/bin/python|${SETENV} python|g'
	@${REINPLACE_CMD} -e 's|type=sequencer-device|type=fake-synth|g ; \
		 s|/usr/bin|${LOCALBASE}/bin|g' ${WRKSRC}/default.config
	@${REINPLACE_CMD} -e 's|(datadir)/locale|(prefix)/share/locale|g' \
		${WRKSRC}/po/Makefile
	@${REINPLACE_CMD} -i '' -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/exercises/standard/lesson-files/bin/csound-play-harmonic-interval.sh

.include <bsd.port.post.mk>
