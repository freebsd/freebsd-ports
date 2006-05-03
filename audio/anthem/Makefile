# New ports collection makefile for:    anthem
# Date created:                         Wed Nov 12 14:10:12 PST 2003
# Whom:                                 Mathew Kanner <mat@hak.cnd.mcgill.ca>
#
# $FreeBSD$

PORTNAME=	anthem
PORTVERSION=	0.0.17
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A KDE midi sequencer

LIB_DEPENDS=	tse3:${PORTSDIR}/audio/tse3

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_KDELIBS_VER=3
INSTALLS_SHLIB=	yes

CPPFLAGS+=	-DQT_NO_ASCII_CAST

post-configure:
	@${REINPLACE_CMD} -e 's|-Wall -g|${CFLAGS}|g' \
		${WRKSRC}/anthem/dialogues/Makefile \
		${WRKSRC}/anthem/gadgets/Makefile \
		${WRKSRC}/anthem/misc/Makefile \
		${WRKSRC}/anthem/phraseeditors/Makefile \
		${WRKSRC}/anthem/settings/Makefile \
		${WRKSRC}/anthem/songwindow/Makefile \
		${WRKSRC}/anthem/tse3/kdeui/Makefile \
		${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
