# New ports collection makefile for:	xmms-rateplug
# Date created:				15 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xmms-rateplug
DISTVERSION=	0.4.2-3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	xmmsassesment

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Add song rating control to the XMMS playlist

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

CXXFLAGS+=	-w -shared -fPIC `xmms-config --cflags` `gtk-config --cflags` \
		`gtk-config --libs`
PLUGIN=		rateplug

PLIST_FILES=	lib/xmms/General/rateplug.so

do-build:
	${CXX} ${CXXFLAGS} ${WRKSRC}/${PLUGIN}.c++ -o ${WRKSRC}/${PLUGIN}.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PLUGIN}.so ${PREFIX}/lib/xmms/General

post-install:
	@${CAT} ${PKGMESSAGE}

install-user:
	${SH} ${FILESDIR}/install-user

.include <bsd.port.mk>
